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
    char a[1010],b[1010];
    scanf("%s%s",a,b);
    int x=count(a,a+strlen(a),'1');
    int y=count(b,b+strlen(b),'1');
    if ( x%2==1 ) x++;
    puts(x>=y?"YES":"NO");
    return 0;
}