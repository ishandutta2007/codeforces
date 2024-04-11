#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>
#include<cmath>
#define MAXN 20005
#define MAXM 200050
#define INF 0x7f7f7f7f
#define ll long long
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define clr(x) memset(x,0,sizeof(x));
using namespace std;
#define N 100005
int n,p;
int a[N],b[N];
const long double EPS=1e-8;
inline void read(int &x) {
	x=0; int f=1; char c=getchar();
	while (c<'0'||c>'9'){if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9'){x=10*x+c-'0'; c=getchar();} x*=f;
}
inline int ok(long double time) {
	long double Spare=time*p;
	rep(i,1,n) if (time*a[i]-b[i]>-EPS) {
		Spare-=(time*a[i]-b[i]);
		if (Spare<EPS) return 0;
	}
	return 1;
}
#include<iostream>
int main()
{
//	double tmp=107.32*107.32*107.32*107.32*107.32*492.61; printf("%.10lf\n",tmp);
//	long double tmp1=107.32*107.32*107.32*107.32*107.32*492.61; printf("%.10lf\n",(double)tmp1);
//	freopen("1.in","r",stdin);
	read(n); read(p);
	rep(i,1,n) read(a[i]),read(b[i]);
	ll tot=0; //Careful!
	rep(i,1,n) tot+=a[i];
	ll totb=0; rep(i,1,n) totb+=b[i];
	if (tot<=p) {puts("-1"); return 0;}
	long double l=0,r=(long double)totb/(tot-p);
	while ((r-l)>EPS) {
		long double mid=(l+r)/2;
		if (ok(mid)) l=mid;
		else r=mid;
	}
	long double ans=(l+r)/2;
	printf("%.10lf",(double)ans);
	return 0;
}