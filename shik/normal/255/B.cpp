// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
char s[1000010];
int main()
{
    gets(s);
    int c[2]={};
    for ( int i=0; s[i]; i++ ) c[s[i]-'x']++;
    for ( int i=0; i<abs(c[0]-c[1]); i++ ) putchar('x'+(c[1]>c[0]));
    puts("");
    return 0;
}