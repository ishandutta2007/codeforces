// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
pair<double,int> p[8*N];
double a[N],ans[N];
int main()
{
	int n,pn=0;
	double l,v1,v2;
	scanf("%d%lf%lf%lf",&n,&l,&v1,&v2);
	double t=l/(v1+v2);
	for ( int i=0; i<n; i++ ) scanf("%lf",a+i);
	for ( int i=0; i<n; i++ ) {
		double st=a[i],ed=a[i]+l-t*v1;
		if ( ed<2*l ) {
			p[pn++]=make_pair(st,+1);
			p[pn++]=make_pair(ed,-1);
		} else {
			p[pn++]=make_pair(st,+1);
			p[pn++]=make_pair(2*l,-1);
			p[pn++]=make_pair(0,+1);
			p[pn++]=make_pair(ed-2*l,-1);
		}
	}
	p[pn++]=make_pair(2*l,0);
	sort(p,p+pn);
	double pre=0;
	int now=0;
	for ( int i=0; i<pn; i++ ) {
		ans[now]+=p[i].first-pre;
		pre=p[i].first;
		now+=p[i].second;
	}
	for ( int i=0; i<=n; i++ ) printf("%.15f\n",ans[i]/(2*l));
	return 0;
}