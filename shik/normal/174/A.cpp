// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
    int n,b,a[110];
    scanf("%d%d",&n,&b);
    for ( int i=0; i<n; i++ ) scanf("%d",a+i);
    for ( int i=0; i<n; i++ ) b+=a[i];
    double s=(double)b/n;
    for ( int i=0; i<n; i++ ) if ( a[i]>s ) return puts("-1"),0;
    for ( int i=0; i<n; i++ ) printf("%.12f\n",s-a[i]);
    return 0;
}