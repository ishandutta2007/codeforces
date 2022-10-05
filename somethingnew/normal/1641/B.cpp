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
vector<int> parts;
vector<pair<int, int>> op;
int add = 0;
void revpref(vector<int> &a, int ln) {
    for (int i = 0; i < ln; ++i) {
        op.push_back({ln + add + i, a[i]});
    }
    parts.push_back(ln * 2);
    //cerr << parts.back() << endl;
    add += ln * 2;
    reverse(a.begin(), a.begin() + ln);
}
void slv(vector<int> a) {
    int mx = 0;
    while (!a.empty()) {
        mx = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] >= a[mx])
                mx = i;
        }
        if (a[mx] == a.back())
            a.pop_back();
        else {
            //cerr << a.size() << ' ' << mx + 1 << endl;
            revpref(a, mx+1);
            revpref(a, a.size());
        }
    }
}
void solve() {
    int n;
    cin >> n;
    parts.clear();
    op.clear();
    add = 0;
    vector<int> a(n), b;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (n % 2 == 1) {
        cout << "-1\n";
        return;
    }
    b = a;
    sort(all(b));
    for (int i = 0; i < n; i += 2) {
        if (b[i] != b[i + 1]) {
            cout << "-1\n";
            return;
        }
    }
    slv(a);
    cout << op.size() << '\n';
    for (auto i : op)
        cout << i.first << ' ' << i.second << '\n';
    for (int i = 0; i < n; i += 2) {
        parts.push_back(2);
    }
    cout << parts.size() << '\n';
    for (long long part : parts) {
        cout << part << ' ';
    }
    cout << '\n';
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