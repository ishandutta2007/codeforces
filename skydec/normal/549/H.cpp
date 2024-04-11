#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
typedef double db;
double a,b,c,d;
bool ck(long double x){
	long double a1,a2,b1,b2,c1,c2,d1,d2;
	a1=a+x;a2=a-x;b1=b+x;b2=b-x;
	c1=c+x;c2=c-x;d1=d+x;d2=d-x;
	long double l1,l2,r1,r2;
	l1=min(min(a1*d1,a1*d2),min(a2*d1,a2*d2));
	r1=max(max(a1*d1,a1*d2),max(a2*d1,a2*d2));
	l2=min(min(b1*c1,b1*c2),min(b2*c1,b2*c2));
	r2=max(max(b1*c1,b1*c2),max(b2*c1,b2*c2));
	if(l1>r2)return 0;
	if(l2>r1)return 0;
	return 1;
}
int main(){
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	double l=0;double r=1e9;
	rep(i,1,300){
		double mid=(l+r)/2.;
		if(ck(mid))r=mid;else l=mid;
	}
	printf("%.10lf\n",l);
	return 0;
}