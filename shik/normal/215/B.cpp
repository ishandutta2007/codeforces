// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#define N 5010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
void read( int &n, int a[] ) {
    scanf("%d",&n);
    for ( int i=0; i<n; i++ ) scanf("%d",a+i);
}
int n,m,k,x[N],y[N],z[N],A,B;
int main()
{
    // (pi * r1 * r1 - pi * r2 * r2) * p1 / (pi * r2 * r2) = A/B
    // (r1^2 - r2^2) * p1/(r2^2 * p2) = A/B
    // B * (r1^2 - r2^2) * p1 = A * r2^2 * p2
    // B * r1^2 * p1 = (A * p2 + B * p1) * r2 ^ 2
    // r2 = sqrt(B * r1^2 * p1 / (A * p2 + B * p1))
    read(n,x);
    read(m,y);
    read(k,z);
    scanf("%d%d",&A,&B);
    int r1=*max_element(x,x+n);
    double ans=0;
    for ( int i=0; i<m; i++ ) for ( int j=0; j<k; j++ ) {
        int p1=y[i],p2=z[j];
        ans=max(ans,sqrt((double)B*r1*r1*p1/(A*p2+B*p1)));
    }
    printf("%.9f\n",ans);
    return 0;
}