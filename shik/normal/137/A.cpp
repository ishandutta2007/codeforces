// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
    char s[110];
    gets(s);
    int ans=0,cnt=0;
    for ( int i=0; s[i]; i++ ) {
        if ( cnt==0 ) cnt++;
        else if ( cnt==5 || s[i]!=s[i-1] ) ans++,cnt=1;
        else cnt++;
    }
    if ( cnt ) ans++;
    printf("%d\n",ans);
    return 0;
}