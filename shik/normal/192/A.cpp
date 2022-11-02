// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
    set<int> s;
    int n;
    scanf("%d",&n);
    for ( int i=1; i*(i+1)/2<n; i++ ) s.insert(i*(i+1)/2);
    FOR(it,s) if ( s.count(n-*it) ) return puts("YES"),0;
    puts("NO");
    return 0;
}