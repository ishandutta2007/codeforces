#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
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
int n,k,u,cnt,a[300001],p[300001],in[300001],bel[300001],ok[300001],ans[300001];
vector<int> G[300001];
queue<int> q;
signed main()
{
	n=read();
	k=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	while(k--)
	{
		int x=read(),y=read();
		p[x]=y;
		ok[y]=1;
	}
	for(int i=1;i<=n;i++)
		if(!ok[i])
		{
			for(int l=i;l;l=p[l])
			{
				bel[l]=i;
				if(a[l]&&bel[a[l]]!=i)
				{
					G[a[l]].push_back(i);
					in[i]++;
				}
			}
			if(!in[i])
				q.push(i);
		}
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(;x;x=p[x])
		{
			ans[++cnt]=x;
			for(int i:G[x])
				if(!(--in[i]))
					q.push(i);
		}
	}
	if(cnt!=n)
	{
		puts("0");
		return 0;
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	return 0;
}