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
int main()
{
    int n=strlen(gets(s));
    int ans=1,now=10;
    if ( s[0]=='?' ) ans*=9;
    else if ( strchr("ABCDEFGHIJ",s[0]) ) {
        ans*=9;
        now--;
    }
    int app[130]={};
    for ( int i=0; i<n; i++ ) app[(int)s[i]]=1;
    for ( int i='A'; i<='J'; i++ ) if ( s[0]!=i && app[i] ) {
        ans*=now--;
    }
    printf("%d",ans);
    int cq=count(s+1,s+n,'?');
    while ( cq-- ) putchar('0');
    puts("");
    return 0;
}