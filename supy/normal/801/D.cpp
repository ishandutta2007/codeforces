#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
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
#define N 1005
struct Point {int x,y;} p[N];
int n;
double ans=1e11;
inline void read(int &x) {
	x=0; int f=1; char c=getchar();
	while (c<'0'||c>'9'){if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9'){x=10*x+c-'0'; c=getchar();} x*=f;
}
int gcd(int a, int b) {if (!b) return a; return gcd(b,a%b);}
void getline(Point a, Point b, int &x, int &y, ll &z) {
	int tmpx=b.x-a.x,tmpy=b.y-a.y;
	int GCD=gcd(abs(tmpx),abs(tmpy));
	tmpx/=GCD; tmpy/=GCD;
	x=tmpy; y=-tmpx; z=-(ll)a.x*x-(ll)a.y*y;
}
int main()
{
//	freopen("1.in","r",stdin);
	read(n); rep(i,1,n) read(p[i].x),read(p[i].y);
	p[n+1]=p[1]; p[n+2]=p[2];
	rep(i,1,n) {
		int a,b; ll c;
		getline(p[i],p[i+2],a,b,c);
		double x=abs((ll)a*p[i+1].x+(ll)b*p[i+1].y+c);
		ans=min(ans,x/sqrt((ll)a*a+(ll)b*b)/2);
	//	printf("%d:%d %d %lld %.10lf\n",i,a,b,c,x/sqrt((ll)a*a+(ll)b*b)/2);
	}
	printf("%.10lf",ans);
	return 0;
}