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
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,k;
    pair<int,int> a[1010];
    scanf("%d%d",&n,&k);
    for ( int i=0; i<n; i++ ) scanf("%d",&a[i].first);
    for ( int i=0; i<n; i++ ) a[i].second=i+1;
    sort(a,a+n);
    printf("%d\n",a[n-k].first);
    for ( int i=1; i<=k; i++ ) printf("%d%c",a[n-i].second,i==k?'\n':' ');
    return 0;
}