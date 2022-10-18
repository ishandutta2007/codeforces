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
typedef pair<int,int> pa;
priority_queue<int> ONLYYFORRCOPYY;
priority_queue<int,vector<int>,greater<int>> ONLYYFORRCOPYY__;
template<typename typC,int N> struct bit
{
	typC a[N],s[N];
	int n;
	bit()
	{
		memset(s,0,sizeof s);
		memset(a,0,sizeof a);
	}
	void init(int nn)
	{
		n=nn;
		memset(a+1,0,n*sizeof a[0]);
		memset(s+1,0,n*sizeof a[0]);
	}
	void init(int nn,typC *b)
	{
		n=nn;
		for (int i=1;i<=n;i++) s[i]=s[i-1]+b[i];
		memset(a+1,0,n*sizeof a[0]);
	}
	void mdf(int x,typC y)
	{
		a[x]+=y;
		while ((x+=x&-x)<=n) a[x]+=y; 
	}
	typC sum(int x)
	{
		typC r=a[x];
		while (x^=x&-x) r+=a[x];
		return r;
	}
	typC sum(int x,int y)
	{
		return sum(y)-sum(x-1);
	}
};
struct Q
{
	int min,sum,lzmin,lzsum;
	Q(){min=sum=lzmin=lzsum=0;}
	void operator*=(const Q &x)
	{
		min=std::min(min,sum+x.lzmin);
		sum+=x.lzsum;
		lzmin=std::min(lzmin,lzsum+x.lzmin);
		lzsum+=x.lzsum;
	}
	void operator*=(const int &x)
	{
		min=std::min(min,sum+=x);
		lzmin=std::min(lzmin,lzsum+=x);
	}
	pa operator+(const Q &x) const
	{
		return pa(std::min(min,x.min),std::min(sum,x.sum));
	}
	void operator=(const pa &x)
	{
		min=x.first;sum=x.second;
	}
	void operator=(const int &x)
	{
		min=sum=x;
	}
};
const int N=2e6+2,M=8e6+2;
Q s[M];
int l[M],r[M],ini[N],Ans[N];
int z,y,dt;
void build(int x)
{
	s[x]=Q();
	if (l[x]==r[x])
	{
		s[x]=ini[l[x]];
		return;
	}
	int c=x<<1;
	l[c]=l[x];r[c]=l[x]+r[x]>>1;
	l[c|1]=r[c]+1;r[c|1]=r[x];
	build(c);build(c|1);
	s[x]=s[c]+s[c|1];
}
void mdf(int x)
{
	//if (x==1) cout<<"["<<z<<","<<y<<"] "<<dt<<endl;
	if (z<=l[x]&&r[x]<=y)
	{
		s[x]*=dt;
		return;
	}
	int c=x<<1;
	if (s[x].lzsum||s[x].lzmin)
	{
		s[c]*=s[x];s[c|1]*=s[x];
		s[x].lzsum=s[x].lzmin=0;
	}
	if (z<=r[c]) mdf(c);
	if (y>r[c]) mdf(c|1);
	s[x]=s[c]+s[c|1];
}
void allpd(int x)
{
	if (l[x]==r[x])
	{
		Ans[l[x]]=s[x].min;
		return;
	}
	int c=x<<1;
	if (s[x].lzsum||s[x].lzmin)
	{
		s[c]*=s[x];s[c|1]*=s[x];
		s[x].lzsum=s[x].lzmin=0;
	}
	allpd(c);allpd(c|1);
}
bit<int,N> S;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);

	int T;
	cin>>T;
	while (T--)
	{
		ll ans=0;
		int n,m,q,i;
		cin>>n>>m;q=n+m;
		static int a[N],b[N],c[N],cnt[N];
		for (i=1;i<=n;i++) cin>>a[i],c[i]=a[i];
		for (i=1;i<=m;i++) cin>>b[i],c[i+n]=b[i];
		sort(c+1,c+q+1);q=unique(c+1,c+q+1)-c-1;
		memset(cnt+1,0,q*sizeof cnt[0]);
		for (i=1;i<=n;i++) a[i]=lower_bound(c+1,c+q+1,a[i])-c;
		for (i=1;i<=m;i++) b[i]=lower_bound(c+1,c+q+1,b[i])-c;
		S.init(q);
		for (i=n;i;i--)
		{
			ans+=S.sum(a[i]-1);
			S.mdf(a[i],1);
		}
		for (i=1;i<=n;i++) ++cnt[a[i]];
		for (i=1;i<=q;i++) cnt[i]+=cnt[i-1];
		for (i=1;i<=q;i++) ini[i]=cnt[i-1];
		r[l[1]=1]=q;build(1);
		for (i=1;i<=n;i++)
		{
			z=a[i]+1;y=q;dt=-1;if (z<=y) mdf(1);
			z=1;y=a[i]-1;dt=1;if (z<=y) mdf(1);
		}
		allpd(1);
		//for (i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];
		//for (i=1;i<=m;i++) cout<<b[i]<<" \n"[i==m];
		//for (i=1;i<=q;i++) cout<<ini[i]<<" \n"[i==q];
		//cout<<ans<<endl;
		//for (i=1;i<=q;i++) cout<<Ans[i]<<" \n"[i==q];
		for (i=1;i<=m;i++) ans+=Ans[b[i]];
		cout<<ans<<'\n';//cout<<endl;
	}
}