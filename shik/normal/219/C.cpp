// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 500010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
inline void chkmin( int &a, int b ) { if ( b<a ) a=b; }
char s[N];
int main()
{
    int n,m;
    scanf("%d %d %s",&n,&m,s);
    if ( m==2 ) {
        int c[2]={};
        for ( int i=0; i<n; i++ ) c[s[i]=='A'+i%2]++;
        if ( c[0]<c[1] ) {
            printf("%d\n",c[0]);
            for ( int i=0; i<n; i++ ) putchar('A'+i%2);
        } else {
            printf("%d\n",c[1]);
            for ( int i=0; i<n; i++ ) putchar('B'-i%2);
        }
        puts("");
        return 0;
    }
    int ans=0;
    for ( int i=1; i<n; i++ ) if ( s[i]==s[i-1] ) {
        ans++;
        while ( s[i]==s[i-1] || s[i]==s[i+1] ) {
            s[i]++;
            if ( s[i]=='A'+m ) s[i]='A';
        }
    }
    printf("%d\n",ans);
    puts(s);
    return 0;
}