// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define CB __builtin_popcount
inline int bit( int x, int i ) { return (x>>i)&1; }
inline void chkmin( int &a, int b ) { if ( b<a ) a=b; }
#define N 23
int n,a[N],dp[1<<N];
bool vis[1<<N],can[1<<N];
int go( int s, int p ) {
    int &ret=dp[s];
    if ( vis[s] ) return ret;
    vis[s]=1;
    if ( p==n ) return ret=CB(s);
    ret=n+1;
    if ( !can[s] ) return ret;
    chkmin(ret,go(s|(1<<p),p+1));
    for ( int i=s; i; i-=i&-i ) chkmin(ret,go((s^(i&-i))|(1<<p),p+1));
    return ret;
}
int main()
{
    scanf("%d",&n);
    for ( int i=0; i<n; i++ ) scanf("%d",a+i);
    for ( int i=0; i<n; i++ ) for ( int j=i; j<n; j++ )
        for ( int k=j+1; k<n; k++ ) if ( a[i]+a[j]==a[k] ) can[(1<<i)|(1<<j)|(1<<(k-1))]=1;
    for ( int i=0; i<n-1; i++ ) for ( int j=0; j<(1<<i); j++ )
        for ( int k=j; k; k-=k&-k ) can[(1<<i)|j]|=can[(1<<i)|(j^(k&-k))];
    go(1,1);
    printf("%d\n",dp[1]>n?-1:dp[1]);
    return 0;
}