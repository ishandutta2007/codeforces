// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
#define N 100010
LL a[N],d[N],w[N];
int l[N],r[N],x[N],y[N],z[N];
int main()
{
    ios_base::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    for ( int i=1; i<=n; i++ ) cin>>a[i];
    for ( int i=1; i<=m; i++ ) cin>>l[i]>>r[i]>>d[i];
    for ( int i=1; i<=k; i++ ) cin>>x[i]>>y[i];
    for ( int i=1; i<=k; i++ ) z[x[i]]++,z[y[i]+1]--;
    for ( int i=1; i<=m; i++ ) z[i]+=z[i-1];
    for ( int i=1; i<=m; i++ ) {
        w[l[i]]+=d[i]*z[i];
        w[r[i]+1]-=d[i]*z[i];
    }
    for ( int i=1; i<=n; i++ ) w[i]+=w[i-1];
    for ( int i=1; i<=n; i++ ) a[i]+=w[i];
    for ( int i=1; i<=n; i++ ) cout<<a[i]<<(i==n?'\n':' ');
    return 0;
}