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
    int n,_t;
    char s[100],t[100];
    scanf("%d%d%s",&n,&_t,s);
    while ( _t-- ) {
        strcpy(t,s);
        for ( int i=n-2; i>=0; i-- ) if ( s[i]=='B' && s[i+1]=='G' ) swap(t[i],t[i+1]);
        strcpy(s,t);
    }
    puts(s);
    return 0;
}