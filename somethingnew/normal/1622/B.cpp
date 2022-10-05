#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "queue"
#include "numeric"
#define int long long
#define all(x) (x).begin(), (x).end()
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    string s;cin >> s;
    vector<pair<int, int>> b, c;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0')
            b.push_back({a[i], i});
        else
            c.push_back({a[i], i});
    }
    sort(all(b));
    sort(all(c));
    for (int i = 0; i < b.size(); ++i) {
        a[b[i].second] = i + 1;
    }
    for (int i = 0; i < c.size(); ++i) {
        a[c[i].second] = b.size() + i + 1;
    }
    for (auto i : a)
        cout << i << ' ';
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    while (n--) solve();
}
//abacdcababb