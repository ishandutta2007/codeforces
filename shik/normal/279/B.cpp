// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 100010
int a[N];
int main()
{
    int n,t;
    scanf("%d%d",&n,&t);
    for ( int i=0; i<n; i++ ) scanf("%d",a+i);
    int ans=0,now=0;
    for ( int i=0,j=0; i<n; i++ ) {
        while ( j<n && now+a[j]<=t ) now+=a[j++];
        ans=max(ans,j-i);
        now-=a[i];
    }
    printf("%d\n",min(ans,n));
    return 0;
}