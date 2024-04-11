// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
char s[100010];
int main()
{
    gets(s);
    for ( int i=0,j; s[i]; i=j ) {
        if ( s[i]==' ' ) {
            j=i+1;
            continue;
        }
        putchar('<');
        if ( s[i]=='"' ) {
            for ( j=i+1; s[j]!='"'; j++ ) putchar(s[j]);
            j++;
        } else {
            for ( j=i; s[j] && s[j]!=' '; j++ ) putchar(s[j]);
        }
        puts(">");
    }
    return 0;
}