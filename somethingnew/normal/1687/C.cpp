//        
//   @roadfromroi 
//        
#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "cmath"
#include "map"
#include "deque"
#include "array"
#include "set"
#define all(x) x.begin(), x.end()
using namespace std;
#define int long long
struct dsu{
    vector<int> nxt;
    void init(int n) {
        nxt.assign(n + 1, {0});
        for (int i = 0; i <= n; ++i) {
            nxt[i] = i;
        }
    }
    int getv(int v) {
        if (nxt[v] == v)
            return v;
        return nxt[v] = getv(nxt[v]);
    }
    void ex(int i) {
        nxt[i] = i + 1;
    }
};
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    vector<int> ex(n+1);
    ex[0] = 1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    dsu ds;
    vector<vector<int>> frnd(n+1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        frnd[a].push_back(b);
        frnd[b].push_back(a);
    }
    ds.init(n+1);
    int pr = 0;
    vector<pair<int, int>> que;
    for (int i = 0; i < n; ++i) {
        pr += a[i] - b[i];
        if (pr == 0) {
            //cout << i + 1 << endl;
            ex[i+1] = 1;
            ds.ex(i+1);
            for (auto x : frnd[i+1]) {
                if (ex[x]) {
                    que.push_back({min(i, x), max(i, x)});
                }
            }
        }
    }
    while (!que.empty()) {
        auto [l, r] = que.back();
        que.pop_back();
        int x = ds.getv(l+1);
        while (x <= r) {
            //cout << x << ' ';
            int i = x;
            ex[i] = 1;
            ds.ex(i);
            for (auto x : frnd[i]) {
                if (ex[x]) {
                    //cerr << x << ' ' << i << endl;
                    que.push_back({min(i, x), max(i, x)});
                }
            }
            x = ds.getv(x);
        }
        //cout << endl;
    }
    for (int i = 0; i <= n; ++i) {
        if (ex[i] == 0) {
            //cout << i << endl;
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}