// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 200010
vector<pair<int,int> > e[N];
int dp1[N],dp2[N];
int go1( int p, int f ) {
    FOR(it,e[p]) if ( it->second!=f ) dp1[p]+=it->first+go1(it->second,p);
    return dp1[p];
}
void go2( int p, int f ) {
    FOR(it,e[p]) if ( it->second!=f ) dp2[it->second]=dp1[p]+dp2[p]-it->first-dp1[it->second]+(it->first==0);
    FOR(it,e[p]) if ( it->second!=f ) go2(it->second,p);
}
int main()
{
    int n;
    scanf("%d",&n);
    for ( int i=1; i<n; i++ ) {
        int a,b;
        scanf("%d%d",&a,&b);
        e[a].push_back(make_pair(0,b));
        e[b].push_back(make_pair(1,a));
    }
    go1(1,0);
    go2(1,0);
    int ans=n;
    vector<int> sol;
    for ( int i=1; i<=n; i++ ) ans=min(ans,dp1[i]+dp2[i]);
    for ( int i=1; i<=n; i++ ) if ( ans==dp1[i]+dp2[i] ) sol.push_back(i);
    printf("%d\n",ans);
    for ( int i=0; i<SZ(sol); i++ ) printf("%d%c",sol[i],i==SZ(sol)-1?'\n':' ');
    return 0;
}