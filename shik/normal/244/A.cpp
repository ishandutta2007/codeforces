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
    int n,k,vis[1000]={},ans[30][30];
    scanf("%d%d",&n,&k);
    for ( int i=0; i<k; i++ ) {
        int x;
        scanf("%d",&x);
        vis[x]=1;
        ans[i][0]=x;
    }
    for ( int i=0; i<k; i++ ) {
        int m=1;
        for ( int j=1; m<n; j++ ) if ( !vis[j] ) {
            vis[j]=1;
            ans[i][m++]=j;
        }
        for ( int j=0; j<n; j++ ) printf("%d%c",ans[i][j],j==n-1?'\n':' ');
    }
    return 0;
}