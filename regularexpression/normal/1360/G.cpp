#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

#define ll long long
#define ld long double
#define int long long

void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if (n * a != m * b) {
        cout << "NO\n";
        return;
    }
    vector<vector<int>> ans;
    vector<int> cnt(m, 0);
    for (int i = 0; i < n; i++) {
        vector<int> row(m, 0);
        for (int k = 0; k < a; k++) {
            int id = -1;
            for (int j = 0; j < m; j++) {
                if (row[j]) continue;
                if (id == -1 || cnt[j] < cnt[id]) id = j;
            }
            row[id] = 1;
            cnt[id]++;
        }
        ans.pb(row);
    }
    cout << "YES\n";
    for (auto row : ans) {
        for (auto x : row) cout << x;
        cout << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}