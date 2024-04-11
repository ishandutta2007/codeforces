// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
    double x1,y1,r1,x2,y2,r2;
    scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&r1,&x2,&y2,&r2);
    double d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    if ( d>r1+r2 ) printf("%.9f\n",(d-r1-r2)/2);
    else if ( d<abs(r1-r2) ) printf("%.9f\n",(abs(r1-r2)-d)/2);
    else puts("0");
    return 0;
}