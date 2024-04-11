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

typedef long double D;

void shik( int l, int r, int x, D &q1, D &q2, D &q3 ) {
    D m=r-l+1;
    if ( x<l ) {
        q1=0;
        q2=0;
        q3=1;
    } else if ( x<=r ) {
        q1=(x-l)/m;
        q2=1/m;
        q3=(r-x)/m;
    } else {
        q1=1;
        q2=0;
        q3=0;
    }
}

#define N 10
int n,l[N],r[N];
int main() {
    RI(n);
    REP(i,n) RI(l[i],r[i]);
    D ans=0;
    REP1(x,1,10000) {
        D dp[N][N]={};
        dp[0][0]=1;
        REP(j,n) {
            D q1,q2,q3;
            shik(l[j],r[j],x,q1,q2,q3);
            for ( int k1=n-1; k1>=0; k1-- ) for ( int k2=n-1; k2>=0; k2-- ) {
                D me=dp[k1][k2];
                dp[k1][k2]=0;
                if ( me==0 ) continue;
                dp[k1][k2]+=q1*me;
                dp[k1+1][k2]+=q2*me;
                dp[k1][k2+1]+=q3*me;
            }
        }
        D p=0;
        REP1(i,1,n) {
            p+=dp[i][1];
            if ( i>=2 ) p+=dp[i][0];
        }
        // if ( p>0 ) printf("%d: %Lf\n",x,p);
        ans+=p*x;
    }
    printf("%.12f\n",(double)ans);
    return 0;
}