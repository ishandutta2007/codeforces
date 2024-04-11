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
int mod = 998244353;
vector<pair<int, int>> opr;
void rev(vector<int> &a, int l, int r) {
    opr.push_back({l, r});
    vector<int> b = a;
    for (int i = l; i <= r; ++i) {
        a[i] = b[r + l - i];
    }
}
void solve() {
    int n;
    cin >> n;
    opr.clear();
    vector<int> a(n), b(n);
    map<pair<int, int>, int> st;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 1; i < n; ++i) {
        st[{min(a[i], a[i-1]), max(a[i], a[i-1])}]++;
        st[{min(b[i], b[i-1]), max(b[i], b[i-1])}]--;
    }
    for (auto i : st) {
        if (i.second != 0) {
            cout << "No\n";
            return;
        }
    }
    if (a[0] != b[0]) {
        cout << "No\n";
        return;
    }
    for (int i = 0; i + 1 < n; ++i) {
        if (b[i + 1] == a[i + 1])
            continue;
        for (int j = i + 2; j < n; ++j) {
            if (a[j] == a[i] and a[j - 1] == b[i + 1]) {
                rev(a, i, j);
                break;
            }
        }
        if (b[i + 1] == a[i + 1])
            continue;
        int k = i + 1;
        for (; k + 1 < n; ++k) {
            if (a[k] == b[i] and a[k + 1] == b[i + 1])
                break;
        }
        if (k + 1 == n) {
            exit(1);
        }
        bool ok = 0;
        for (int j = i + 1; j <= k; ++j) {
            for (int l = k + 1; l < n; ++l) {
                if (a[j] == a[l]) {
                    rev(a, j, l);
                    ok = 1;
                    break;
                }
            }
            if (ok == 1)
                break;
        }
        if (ok == 0) {
            cout << "No\n";
            return;
        }
        if (b[i + 1] == a[i + 1])
            continue;
        for (int j = i + 2; j < n; ++j) {
            if (a[j] == a[i] and a[j - 1] == b[i + 1]) {
                rev(a, i, j);
                break;
            }
        }
        if (b[i + 1] != a[i + 1])
            exit(1);
    }
    cout << "Yes\n";
    cout << opr.size() << '\n';
    for (auto i : opr)
        cout << i.first + 1 << ' ' << i.second + 1 << '\n';
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