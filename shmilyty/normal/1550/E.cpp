#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
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
int n,k;
string s;
bool check(int d)
{
	vector<int> lst(n+1,n);
	vector<vector<int> >  pos(n+1,vector<int>(k+1,n+1));
	for(int i=n-1;i>=0;i--)
	{
		if(s[i]!='?')
			lst[s[i]-'a']=i;
		int cur=n;
		for(int l=0;l<k;l++)
		{
			pos[i][l]=(i+d<=cur?i+d:pos[i+1][l]);
			cur=min(cur,lst[l]);
		}
		cur=n;
		for(int l=k-1;l>=0;l--)
		{
			if(i+d>cur)
				pos[i][l]=pos[i+1][l];
			cur=min(cur,lst[l]);
		}
	}
	vector<int> f(1<<k,n+1);
	f[0]=0;
	for(int i=0;i<(1<<k);i++)
		if(f[i]<n+1)
			for(int l=0;l<k;l++)
				if(!((i>>l)&1))
					f[i|(1<<l)]=min(f[i|(1<<l)],pos[f[i]][l]);
	return f[(1<<k)-1]<=n;
 } 
signed main()
{
	n=read();
	k=read();
	cin>>s;
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
			l=mid+1;
		else
			r=mid-1;
	}
	cout<<l-1;
	return 0;
}