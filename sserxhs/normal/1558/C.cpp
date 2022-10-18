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
int a[N],b[N],ans[N];
int T,n,m,c,i,j,k,x,y,z,tp,la,ksiz,ks;
int main()
{//return 0;
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	T=1e6;n=13;
	cin>>T;
	while (T--)
	{
		cin>>n;
		tp=0;
		//for (i=1;i<=n;i++) a[i]=i;
		//for (i=n;i;i--) swap(a[i],a[rnd()%i+1]);
		//for (i=1;i<=n;i++) b[i]=a[i];
		for (i=1;i<=n;i++) cin>>a[i];
		for (i=1;i<=n;i++) if ((a[i]^i)&1) break;
		if (i<=n) {cout<<-1<<"\n";
	continue;}
		for (i=n;i>1;i-=2)
		{
			for (j=1;j<=i;j++) if (a[j]==i) {x=j;break;}
			for (j=1;j<=i;j++) if (a[j]==i-1) {y=j;break;}
			if (abs(x-y)!=1)
			{
				if (x>y)
				{
					ans[++tp]=x;
					reverse(a+1,a+x+1);
					y=x-y+1;
					ans[++tp]=y-1;
					reverse(a+1,a+y);
					x=y-1;
				}
				else
				{
					ans[++tp]=x;
					reverse(a+1,a+x+1);
					ans[++tp]=y-1;
					reverse(a+1,a+y);
					x=y-1;
					//cout<<"spe"<<x<<" "<<y<<"\n";
				}
			}
			if (x>y)
			{
				ans[++tp]=x;
				reverse(a+1,a+x+1);
				ans[++tp]=i;
				reverse(a+1,a+i+1);
			}
			else
			{
				ans[++tp]=y+1;
				reverse(a+1,a+y+1+1);
				//n>=5
				ans[++tp]=3;
				reverse(a+1,a+4);
				ans[++tp]=i;
				reverse(a+1,a+i+1);
			}
		}
		if (tp==-1) {cout<<-1<<"\n";
		continue;
	} else
		{
			cout<<tp<<"\n";
			for (i=1;i<=tp;i++) cout<<ans[i]<<" \n"[i==tp],assert(ans[i]&1);
		}
		assert(tp<=5*n/2);
		//for (i=1;i<=n;i++) if (a[i]!=i)
		//{
		//	for (i=1;i<=n;i++) cout<<b[i]<<" \n"[i==n];return 0;
		//}
		for (i=1;i<=n;i++) assert(a[i]==i);
		//cout<<"check";
		//for (i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];
	}
}