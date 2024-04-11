#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define endl "\n"
const int inf = 1e18;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        a--, b--;
        vector<int> x(n);
        for (int i=0; i<n; i++)
            cin >> x[i];

        vector<int> st1(4 * n), st2(4 * n), dist(n, -1);
        queue<int> que;

        auto build = [&] (auto &self, int p, int l, int r) -> void {
            if (l == r) {
                if (l == a) {
                    st1[p] = inf;
                    st2[p] = -inf;
                } else {
                    st1[p] = l - x[l];
                    st2[p] = l + x[l];
                }
                return;
            }
            int m = (l + r) / 2;
            self(self, 2 * p, l, m);
            self(self, 2 * p + 1, m + 1, r);
            st1[p] = min(st1[2*p], st1[2*p+1]);
            st2[p] = max(st2[2*p], st2[2*p+1]);
        };

        auto query = [&] (auto &self, int p, int l, int r, int i, int j, int x, bool b) -> void {
            if (i > r || j < l || (b ? st2[p] < x : st1[p] > x))
                return;
            if (l == r) {
                dist[l] = dist[x] + 1;
                que.push(l);
                st1[p] = inf;
                st2[p] = -inf;
                return;
            }
            int m = (l + r) / 2;
            self(self, 2 * p, l, m, i, j, x, b);
            self(self, 2 * p + 1, m + 1, r, i, j, x, b);
            st1[p] = min(st1[2*p], st1[2*p+1]);
            st2[p] = max(st2[2*p], st2[2*p+1]);
        };

        build(build, 1, 0, n - 1);
        dist[a] = 0;
        que.push(a);
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            if (u > 0)
                query(query, 1, 0, n - 1, max(u - x[u], 0LL), u - 1, u, 1);
            if (u + 1 < n)
                query(query, 1, 0, n - 1, u + 1, min(u + x[u], n - 1), u, 0);
        }
        cout << dist[b] << "\n";
    }

    return 0;
}