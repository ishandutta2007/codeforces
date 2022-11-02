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
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    char s[110];
    scanf("%d%s",&n,s+1);
    for ( int i=1; i<=n/2; i++ ) {
        if ( s[i]!='R' && s[n/2+i]!='L' ) printf("%d %d\n",i,n/2+i);
        else printf("%d %d\n",n/2+i,i);
    }
    return 0;
}