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
    int a,ans=1;
    scanf("%d",&a);
    for ( int i=2; i<=a; i++ ) ans+=12*(i-1);
    printf("%d\n",ans);
    return 0;
}