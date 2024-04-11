#include <bits/stdc++.h>
using namespace std;
typedef long long INT;
typedef pair<double, int> pii;
#define x first
#define y second
struct point {
   double x, y;
} a, b, t, r;
double f(point a, point b) {return hypot((a.x-b.x),(a.y-b.y));} 
double ans=1e100,res;
pii  pa[110000],pb[110000];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
   int n,i;
	scanf(" %lf %lf %lf %lf %lf %lf %d",&a.x,&a.y,&b.x,&b.y,&t.x,&t.y,&n);
	for(i=0;i<n;i++) {
		scanf("%lf %lf",&r.x,&r.y);
		res+=2*f(r,t);
		pa[i].x=f(r,a)-f(r,t);
		pa[i].y=i;
		pb[i].x=f(r,b)-f(r,t);
		pb[i].y=i;
	} 
	sort(pa,pa+n);
	sort(pb,pb+n);
	ans=min(ans,res+min(pa[0].x,pb[0].x));
	if(pa[0].y==pb[0].y){
		ans=min(ans,res+pa[0].x+pb[1].x);
		ans=min(ans,res+pa[1].x+pb[0].x); } 
	else ans=min(ans,res+pa[0].x+pb[0].x);
	printf("%.12lf\n",ans);
}