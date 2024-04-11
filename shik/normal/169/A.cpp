// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int n,a,b,h[2010];
int main()
{
    scanf("%d%d%d",&n,&a,&b);
    for ( int i=0; i<n; i++ ) scanf("%d",h+i);
    sort(h,h+n);
    printf("%d\n",h[b]-h[b-1]);
    return 0;
}