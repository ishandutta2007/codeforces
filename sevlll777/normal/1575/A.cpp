#include <bits/stdc++.h>

#define int long long
#define pb push_back
#define endl '\n'
#define all(x) x.begin(), x.end()

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (auto &el : s) {
        cin >> el;
        for (int i = 1; i < m; i += 2) {
            el[i] = 'Z' - el[i];
        }
    }
    vector<pair<string, int>> lol;
    for (int i = 0; i < n; i++) {
        lol.emplace_back(s[i], i);
    }
    sort(all(lol));
    for (auto el : lol) {
        cout << el.second + 1 << ' ';
    }
    cout << '\n';
}