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
    char *p=strchr(s,'0');
    if ( !p ) puts(s+1);
    else {
        *p=0;
        printf("%s%s",s,p+1);
    }
    return 0;
}