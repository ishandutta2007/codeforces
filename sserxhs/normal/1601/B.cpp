#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
#define all(x) (x).begin(),(x).end()
std::mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int sj(int n)
{
	ull x=rnd();
	x=x<<32|rnd();
	return x%n+1;
}
#define rand fst
const int p=998244353;
inline void inc(int &x,const int y){if((x+=y)>=p)x-=p;}
inline void dec(int &x,const int y){if((x-=y)<0)x+=p;}
inline int ksm(int x,int y)
{int r=1;while (y){if(y&1)r=(ll)r*x%p;x=(ll)x*x%p;y>>=1;}return r;}
priority_queue<int> ONLYYFORRCOPYY;
priority_queue<int,vector<int>,greater<int>> ONLYYFORRCOPYY__;
struct Q
{
	int u,v;
	Q(){}
	Q(int a,int b):u(a),v(b){}
	bool operator<(const Q &o) const {return v<o.v;}
};
const int M=1.2e6+2000,N=3e5+1000,inf=1e9;
int a[N],b[N],ys[N];
int l[M],r[M],s[M],lz[M],dis[N],plz[M],pre[N];
int n,m,z,y,dt,dp;
void build(int x)
{
	lz[x]=inf;
	if (l[x]==r[x]) return s[x]=(l[x]==n?0:inf),ys[l[x]]=x,void();
	int c=x<<1;
	l[c]=l[x];r[c]=l[x]+r[x]>>1;
	l[c|1]=r[c]+1;r[c|1]=r[x];
	build(c);build(c|1);
	s[x]=min(s[c],s[c|1]);
}
int find()
{
	int x=1;
	while (l[x]<r[x])
	{
		int c=x<<1;
		if (lz[x]!=inf)
		{
			if (s[c]!=inf*2)
			{
				if (lz[c]>lz[x])
				{
					lz[c]=lz[x];
					plz[c]=plz[x];
				}
				s[c]=min(s[c],lz[x]);
			}
			c^=1;
			if (s[c]!=inf*2)
			{
				if (lz[c]>lz[x])
				{
					lz[c]=lz[x];
					plz[c]=plz[x];
				}
				s[c]=min(s[c],lz[x]);
			}
			c^=1;
			lz[x]=inf;
		}
		if (s[c]<s[c|1]) x=c; else x=c|1;
	}
	return x;
}
void mdf(int x)
{
	if (z<=l[x]&&r[x]<=y)
	{
		if (s[x]!=inf*2)
		{
			if (lz[x]>dt)
			{
				lz[x]=dt;
				plz[x]=dp;
			}
			s[x]=min(s[x],dt);
		}
		return;
	}
	int c=x<<1;
	if (lz[x]!=inf)
	{
		if (s[c]!=inf*2)
		{
			if (lz[c]>lz[x])
			{
				lz[c]=lz[x];
				plz[c]=plz[x];
			}
			s[c]=min(s[c],lz[x]);
		}
		c^=1;
		if (s[c]!=inf*2)
		{
			if (lz[c]>lz[x])
			{
				lz[c]=lz[x];
				plz[c]=plz[x];
			}
			s[c]=min(s[c],lz[x]);
		}
		c^=1;
		lz[x]=inf;
	}
	if (z<=r[c]) mdf(c);
	if (y>r[c]) mdf(c|1);
	s[x]=min(s[c],s[c|1]);
}
void modify(int y)
{
	int x=ys[y];
	s[x]=2e9;
	while (x>>=1) s[x]=min(s[x<<1],s[x<<1|1]);
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int ans=inf,i;
	cin>>n;
	for (i=1;i<=n;i++) cin>>a[i];
	for (i=1;i<=n;i++) cin>>b[i];
	r[l[1]=1]=n;build(1);
	while (1)
	{
		if (s[1]>=inf)
		{
			cout<<-1<<endl;
			return 0;
		}
		int x=find();
		int v=s[x],pp=plz[x];
		x=l[x];pre[x]=pp;
		modify(x);
		dp=x;
		x+=b[x];
		if (x<=a[x])
		{
			cout<<v+1<<'\n';
			x=dp;
			static int st[N];
			int tp=0;
			while (x!=n)
			{
				st[++tp]=x;
				x=pre[x];
			}
			for (i=tp;i;i--) cout<<st[i]<<' ';
			cout<<0<<endl;
			return 0;
		}
		z=max(1,x-a[x]);y=x;dt=v+1;
		mdf(1);
	}
}