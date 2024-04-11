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
    bool ans=1;
    char s[10];
    for ( int i=0; i<8; i++ ) {
        gets(s);
        for ( int j=0; j<8; j++ ) if ( s[j]==s[(j+1)%8] ) ans=0;
    }
    puts(ans?"YES":"NO");
    return 0;
}