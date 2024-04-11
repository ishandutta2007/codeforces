#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
//#define int long long
#define lc x<<1
#define rc lc|1 
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
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
const int N=100002;
int n,k,ans,tot,s[N],t[N<<2],len[N<<2],ok[N<<2];
vector<int> pL[N],pR[N];
void build(int x,int l,int r)
{
	t[x]=len[x]=r-l+1;
	if(l==r)
		return ;
	int mid=(l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r); 
}
void opt(int x)
{
	t[x]=len[x]-t[x];
	ok[x]^=1;
}
void ins(int x,int l,int r,int ll,int rr)
{
	if(ll>r||l>rr) 
		return;
	if(ll<=l&&r<=rr)
	{
		opt(x);
		return ;
	}
	if(ok[x])
	{
		opt(lc);
		opt(rc);
		ok[x]=0;	
	}
	int mid=(l+r)>>1;
	ins(lc,l,mid,ll,rr);
	ins(rc,mid+1,r,ll,rr);
	t[x]=t[lc]+t[rc];
}
signed main()
{
	n=read();
	k=read();
	for(int i=1;i<=n;i++)
		s[i]=read();
	sort(s+1,s+1+n); 
	while(k--)
	{
		int x=read(),y=read();
		int xx=lower_bound(s+1,s+1+n,x)-s;
		int yy=upper_bound(s+1,s+1+n,y)-s-1;
		pR[xx].push_back(yy);
		pL[yy+1].push_back(xx);
	}
	long long ans=1ll*n*(n-1ll)*(n-2ll)/6;
	build(1,1,n);
	for(int i=1;i<=n;i++)
	{ 
		ins(1,1,n,i,i);
		for(int l:pL[i])
		{
			ins(1,1,n,l,i-1);
			tot^=1;
		}
		for(int l:pR[i])
		{
			ins(1,1,n,i,l);
			tot^=1;
		}
		int q=t[1]-tot;
		ans-=1ll*q*(q-1)/2;
	}
	cout<<ans;
	return 0;
}