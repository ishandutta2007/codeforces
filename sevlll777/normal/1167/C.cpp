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
    vector<vector<int>> gr(n);
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        vector<int> lol(k);
        for (int j = 0;j < k; j++) {cin >> lol[j]; lol[j]--;}
        for (int j = 0; j < k- 1; j++) {
            gr[lol[j]].pb(lol[j+1]);
            gr[lol[j+1]].pb(lol[j]);
        }
    }
    vector<int> ans(n);
    bitset<2000008> used;
    for (int v = 0; v < n; v++) {
        if (!used[v]) {
            vector<int> lol = {v};
            deque<int> q ={v};
            used[v] = true;
            while(!q.empty()) {
                int u = q.front();
                q.pop_front();
                for (auto uu :gr[u]) {
                    if (!used[uu]) {
                        used[uu] = true;
                        q.pb(uu);
                        lol.pb(uu);
                    }
                }
            }
            for (auto x : lol) {
                ans[x] = (int) lol.size();
            }
        }
    }
    for (auto p :ans) cout << p << ' ';
}