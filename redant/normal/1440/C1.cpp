#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 102;
int a[MX][MX];
int n, m;
vector<pair<int, int> > ans;
vector<array<int, 3> > ans2;
vector<array<int, 3> > ops;
int s, e, x, y; // lol
bool res;

void print() {
    REP(i, n) {
        REP(j, m) cout << a[i][j];
        cout << endl;
    }
    cout << endl;
}

inline void flip(int i, int j) {
    assert(i >= 0 && i < n);
    assert(j >= 0 && j < m);
    a[i][j] = 1 - a[i][j];
    if (res) ans.push_back({i, j});
}

inline void flip(int i, int j, int op) {
    flip(i, j);
    if (op == 0) { flip(i+1,j); flip(i, j+1); }
    else if (op == 1) { flip(i,j-1); flip(i+1, j); }
    else if (op == 2) { flip(i-1,j); flip(i, j+1); }
    else if (op == 3) { flip(i-1,j); flip(i, j-1); }
}

bool go(int t) {
    if (a[s][x]==0 && a[s][y]==0 && a[e][x]==0 && a[e][y]==0)
        return true;
    
    if (t == 4) return false;

    for (auto & ar : ops) {
        flip(ar[0], ar[1], ar[2]);
        if (go(t+1)) {
            ans2.push_back(ar);
            return true;
        }
        flip(ar[0], ar[1], ar[2]);
    }

    return false;
}

void solve() {
    ans.clear(); ans2.clear();
    res = true;
    REP(i, n-2) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) {}
            else if (j+1<m && a[i][j+1]==1) {
                flip(i,j,0);
            } else {
                flip(i+1,j,(j+1)<m?2:3);
            }
        }
    }

    s = n - 2, e = n - 1;
    REP(j, m-2) {
        if (a[s][j] == 1 && a[e][j] == 1) {
            flip(s, j, 0);
        } else if (a[s][j] == 1) {
            flip(s, j + 1, 1);
        } else if (a[e][j] == 1) {
            flip(e, j + 1, 3);
        }
    }

    x = m - 2, y = m - 1;
    res = false;
    ops.clear();
    ops.push_back({s, x, 0});
    ops.push_back({s, y, 1});
    ops.push_back({e, x, 2});
    ops.push_back({e, y, 3});
    go(0);

    res = true;
    for (auto & ar : ans2) {
        flip(ar[0], ar[1], ar[2]);
    }

    int N = ans.size();
    cout << N / 3 << endl;
    for (int i = 0; i < N; i++) {
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << " \n"[(i+1)%3 == 0];
    }
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>m;
        REP(i, n) {
            string s; cin >> s;
            REP(j, m) 
                a[i][j] = s[j] - '0';
        }
        solve();
        // print();
    }
    
    return 0;
}