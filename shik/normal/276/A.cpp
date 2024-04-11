// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
    int n,k,ans=INT_MIN;
    scanf("%d%d",&n,&k);
    while ( n-- ) {
        int f,t;
        scanf("%d%d",&f,&t);
        ans=max(ans,f-max(t-k,0));
    }
    printf("%d\n",ans);
    return 0;
}