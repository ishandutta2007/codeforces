// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 1000010
char s[N];
int sum[N];
int main()
{
    int n=strlen(gets(s+1));
    for ( int i=1; i<=n; i++ ) sum[i]=sum[i-1]+(s[i]==s[i+1]);
    int m;
    scanf("%d",&m);
    while ( m-- ) {
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",sum[r-1]-sum[l-1]);
    }
    return 0;
}