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
    char s[314];
    gets(s);
    int big=0,sml=0,cnt=0;
    for ( int i=0; s[i]; i++ ) {
        if ( s[i]=='+' ) cnt++;
        else cnt--;
        big=max(big,cnt);
        sml=min(sml,cnt);
    }
    printf("%d\n",big-sml);
    return 0;
}