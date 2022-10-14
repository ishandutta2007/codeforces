#include <bits/stdc++.h>

using namespace std;

//#define int long long
#define fro for
#define pb push_back
#define ld long double


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<set<int>> gr(n);
    fro (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        gr[a].insert(b);
        gr[b].insert(a);
    }
    int ans = 1e9;
    for (int v = 0; v < n; v++) {
        for (auto u : gr[v]) {
            for (auto uu : gr[v]) {
                if (u != uu && gr[u].find(uu) != gr[u].end()) {
                    ans = min(ans, (int) gr[v].size() + (int) gr[u].size() + (int) gr[uu].size());
                }
            }
        }
    }
    if (ans == 1e9) {
        cout << -1;
    } else {
        cout << ans-6;
    }

}