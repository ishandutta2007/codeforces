// TwT514 {{{
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <bitset>
#include <queue>
#include <stack>
#include <functional>
#include <utility>
#define SZ(x) ((int)(x).size())
#define FOR(i,c) for (__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define REP(i,n) for (int i=0; i<(int)(n); i++)
#define REP1(i,a,b) for (int i=(int)(a); i<=(int)(b); i++)
#define ALL(x) (x).begin(),(x).end()
#define MS0(x,n) memset((x),0,(n)*sizeof(*x))
#define MS1(x,n) memset((x),-1,(n)*sizeof(*x))
#define MP make_pair
#define PB push_back
#define RI(a) scanf("%d",&(a))
#define RII(a,b) scanf("%d%d",&(a),&(b))
#define RIII(a,b,c) scanf("%d%d%d",&(a),&(b),&(c))
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
// }}}

bool isp( int n ) {
    if ( n<=1 ) return 0;
    for ( int i=2; i*i<=n; i++ ) if ( n%i==0 ) return 0;
    return 1;
}

bool shik( int n, vector<int> ps ) {
    vector<int> sol;
    queue<int> q;
    set<int> vis;
    FOR(it,ps) q.push(*it);
    while ( SZ(sol)<=n && !q.empty() ) {
        int v=q.front(); q.pop();
        sol.PB(v);
        FOR(it,ps) {
            int nv=*it*v;
            if ( !vis.count(nv) && nv<=2*n*n ) {
                vis.insert(nv);
                q.push(nv);
            }
        }
    }
    if ( SZ(sol)<n ) return 0;
    sort(ALL(sol));
    FOR(it,ps) {
        int cnt=0;
        FOR(jt,sol) if ( *jt%*it==0 ) cnt++;
        if ( cnt < (n+1)/2 ) return 0;
    }
    REP(i,n) printf("%d%c",sol[i],i+1==n?'\n':' ');
    return 1;
}

int main() {
    int n;
    while ( ~RI(n) ) {
        vector<int> ps={2};
        while ( !shik(n,ps) ) {
            int p=ps.back()+1;
            while ( !isp(p) ) p++;
            ps.PB(p);
        }
    }
    return 0;
}