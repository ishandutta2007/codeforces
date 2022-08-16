#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 400005;
const LL MOD = 1e9+7;
int a[2][MX];
int p[2][MX];
bool d[MX];
int n;

LL solve() {
    REP(j, 2) {
        REP(i, n) p[j][a[j][i]] = i;
    }
    memset(d, 0, sizeof d);
    int m = 0;
    queue<int> Q;
    REP(i, n) {
        if (d[i]) continue;
        ++m;
        Q.push(i);
        while (!Q.empty()) {
            int c = Q.front(); Q.pop();
            if (d[c]) continue;
            d[c] = true;
            REP(j, 2) {
                int nc = p[1-j][a[j][c]];
                Q.push(nc);
            }
        }
    }

    LL r = 1;
    REP(i, m) {
        r <<= 1;
        if (r >= MOD) r %= MOD;
    }
    return r;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        REP(j, 2) REP(i, n) {
            cin>>a[j][i];
        }
        cout<<solve()<<"\n";
    }
    
    return 0;
}