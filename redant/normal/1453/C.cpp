#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 2005;
int a[MX][MX];
int n;
int r[10] = {0};
int mn[MX][10], mx[MX][10];

int f(int i, int j, int a1, int a2, int b1, int b2) {
    int r = 0;
    r = max(r, abs(a1-b1));
    r = max(r, abs(a1-b2));
    r = max(r, abs(a2-b1));
    r = max(r, abs(a2-b2));
    return r * max(max(j, n - 1 - i), max(i, n - 1 - j));
}

void solve2() {
    REP(i, n) {
        REP(k, 10) mn[i][k] = n, mx[i][k] = -1;
        REP(j, n) {
            int x = a[i][j];
            mn[i][x] = min(mn[i][x], j);
            mx[i][x] = max(mx[i][x], j);
        }
        REP(k, 10) {
            if (mn[i][k] < n && mx[i][k] >= 0)
                r[k] = max(r[k], (mx[i][k] - mn[i][k]) * max(i, n - 1 - i));
        }
    }
    REP(k, 10) {
        REP(i, n) {
            if (mn[i][k] >= n) continue;
            REP(j, i) {
                if (mn[j][k] >= n) continue;
                r[k] = max(r[k], f(i, j, mn[i][k], mx[i][k], mn[j][k], mx[j][k]));
                if (k == 1) {
                    // cout << i << ", " << j << endl;
                }
            }
        }
    }
}

void solve() {
    REP(k, 10) r[k] = 0;
    solve2();
    REP(i, n) REP(j, i) swap(a[i][j], a[j][i]);
    solve2();
    REP(i, 10) cout << r[i] << " ";
    cout << "\n";
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        REP(i, n) {
            string s; cin >> s;
            REP(j, n) a[i][j] = s[j] - '0';
        }
        solve();
    }
    
    return 0;
}