// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 200010
double dat[N];
void ins( int x, double v ) {
    for ( int i=x; i; i-=i&-i ) dat[i]+=v;
}
double ask( double x ) {
    double s=0;
    for ( int i=x; i<N; i+=i&-i ) s+=dat[i];
    return s;
}
int main()
{
    int n,m=1;
    double all=0;
    scanf("%d",&n);
    while ( n-- ) {
        int t,a,b;
        scanf("%d",&t);
        if ( t==1 ) {
            scanf("%d%d",&a,&b);
            all+=a*b;
            ins(a,b);
        } else if ( t==2 ) {
            scanf("%d",&a);
            all+=a;
            m++;
            ins(m,a);
            ins(m-1,-a);
        } else if ( t==3 ) {
            double v=ask(m);
            all-=v;
            ins(m,-v);
            ins(m-1,v);
            m--;
        } else puts("QQ");
        printf("%.9f\n",all/m);
    }
    return 0;
}