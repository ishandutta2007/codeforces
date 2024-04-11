// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
    char s[110],t[]="><+-.,[]";
    gets(s);
    int ans=0;
    for ( int i=0; s[i]; i++ ) ans=(ans*16+(8+strchr(t,s[i])-t))%1000003;
    printf("%d\n",ans);
    return 0;
}