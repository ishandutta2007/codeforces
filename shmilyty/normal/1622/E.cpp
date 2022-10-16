#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
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
int t,n,m,ans,a[10],ok[10][10001],p[10001],q[10001];
array<int,2> v[10001];
void solve()
{
	n=read();
	m=read();
	for(int i=0;i<n;i++)
		a[i]=read();
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		for(int l=0;l<m;l++)
			ok[i][l+1]=s[l]-'0';
	}
	ans=0;
	for(int i=0;i<(1<<n);i++)//1 
	{
		int res=0;
		for(int l=1;l<=m;l++)
			v[l]={0,l};
		for(int l=0;l<n;l++)
		{
			int k=1;
			if((i>>l)&1)
				k=-1;
			res-=k*a[l];
			for(int j=1;j<=m;j++)
				v[j][0]+=ok[l][j]*k;
		}
		sort(v+1,v+1+m);
		for(int l=1;l<=m;l++)
			res+=l*v[l][0];
//		/*
		bool flag=1;
		for(int l=0;l<n;l++)
		{
			int k=1,tot=0;
			if((i>>l)&1)
				k=-1;
			for(int j=1;j<=m;j++)
				tot+=ok[l][j]*q[j];
			if(tot*k<0)
			{
				flag=0;
				break;
			}
		}
		if(!flag)
			continue;
//		*/
		if(res>=ans)
		{
			ans=res;
			for(int l=1;l<=m;l++)
				p[v[l][1]]=l;
		}
	}
//	cout<<ans<<endl;
	for(int i=1;i<=m;i++)
		cout<<p[i]<<" ";
	cout<<'\n'; 
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}