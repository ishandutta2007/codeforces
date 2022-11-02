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
    int a,b,r;
    scanf("%d%d%d",&a,&b,&r);
    puts(2*r<=min(a,b)?"First":"Second");
    return 0;
}