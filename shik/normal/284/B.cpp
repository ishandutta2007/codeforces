// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 200010
char s[N];
int main()
{
    int n,ca=0,cf=0,ci=0;
    scanf("%d%s",&n,s);
    for ( int i=0; i<n; i++ )
        if ( s[i]=='A' ) ca++;
        else if ( s[i]=='F' ) cf++;
        else ci++;
    int ans=0;
    if ( ci==1 ) ans=1;
    else if ( ci==0 ) ans=ca;
    printf("%d\n",ans);
    return 0;
}