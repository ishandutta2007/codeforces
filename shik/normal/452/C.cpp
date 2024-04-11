// shik {{{
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

const int N=1010;
const int M=1010;

long double lf[N*M];
long double C( int n, int k ) { return lf[n]-lf[k]-lf[n-k]; }

int main() {
    lf[0]=0;
    REP1(i,1,N*M-1) lf[i]=lf[i-1]+logl((long double)i);
    int n,m;
    RI(n,m);
    long double ans=0;
    REP1(i,1,min(n,m)) {
        long double x=C(m,i)+C(n*m-m,n-i)-C(n*m,n);
        long double y=(long double)i/n;
        ans+=expl(x)*y*y;
    }
    ans*=n;
    printf("%.12f\n",(double)ans);
    return 0;
}