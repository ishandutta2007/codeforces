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
    vector<int> p, sz;
    dsu(int n) {
        p.assign(n, {});
        sz.assign(n, 1);
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
    }
    int getv(int v) {
        if (p[v] == v)
            return v;
        return p[v] = getv(p[v]);
    }
    int merge(int a, int b) {
        a = getv(a);
        b = getv(b);
        int vl = sz[b];
        if (b == a)
            exit(1);
        p[b] = a;
        sz[a] += sz[b];
        return vl;
    }
};
void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> k(n);
    for (int i = 0; i < n; ++i) {
        cin >> k[i].first;
        k[i].second = i;
    }
    sort(all(k));
    reverse(all(k));
    dsu usd(n);
    for (int j = 0; j < k.size(); ++j) {
        int p = k[j].second;
        if (usd.sz[usd.getv(p)] == 1) {
            for (int i = 0; i < k[j].first; ++i) {
                cout << "? " << p + 1 << endl;
                int x;
                cin >> x;
                x--;
                if (usd.merge(p, x) > 1)
                    break;
            }
        }
    }
    cout << "! ";
    for (int l = 0; l < n; ++l) {
        cout << usd.getv(l) + 1 << ' ';
    }
    cout << endl;
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