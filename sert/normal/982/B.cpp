//made by Sert
#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9 + 34;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> w(n), s;
    for (int i = 0; i < n; i++) {
        cin >> w[i].first;
        w[i].second = i;
    }
    sort(w.begin(), w.end());
    int ci = 0;
    string p;
    cin >> p;
    for (int i = 0; i < (int)p.length(); i++) {
        if (p[i] == '0') {
            cout << w[ci].second + 1 << " ";
            s.push_back(w[ci++]);
        } else {
            cout << s.back().second + 1 << " ";
            s.pop_back();
        }
    }
    cout << "\n";
}

int main() {
#ifdef SERT
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    solve();
    //solve();
#endif
    solve();
    return 0;
}