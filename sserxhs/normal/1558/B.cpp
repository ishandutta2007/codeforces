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
int p;
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
const int N=4e6+2,M=1e6+2,inf=1e9;
int a[N],s[N],d[N];
int T,n,m,c,i,j,k,x,y,z,ans,la,ksiz,ks;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	cin>>n>>p;
	a[1]=s[1]=1;
	for (i=1;i<=n;i++)
	{
		inc(d[i],d[i-1]);inc(a[i],s[i-1]);inc(a[i],d[i]);
		for (j=2;i*j<=n;j++) inc(d[i*j],a[i]),dec(d[min((i+1)*j,n+1)],a[i]);
		s[i]=s[i-1];
		inc(s[i],a[i]);
	}
	// for (i=2;i<=n;i++)
	// {
	// 	a[i]=s[i-1];
	// 	for (j=2;j<=i;j=k+1)
	// 	{
	// 		k=i/(x=i/j);
	// 		a[i]=(a[i]+(ll)a[x]*(k-j+1))%p;
	// 	}
	// 	s[i]=s[i-1];
	// 	inc(s[i],a[i]);
	// }
	//for (i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];
	//for (i=1;i<=n;i++) cout<<d[i]<<" \n"[i==n];
	//for (i=1;i<=n;i++) cout<<s[i]<<" \n"[i==n];
	cout<<a[n]<<endl;
}