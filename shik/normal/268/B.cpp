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
    int n,ans=0;
    scanf("%d",&n);
    for ( int i=0; i<n; i++ ) {
        ans+=(i+1)*(n-i)-i;
    }
    printf("%d\n",ans);
    return 0;
}