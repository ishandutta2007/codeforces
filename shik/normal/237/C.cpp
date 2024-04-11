// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
bool isp( int n ) {
    if ( n<2 ) return 0;
    for ( int i=2; i*i<=n; i++ ) if ( n%i==0 ) return 0;
    return 1;
}
int main()
{
    int a,b,k;
    scanf("%d%d%d",&a,&b,&k);
    int l=0,c=0;
    for ( int i=a; i+l-1<=b; i++ ) {
        while ( i+l<=b && c<k ) c+=isp(i+l++);
        if ( c<k ) l++;
        c-=isp(i);
        c+=isp(i+l);
    }
    printf("%d\n",l>b-a+1?-1:l);
    return 0;
}