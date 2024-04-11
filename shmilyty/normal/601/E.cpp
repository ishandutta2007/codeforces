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
const int bse=1e7+19,mod=1e9+7;
int n,k,q,rt,cnt,tot=1,v[35001],w[35001],L[35001],R[35001],LL[120001],RR[120001],ans[35001],dp[1001];
vector<int> t[120001];
void modify(int &x,int l,int r,int ll,int rr,int val)
{
	if(!x)
		x=++cnt;
	if(ll<=l&&r<=rr)
	{
		t[x].push_back(val);
		return ;
	}
	int mid=(l+r)>>1;
	if(mid>=ll)
		modify(LL[x],l,mid,ll,rr,val);
	if(mid<rr)
		modify(RR[x],mid+1,r,ll,rr,val);
}
void solve(int x,int l,int r,int f[])
{
	for(int i:t[x])
		for(int j=k;j>=w[i];j--)
			f[j]=max(f[j],f[j-w[i]]+v[i]);
	if(l==r)
	{
		int res=0,p=1;
		for(int i=1;i<=k;i++)
		{
			(res+=f[i]*p)%=mod;
			(p*=bse)%=mod;
		}
		ans[l]=res;
		return ;
	}
	int mid=(l+r)>>1;
	int g[1001];
	for(int i=0;i<=k;i++)
		g[i]=f[i];
	solve(LL[x],l,mid,f);
	solve(RR[x],mid+1,r,g);
}
signed main()
{
	n=read();
	k=read();
	for(int i=1;i<=n;i++)
	{
		v[i]=read();
		w[i]=read();
		L[i]=1;
		R[i]=-1;
	}
	q=read();
	while(q--)
	{
		int opt=read();
		if(opt==1)
		{
			v[++n]=read();
			w[n]=read();
			L[n]=tot;
			R[n]=-1;
		}
		elif(opt==2)
			R[read()]=tot-1;
		else
			tot++;
	}
	for(int i=1;i<=n;i++)
	{
		if(R[i]<0)
			R[i]=tot-1;
		if(L[i]>R[i])
			continue;
		modify(rt,1,tot-1,L[i],R[i],i);
	}
	solve(rt,1,tot-1,dp);
	for(int i=1;i<tot;i++)
		cout<<ans[i]<<'\n';
	return 0;
}