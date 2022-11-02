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
#define N 200010
int n,a[N];
LL dp[2][N];
int vis[2][N];
LL go( int s, int x ) {
    if ( x<=0 || x>n ) return 0;
    if ( x==1 || vis[s][x]==1 ) return -1;
    LL &ret=dp[s][x];
    if ( vis[s][x]==2 ) return ret;
    vis[s][x]=1;
    LL val=go(s^1,(s==0?x+a[x]:x-a[x]));
    vis[s][x]=2;
    if ( val==-1 ) return ret=-1;
    else return ret=a[x]+val;
}
int main()
{
    scanf("%d",&n);
    for ( int i=2; i<=n; i++ ) scanf("%d",a+i);
    for ( int i=1; i<n; i++ ) {
        LL val=go(1,1+i);
        if ( val==-1 ) puts("-1");
        else cout<<val+i<<endl;
    }
    return 0;
}