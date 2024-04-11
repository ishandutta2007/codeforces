// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 100010
int a[N],b[N];
pair<int,int> x[2*N];
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for ( int i=0; i<n; i++ ) scanf("%d",a+i);
    for ( int i=0; i<m; i++ ) scanf("%d",b+i);
    int nm=0;
    for ( int i=0; i<n; i++ ) x[nm++]=make_pair(a[i],-1);
    for ( int i=0; i<m; i++ ) x[nm++]=make_pair(b[i],+1);
    sort(x,x+nm);
    int now=0,ok=0;
    for ( int i=nm-1; i>=0; i-- ) {
        now+=x[i].second;
        if ( now<0 ) ok=1;
    }
    puts(ok?"YES":"NO");
    return 0;
}