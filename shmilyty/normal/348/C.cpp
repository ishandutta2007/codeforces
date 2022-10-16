#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define elif else if
#define ALL(x) x.begin(),x.end()
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
//const int INF=4e18;
inline int read()
{
	int x=0;
	bool flag=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
const int N=1e5+1,M=sqrt(N);
vector<int> s[N];
int n,m,q,top,stk[M+5],com[N][M+5];
ll a[N],ans[N],tag[N];
bool big[N],vis[M+5][N];
signed main()
{
	n=read();
	m=read();
	q=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=m;i++)
	{
		int k=read();
		for(int l=1;l<=k;l++)
		{
			int x=read();
			s[i].push_back(x);
			ans[i]+=a[x];
		}
		if(k>=M)
		{
			stk[++top]=i;
			big[i]=1;
			for(int l:s[i])
				vis[top][l]=1;
		}
	}
	for(int i=1;i<=m;i++)
		for(int l=1;l<=top;l++)
			for(int j:s[i])
				if(vis[l][j])
					com[i][l]++;
	while(q--)
	{
		char opt;
		cin>>opt;
		int x=read();
		if(opt=='+')
		{
			int v=read();
			if(big[x])
				tag[x]+=1ll*v;
			else
				for(int i:s[x])
					a[i]+=1ll*v;
			for(int i=1;i<=top;i++)
				ans[stk[i]]+=1ll*v*com[x][i];
		}
		else
		{
			if(!big[x])
			{
				ans[x]=0;
				for(int i:s[x])
					ans[x]+=1ll*a[i];
				for(int i=1;i<=top;i++)
					ans[x]+=1ll*tag[stk[i]]*com[x][i]; 
			}
			cout<<ans[x]<<endl;
		}
	}
	return 0;
}