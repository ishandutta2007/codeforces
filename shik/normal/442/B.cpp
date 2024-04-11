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

#define N 110
int n;
double p[N];

int main() {
    RI(n);
    REP(i,n) scanf("%lf",p+i);
    if ( count(p,p+n,1.0) ) {
        puts("1");
        return 0;
    }
    sort(p,p+n);
    double ans=0;
    REP(i,n) {
        long double s1=1,s2=0;
        REP1(j,i,n-1) {
            s1*=(1-p[j]);
            s2+=p[j]/(1-p[j]);
            ans=max(ans,(double)(s1*s2));
        }
    }
    printf("%.9f\n",ans);
    return 0;
}