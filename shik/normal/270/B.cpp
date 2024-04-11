// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 100010
int a[N];
int main()
{
    int n;
    scanf("%d",&n);
    for ( int i=1; i<=n; i++ ) scanf("%d",a+i);
    while ( n>1 && a[n]>a[n-1] ) n--;
    printf("%d\n",n-1);
    return 0;
}