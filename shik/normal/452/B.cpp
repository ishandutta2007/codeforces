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

double dis( PII a, PII b ) {
    double dx=a.first-b.first;
    double dy=a.second-b.second;
    return sqrt(dx*dx+dy*dy);
}

int main() {
    int n,m;
    RI(n,m);
    n++; m++;
    vector<PII> v;
    REP(i,n) REP(j,m) if ( (i<3 || n-i<3) && (j<3 || m-j<3) ) v.PB(MP(i,j));
    double mx=-1;
    vector<PII> sol;
    int nv=SZ(v);
    REP(i,nv) REP(j,nv) REP(k,nv) REP(l,nv) {
        if ( i==j || i==k || i==l || j==k || j==l || k==l ) continue;
        double now=dis(v[i],v[j])+dis(v[j],v[k])+dis(v[k],v[l]);
        if ( now>mx ) {
            mx=now;
            sol={v[i],v[j],v[k],v[l]};
        }
    }
    REP(i,4) printf("%d %d\n",sol[i].first,sol[i].second);
    return 0;
}