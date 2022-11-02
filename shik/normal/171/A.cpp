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
    int a,b,rb=0;
    scanf("%d%d",&a,&b);
    while ( b ) {
        rb=rb*10+b%10;
        b/=10;
    }
    printf("%d\n",a+rb);
    return 0;
}