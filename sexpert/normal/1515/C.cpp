#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<int, 2>;

void solve() {
    int n, m, x;
    cin >> n >> m >> x;
    set<ii> cur;
    for(int i = 1; i <= m; i++)
        cur.insert({0, i});

    cout << "YES\n";
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;
        auto p = *cur.begin();
        cur.erase(cur.begin());
        cout << p[1] << " ";
        cur.insert({p[0] + k, p[1]});
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}