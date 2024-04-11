#include <bits/stdc++.h>
using namespace std;

// #define int long long
// #define pb push_back
// #define mp make_pair
// #define pi pair<int, int>
// #define endl "\n"
// const int inf = 1e18;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Node {
    int ch[2], sz, val = -1e9, mx = -1e9;
    long long key;
} tr[200005];
int id = 1;

int newNode(long long key, int val) {
    int p = id++;
    tr[p].ch[0] = tr[p].ch[1] = 0;
    tr[p].sz = 1;
    tr[p].val = tr[p].mx = val;
    tr[p].key = key;
    return p;
}

void pull(int p) {
    int l = tr[p].ch[0], r = tr[p].ch[1];
    tr[p].sz = tr[l].sz + tr[r].sz + 1;
    tr[p].mx = max({tr[l].mx, tr[r].mx, tr[p].val});
}

pair<int, int> split(int p, long long key) {
    if (!p) {
        return {0, 0};
    } else if (key >= tr[p].key) {
        auto [l, r] = split(tr[p].ch[1], key);
        tr[p].ch[1] = l;
        pull(p);
        return {p, r};
    } else {
        auto [l, r] = split(tr[p].ch[0], key);
        tr[p].ch[0] = r;
        pull(p);
        return {l, p};
    }
}

int merge(int l, int r) {
    if (!l || !r) {
        return l ? l : r;
    } else if (rng() % (tr[l].sz + tr[r].sz) < tr[l].sz) {
        tr[l].ch[1] = merge(tr[l].ch[1], r);
        pull(l);
        return l;
    } else {
        tr[r].ch[0] = merge(l, tr[r].ch[0]);
        pull(r);
        return r;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, v;
    cin >> n >> v;
    vector<int> t(n), a(n);
    for (int &x : t)
        cin >> x;
    for (int &x : a)
        cin >> x;

    vector<int> dp(n);
    for (int i=0; i<n; i++) {
        if ((abs(a[i]) + v - 1) / v <= t[i])
            dp[i] = 1;
        else
            dp[i] = -1e9;
    }

    auto solve = [&] (auto &self, int l, int r) -> void {
        if (l == r)
            return;
        int m = (l + r) / 2;
        self(self, l, m);
        vector<pair<long long, int>> left, right;
        for (int i=l; i<=m; i++)
            left.emplace_back(a[i] - (long long) t[i] * v, i);
        for (int i=m+1; i<=r; i++)
            right.emplace_back(a[i] - (long long) t[i] * v, i);
        sort(left.rbegin(), left.rend());
        sort(right.rbegin(), right.rend());
        id = 1;
        int rt = 0;
        for (int i=0, j=0; i<(int)right.size(); i++) {
            while (j < (int) left.size() && left[j].first >= right[i].first) {
                int k = left[j++].second, p = newNode(a[k] + (long long) t[k] * v, dp[k]);
                auto [x, y] = split(rt, a[k] + (long long) t[k] * v);
                rt = merge(merge(x, p), y);
            }
            int k = right[i].second;
            auto [x, y] = split(rt, a[k] + (long long) t[k] * v);
            dp[k] = max(dp[k], tr[x].mx + 1);
            rt = merge(x, y);
        }
        self(self, m + 1, r);
    };

    solve(solve, 0, n - 1);
    cout << max(*max_element(dp.begin(), dp.end()), 0) << "\n";

    return 0;
}