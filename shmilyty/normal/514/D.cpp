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
int n,m,k,maxx,p,tot;
array<int,5> t[200001],ans,cnt;
int q(int l,int r,int id)
{
	l--;
	int res=0;
	for(l+=n,r+=n;l<r;l>>=1,r>>=1)
	{
		if(l&1)	
			res=max(res,t[l++][id]);
		if(r&1)
			res=max(res,t[--r][id]);
	}
	return res;
}
signed main()
{
	n=read();
	m=read();
	k=read();
	for(int i=n;i<2*n;i++)
		for(int l=0;l<m;l++)
			t[i][l]=read();
	for(int l=0;l<m;l++)
		for(int i=n-1;i;i--)
			t[i][l]=max(t[i<<1][l],t[i<<1|1][l]);
	for(int i=1;i<=n;i++)
	{
		if(i+maxx-1>n)
			break;
		if(p==i-1)
			p=i;
		tot=0;
		for(int l=0;l<m;l++)
		{
			cnt[l]=q(i,p,l);
			tot+=cnt[l]; 
		}
		if(tot>k)
			continue;
		for(;p<=n+1;p++)
		{
			if(p==n+1)
			{
				if(maxx<p-i+1)
				{
					ans=cnt;
					maxx=p-i+1;
				}
				break;
			}
			tot=0;
			for(int j=0;j<m;j++)
				tot+=max(cnt[j],t[p+n-1][j]);
			if(tot>k)
			{
				if(maxx<p-i)
				{
					ans=cnt;
					maxx=p-i;
				}
				break;
			}
			for(int j=0;j<m;j++)
				cnt[j]=max(cnt[j],t[p+n-1][j]);
		}
	}
//	cout<<maxx<<endl;
	for(int i=0;i<m;i++)
		cout<<ans[i]<<" ";
	return 0;
}