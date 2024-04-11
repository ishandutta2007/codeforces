// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
set<double> good;
int main()
{
    for ( int i=3; i<=100000; i++ ) good.insert((i-2)*180.0/i);
    int t,n;
    scanf("%d",&t);
    while ( t-- ) {
        scanf("%d",&n);
        puts(good.count(n)?"YES":"NO");
    }
    return 0;
}