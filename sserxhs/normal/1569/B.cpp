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
const int N=52,M=1e6+2,inf=1e9;
char s[N],a[N][N];
int b[N];
int T,n,m,c,i,j,k,x,y,z,ans,la,ksiz,ks;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	T=1;
	cin>>T;
	while (T--)
	{
		cin>>n>>s+1;m=0;
		memset(a,0,sizeof a);
		for (i=1;i<=n;i++) a[i][i]='X';
		for (i=1;i<=n;i++) if (s[i]=='1')
		{
			for (j=1;j<=n;j++) if (i!=j) a[i][j]=a[j][i]='=';
		} else b[++m]=i;
		if (m==2||m==1) {cout<<"NO\n";continue;}
		cout<<"YES\n";b[m+1]=b[1];
		for (i=1;i<=m;i++) a[b[i]][b[i+1]]='+',a[b[i+1]][b[i]]='-';
		for (i=1;i<=n;i++) for (j=1;j<=n;j++) if (!a[i][j]) a[i][j]='=';
		for (i=1;i<=n;i++) cout<<a[i]+1<<'\n';
	}
}