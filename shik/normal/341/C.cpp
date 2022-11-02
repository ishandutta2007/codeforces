// TwT514 {{{
#include <bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define FOR(i,c) for (__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define PER(i,n) for (int i=(int)(n)-1; i>=0; i--)
#define PER1(i,b,a) for (int i=(int)(b); i>=(int)(a); i--)
#define REP(i,n) for (int i=0; i<(n); i++)
#define REP1(i,a,b) for (int i=(int)(a); i<=(int)(b); i++)
#define ALL(x) (x).begin(),(x).end()
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
// }}}

#define N 2010
#define MOD 1000000007
int C[N][N],fac[N];
int n,a[N];
bool used[N];
int main() {
    REP(i,N) for ( int j=C[i][0]=1; j<=i; j++ ) C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
    for ( int i=fac[0]=1; i<N; i++ ) fac[i]=(LL)fac[i-1]*i%MOD;
    scanf("%d",&n);
    REP1(i,1,n) scanf("%d",a+i);
    REP1(i,1,n) if ( a[i]!=-1 ) used[a[i]]=1;
    int c1=0,c2=0;
    REP1(i,1,n) if ( a[i]==-1 ) {
        c1++;
        if ( !used[i] ) c2++;
    }
    LL ans=0;
    REP1(i,0,c2) {
        int now=(LL)C[c2][i]*fac[c1-i]%MOD;
        if ( i&1 ) now=-now;
        ans+=now;
    }
    ans%=MOD;
    if ( ans<0 ) ans+=MOD;
    printf("%d\n",(int)ans);
    return 0;
}