#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

LL n, m, x, y;
LL r1x, r1y, r2x, r2y;

void solve(LL &r1, LL &r2, LL p, LL pn) {
    if (p - 1 > pn - p) {
        r1 = 1;
        r2 = pn;
    }
    else {
        r2 = pn;
        r1 = 1;
    }
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>m>>x>>y;
        // solve(r1x, r2x, x, n);
        // solve(r1y, r2y, y, m);
        // cout<<r1x<<" "<<r1y<<" ";
        // cout<<r2x<<" "<<r2y<<"\n";
        cout <<"1 1 " << n << " " << m << "\n";
    }
    
    return 0;
}