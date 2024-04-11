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
    char s[100],t[100];
    scanf("%s%s",s,t);
    int p=0;
    for ( int i=0; t[i]; i++ ) if ( s[p]==t[i] ) p++;
    printf("%d\n",p+1);
    return 0;
}