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
    int n,a[100],sn=0,s[100];
    scanf("%d",&n);
    for ( int i=0; i<n; i++ ) scanf("%d",a+i);
    int c=0,d=0;
    for ( int i=0; i<n; i++ ) {
        if ( a[i]<0 && d==2 ) {
            s[sn++]=c;
            c=d=0;
        }
        c++;
        if ( a[i]<0 ) d++;
    }
    s[sn++]=c;
    printf("%d\n",sn);
    for ( int i=0; i<sn; i++ ) printf("%d%c",s[i],i==sn-1?'\n':' ');
    return 0;
}