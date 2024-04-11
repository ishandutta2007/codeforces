// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 1000010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
char s[N];
void go( int x ) {
    if ( s[x]=='l' ) go(x+1);
    if ( s[x] ) printf("%d\n",x);
    if ( s[x]=='r' ) go(x+1);
}
int main()
{
    gets(s+1);
    go(1);
    return 0;
}