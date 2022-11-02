// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#define N 100010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
inline void chkmax( LL &a, LL b ) { if ( b>a ) a=b; }
int n,q,c[N],v[N];
LL dp[N];
int main()
{
    scanf("%d%d",&n,&q);
    for ( int i=1; i<=n; i++ ) scanf("%d",v+i);
    for ( int i=1; i<=n; i++ ) scanf("%d",c+i);
    while ( q-- ) {
        LL a,b;
        cin>>a>>b;
        for ( int i=0; i<N; i++ ) dp[i]=(LL)-1e15;
        pair<LL,int> big[2];
        for ( int i=1; i<=n; i++ ) {
            chkmax(dp[c[i]],dp[c[i]]+a*v[i]);
            for ( int j=0; j<2; j++ ) if ( c[i]!=big[j].second ) {
                chkmax(dp[c[i]],big[j].first+b*v[i]);
                break;
            }
            if ( big[0].second==c[i] ) chkmax(big[0].first,dp[c[i]]);
            else if ( big[1].second==c[i] ) chkmax(big[1].first,dp[c[i]]);
            else if ( dp[c[i]]>=big[1].first ) big[1]=make_pair(dp[c[i]],c[i]);
            if ( big[0]<big[1] ) swap(big[0],big[1]);
        }
        cout<<big[0].first<<endl;
    }
    return 0;
}