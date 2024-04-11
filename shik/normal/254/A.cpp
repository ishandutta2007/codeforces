// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
vector<int> id[5010];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,x;
    scanf("%d",&n);
    for ( int i=1; i<=2*n; i++ ) {
        scanf("%d",&x);
        id[x].push_back(i);
    }
    for ( int i=1; i<=5000; i++ ) if ( SZ(id[i])%2!=0 ) return puts("-1"),0;
    for ( int i=1; i<=5000; i++ ) for ( int j=0; j<SZ(id[i]); j+=2 ) printf("%d %d\n",id[i][j],id[i][j+1]);
    return 0;
}