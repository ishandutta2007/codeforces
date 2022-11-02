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
    int n,d[110],s,t;
    scanf("%d",&n);
    for ( int i=1; i<=n; i++ ) scanf("%d",d+i);
    scanf("%d%d",&s,&t);
    if ( s>t ) swap(s,t);
    int ans=0,sum=0;
    for ( int i=1; i<=n; i++ ) sum+=d[i];
    for ( int i=s; i<t; i++ ) ans+=d[i];
    ans=min(ans,sum-ans);
    printf("%d\n",ans);
    return 0;
}