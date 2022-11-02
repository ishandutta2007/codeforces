// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
char s[100010],t[100010];
int main()
{
    gets(s); gets(t);
    if ( strlen(s)!=strlen(t) ) return puts("NO"),0;
    int c=0,w[3];
    for ( int i=0; s[i] && c<=2; i++ ) if ( s[i]!=t[i] ) w[c++]=i;
    if ( c==2 ) swap(s[w[0]],s[w[1]]);
    puts(c==2 && strcmp(s,t)==0?"YES":"NO");
    return 0;
}