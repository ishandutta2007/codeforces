// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 100010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
inline void chkmax( int &a, int b ) { if ( b>a ) a=b; }
int a[N],dp[N];
bool good[N];
vector<int> e[N];
int main()
{
    int n,ans=1;
    scanf("%d",&n);
    for ( int i=0; i<n; i++ ) scanf("%d",a+i);
    for ( int i=0; i<n; i++ ) good[a[i]]=1;
    for ( int i=2; i<N; i++ ) {
        int pre=0;
        for ( int j=i; j<N; j+=i ) if ( good[j] ) {
            if ( pre ) e[j].push_back(pre);
            pre=j;
        }
    }
    for ( int i=2; i<N; i++ ) if ( good[i] ) {
        dp[i]=1;
        FOR(it,e[i]) chkmax(dp[i],dp[*it]+1);
        chkmax(ans,dp[i]);
    }
    printf("%d\n",ans);
    return 0;
}