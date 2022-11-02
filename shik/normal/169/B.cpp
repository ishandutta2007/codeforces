// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 100010
char a[N],b[N];
int c[10];
int main()
{
    scanf("%s%s",a,b);
    for ( int i=0; b[i]; i++ ) c[b[i]-'0']++;
    for ( int i=0; a[i]; i++ ) for ( int j=9; j>a[i]-'0'; j-- ) if ( c[j]>0 ) {
        c[j]--;
        a[i]=j+'0';
    }
    puts(a);
    return 0;
}