#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 55;
int n, m;
string G[MX];
char B[2];

void solve() {
    B[0] = B[1] = '?';
    bool ok = true;
    REP(i, n) REP(j, m) {
        int p = (i + j) % 2;
        if (G[i][j] == 'R') {
            if (B[1-p] == 'R' || B[p] == 'W') ok = false;
            B[p] = 'R'; B[1-p] = 'W';
        } else if (G[i][j] == 'W') {
            if (B[1-p] == 'W' || B[p] == 'R') ok = false;
            B[p] = 'W'; B[1-p] = 'R';
        }
    }

    if (!ok) {
        cout << "NO\n";
        return;
    }

    if (B[0] == '?') {
        B[0]  = 'R'; B[1] = 'W';
    }

    REP(i, n) REP(j, m) {
        int p = (i + j) % 2;
        G[i][j] = B[p];
    }

    cout << "YES\n";
    REP(i, n) cout << G[i] << "\n";
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>m;
        REP(i, n) {
            cin>>G[i];
        }
        solve();
    }
    
    return 0;
}