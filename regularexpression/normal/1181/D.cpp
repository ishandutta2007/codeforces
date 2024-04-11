#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e5 + 17, INF = 1e18 + 17;

int t[4 * N];

void add(int v, int tl, int tr, int pos) {
    if (tr - tl == 1) t[v] = 1; else {
        int tm = (tl + tr) / 2;
        if (pos < tm) add(2 * v, tl, tm, pos); else add(2 * v + 1, tm, tr, pos);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}

int find_kth(int v, int tl, int tr, int k) {
    if (t[v] < k) return -1;
    if (tr - tl == 1) return tl;
    int tm = (tl + tr) / 2;
    int res = find_kth(2 *  v, tl, tm, k);
    if (res == -1) res = find_kth(2 * v + 1, tm, tr, k - t[2 * v]);
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
    }
    vector <pair <int, int>> cnt(m);
    for (int i = 0; i < m; ++i) cnt[i] = {0, i};
    for (auto i : a) cnt[i].first++;
    int sum = n * m;
    for (auto i : cnt) {
        sum -= i.first;
    }
    sort(cnt.begin(), cnt.end());
    vector <pair <int, int>> query(q);
    for (int i = 0; i < q; ++i) {
        cin >> query[i].first;
        --query[i].first;
        query[i].first -= n;
        query[i].second = i;
    }
    vector <int> ans(q);
    sort(query.begin(), query.end());
    int cur = 0, pos = 0;
    for (int i = 0; i < n; ++i) {
        while (pos < m && cnt[pos].first <= i) {
            add(1, 0, N, cnt[pos].second);
            ++pos;
        }
        int ind = lower_bound(query.begin(), query.end(), make_pair(cur, -INF)) - query.begin();
        for (int j = ind; j < q && query[j].first < cur + pos; ++j) {
            int val = query[j].first - cur + 1;
            ans[query[j].second] = find_kth(1, 0, N, val) + 1;
        }
        cur += pos;
    }
    for (int j = 0; j < q; ++j) {
        if (query[j].first >= cur) {
            ans[query[j].second] = (query[j].first - cur) % m + 1;
        }
    }
    for (auto i : ans) cout << i << endl;
    return 0;
}