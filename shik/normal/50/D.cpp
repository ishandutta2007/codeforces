// by shik
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define N 110
using namespace std;
struct P{
	double x,y;
	P(){}
	P( double _x, double _y ):x(_x),y(_y){}
	void read() { scanf("%lf%lf",&x,&y); }	
	double len() { return sqrt(x*x+y*y); }
} p[N];
P operator -( P a, P b ) { return P(a.x-b.x,a.y-b.y); }
double dis( P a, P b ) { return (a-b).len(); }
double cal( double d, double r ) {
	if ( d<=r ) return 1;
	else return exp(1-(d*d)/(r*r)); 
}
int n,k,e;
double dp[N][N];
bool chk( double M ) {
	int i,j; double pro,sum=0;
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for ( i=1; i<=n; i++ ) {
		pro=cal(dis(p[i],p[0]),M);
		dp[i][0]=dp[i-1][0]*(1-pro);
		for ( j=1; j<=i; j++ ) {
			dp[i][j]=dp[i-1][j]*(1-pro)+dp[i-1][j-1]*pro;
		}
	}
	for ( i=0; i<k; i++ ) sum+=dp[n][i];
	return sum<=0.001*e;
}
int main()
{
	double L=0,M,R=1e10;
	scanf("%d%d%d",&n,&k,&e);
	for ( int i=0; i<=n; i++ ) p[i].read();
	while ( R-L>1e-9 ) {
		M=(L+R)/2;
		if ( chk(M) ) R=M;
		else L=M;	
	}
	printf("%.10f\n",(L+R)/2);
	return 0;
}