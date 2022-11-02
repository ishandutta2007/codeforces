// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define N 514
#define L 100000
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
const double eps=1e-12;
int vt[L+1],vf[L+1],val[N];
double ev[N];
int get( int v[], double x ) {
	int l=(int)floor(x+eps);
	int r=(int)ceil(x-eps);
	if ( v[l]!=v[r] )return 0;
	return v[l];
}
bool vis[N];
int solve( int hl, int hr, int t ) {
	for ( int i=1; i<=t; i++ ) hr=i*100+(i*100-hr);
	if ( hl>=hr ) return 0;
	int ans=0,nv=-1;
	memset(vis,0,sizeof(vis));
	double x=0,y=hl,m=(hr-hl)/100000.0;
	for ( int i=1; i<=t; i++ ) {
		x+=(i*100-y)/m;
		y=i*100;
		//if ( t==4 ) printf("i=%d, x=%f, y=%f, pv=%d, nv=%d, ans=%d\n",i,x,y,pv,nv,ans);
		if ( i%2==1 ) nv=get(vt,x);
		else nv=get(vf,x);
		if ( nv==0 || vis[nv] ) return 0;
		vis[nv]=1;
		ans+=val[nv];
	}
	//if ( ans==120 ) printf("%d,%d,%d\n",hl,hr,t);
	return ans;
}
int solve( int hl, int hr ) {
	int ans=0;
	for ( int i=1; i<=200; i++ ) ans=max(ans,solve(hl,hr,i));
	return ans;
}
int main()
{
	int hl,hr,n;
	scanf("%d%d%d",&hl,&hr,&n);
	for ( int i=1; i<=n; i++ ) {
		int v,a,b;
		char c;
		scanf("%d %c %d %d",&v,&c,&a,&b);
		val[i]=v;
		if ( c=='T' ) for ( int j=a; j<=b; j++ ) vt[j]=i;
		else for ( int j=a; j<=b; j++ ) vf[j]=i;
	}
	int ans=solve(hl,hr);
	hl=100-hl;
	hr=100-hr;
	for ( int i=0; i<=L; i++ ) swap(vt[i],vf[i]);
	ans=max(ans,solve(hl,hr));
	printf("%d\n",ans);
	return 0;
}