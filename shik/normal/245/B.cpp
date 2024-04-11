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
    char s[100];
    int flg=0;
    gets(s);
    for ( int i=0; s[i]; i++ ) {
        if ( strncmp(s,"http",4)==0 && i==4 ) printf("://"),flg=-1;
        if ( strncmp(s,"ftp",3)==0 && i==3 ) printf("://"),flg=-1;
        if ( flg==0 && strncmp(s+i,"ru",2)==0 ) printf("."),flg=1;
        if ( flg==1 && i>=2 && strncmp(s+i-2,"ru",2)==0 ) printf("/"),flg=2;
        flg=max(flg,0);
        putchar(s[i]);
    }
    puts("");
    return 0;
}