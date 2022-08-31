#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 300005;
int a[MX], b[MX];
int perm[MX];
int n, m;

int get(int k) {
    REP(i, n)
        perm[(i-k+n)%n] = a[i];
    vector<bool> vis(n, false);
    int cycs = 0;
    REP(i, n) {
        if (vis[i])
            continue;
        int j = i;
        while (!vis[j]) {
            vis[j] = true;
            j = perm[j];
        }
        ++cycs;
    }
    return n - cycs;
}

void solve() {
    REP(i, n) b[i] = 0;
    REP(i, n) {
        int p = (i-a[i]+n)%n;
        b[p]++;
    }
    vector<int> res;
    REP(i, n)
        if (3 * b[i] >= n && get(i) <= m) {
            res.push_back(i);
        }
    cout << res.size() << " ";
    for (auto &x : res)
        cout << x << " ";
    cout << "\n";
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>m;
        REP(i, n) {
            cin>>a[i];
            --a[i];
        }
        solve();
    }
    
    return 0;
}