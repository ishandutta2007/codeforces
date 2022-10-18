#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
#define range(x) (x).begin(),(x).end()
std::mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int sj(int n)
{
	unsigned int x=rnd();
	return x%n+1;
}
#define rand fst
const int p=998244353;
const db eps=1e-9;
inline void inc(register int &x,const int y)
{
	if ((x+=y)>=p) x-=p;
}
inline void dec(register int &x,const int y)
{
	if ((x-=y)<0) x+=p;
}
inline int ksm(register int x,register int y)
{
	register int r=1;
	while (y)
	{
		if (y&1) r=(ll)r*x%p;
		x=(ll)x*x%p;
		y>>=1;
	}
	return r;
}
priority_queue<int> ONLYYFORRCOPYY;
priority_queue<int,vector<int>,greater<int> > ONLYYFORRCOPYY__;
struct Q
{
	int u,v;
	Q(int a=0,int b=0):u(a),v(b){}
	bool operator<(const Q &o) const {return v<o.v;}
};
const int N=1e6+2,M=1e6+2,inf=1e9;
char s[N];
int a[N],b[N];
int T,n,m,c,i,j,k,x,y,z,ans,la,ksiz,ks,tp;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	T=1;
	cin>>T;
	while (T--)
	{
		cin>>n>>m;
		if (n>m) swap(n,m);
		tp=0;
		if (n==m)
		{
			cout<<n+1<<"\n";
			for (i=0;i<=2*n;i+=2) cout<<i<<" \n"[i==2*n];
			continue;
		}
		for (i=0;i<=n;i++) a[++tp]=(m-n+1)/2+i*2;
		for (i=0;i<=n;i++) a[++tp]=(m-n)/2+i*2;
		sort(a+1,a+tp+1);tp=unique(a+1,a+tp+1)-a-1;
		//m-n+[0,n]
		cout<<tp<<"\n";
		for (i=1;i<=tp;i++) cout<<a[i]<<" \n"[i==tp];
	}
}