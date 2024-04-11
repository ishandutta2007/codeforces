// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 310
#define MOD 1000000007
void add( int &a, int b ) {
    a+=b;
    if ( a>=MOD ) a-=MOD;
}
int a[N],to[N],in[N],v[N],dp[100010];
int main()
{
    int n,q,t,m=0;
    scanf("%d%d%d",&n,&q,&t);
    for ( int i=1; i<=n; i++ ) scanf("%d",a+i);
    while ( q-- ) {
        int b,c;
        scanf("%d%d",&b,&c);
        to[b]=c;
        in[c]++;
    }
    long long si=0,c=0;
    for ( int i=1; i<=n; i++ ) if ( !in[i] ) {
        int s=0;
        for ( int j=i; j; j=to[j] ) {
            c++;
            si+=s;
            s+=a[j];
            v[m++]=s;
        }
    }
    if ( si>t || c!=n ) {
        puts("0");
        return 0;
    }
    dp[si]=1;
    for ( int i=0; i<m; i++ ) for ( int j=v[i]; j<=t; j++ ) add(dp[j],dp[j-v[i]]);
    printf("%d\n",dp[t]);
    return 0;
}