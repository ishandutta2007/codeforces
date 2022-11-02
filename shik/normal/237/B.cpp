// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 55
vector<int> sol;
void add( int a, int b, int c, int d ) {
    sol.push_back(a);
    sol.push_back(b);
    sol.push_back(c);
    sol.push_back(d);
}
int n,c[N],v[N][N],id[N][N],sx[N*N],sy[N*N],sv[N*N],sn;
int main()
{
    scanf("%d",&n);
    for ( int i=1; i<=n; i++ ) scanf("%d",c+i);
    for ( int i=1; i<=n; i++ ) for ( int j=1; j<=c[i]; j++ ) scanf("%d",v[i]+j);
    for ( int i=1; i<=n; i++ ) for ( int j=1; j<=c[i]; j++ ) sv[id[i][j]=sn++]=v[i][j];
    sort(sv,sv+sn);
    for ( int i=1; i<=n; i++ ) for ( int j=1; j<=c[i]; j++ ) sx[sv[id[i][j]]]=i;
    for ( int i=1; i<=n; i++ ) for ( int j=1; j<=c[i]; j++ ) sy[sv[id[i][j]]]=j;
    for ( int i=1; i<=n; i++ ) for ( int j=1; j<=c[i]; j++ ) {
        while ( 1 ) {
            int x=sx[v[i][j]],y=sy[v[i][j]];
            if ( i==x && j==y ) break;
            add(i,j,x,y);
            swap(v[i][j],v[x][y]);
        }
    }
    printf("%d\n",SZ(sol)/4);
    for ( int i=0; i<SZ(sol); i+=4 ) printf("%d %d %d %d\n",sol[i],sol[i+1],sol[i+2],sol[i+3]);
    return 0;
}