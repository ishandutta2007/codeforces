// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x),end(x)
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define FOR(it,c) for ( auto it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

void RI() {}

template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}
// }}}

#define N 1000010
const int MOD=1e9+7;

LL M;
const int H=131;

bool isp( LL x ) {
    for ( int i=2; i<=100000; i++ ) if ( x%i==0 ) return 0;
    return 1;
}

LL pw[N];
void predo() {
    srand(time(0)^getpid());
    REP(i,29) if ( rand()%2 ) M|=1LL<<i;
    while ( !isp(M) ) M++;
    pw[0]=1;
    REP1(i,1,N-1) pw[i]=pw[i-1]*H%M;
}

int n,m,y[N];
char p[N];

LL sh[N];
LL hsh( int l, int r ) {
    LL h=sh[r+1]-sh[l]*pw[r-l+1]%M;
    if ( h<0 ) h+=M;
    return h;
}

int main() {
    predo();
    RI(n,m);
    scanf("%s",p);
    REP(i,m) RI(y[i]);
    int np=strlen(p);
    REP(i,np) sh[i+1]=(sh[i]*H+p[i])%M;
    int cnt=0;
    REP(i,m) {
        if ( i==0 ) {
            cnt+=y[i]-1;
        } else if ( y[i]>=y[i-1]+np ) {
            cnt+=y[i]-(y[i-1]+np);
        } else {
            int len=y[i-1]+np-y[i];
            LL h1=hsh(0,len-1);
            LL h2=hsh(np-len,np-1);
            if ( h1!=h2 ) {
                puts("0");
                return 0;
            }
        }
    }
    if ( m==0 ) cnt=n;
    else cnt+=n-(y[m-1]+np)+1;
    int ans=1;
    REP(i,cnt) ans=ans*26LL%MOD;
    printf("%d\n",ans);
    return 0;
}