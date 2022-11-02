// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 100010
int a[N];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for ( int i=0; i<n; i++ ) scanf("%d",a+i);
    sort(a,a+n);
    set<int> s;
    for ( int i=0; i<n; i++ ) if ( a[i]%k!=0 || !s.count(a[i]/k) ) s.insert(a[i]);
    printf("%d\n",SZ(s));
    return 0;
}