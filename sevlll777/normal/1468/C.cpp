#include <bits/stdc++.h>

#define int long long
#define all(x) x.begin(), x.end()
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int q;
    cin >> q;
    vector<int> c(q);
    set<int> kek;
    set<pair<int, int>> lol;
    int now = 0;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            now++;
            int m;
            cin >> m;
            c[now] = m;
            kek.insert(now);
            lol.insert({m, -now});
        } else if (t == 2) {
            int ind = *kek.begin();
            cout << ind << '\n';
            kek.erase(ind);
            lol.erase({c[ind], -ind});
        } else {
            int ind = -(--lol.end())->second;
            cout << ind << '\n';
            kek.erase(ind);
            lol.erase({c[ind], -ind});
        }
    }
}