#include <bits/stdc++.h>
using namespace std;

#define N 200100

int n, m, x[N], l[N], r[N], h[N];
vector <int> add[N], del[N];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        scanf("%d %d %d", &h[i], &l[i], &r[i]);
        x[m++] = l[i], x[m++] = r[i];
    }
    sort(x, x + m); m = unique(x, x + m) - x;
    for (int i = 0; i < n; i ++) {
        l[i] = lower_bound(x, x + m, l[i]) - x;
        r[i] = lower_bound(x, x + m, r[i]) - x;
        add[l[i]].push_back(h[i]);
        del[r[i]].push_back(h[i]);
    }
    int c = 0; multiset <int> S; S.insert(0);
    typedef pair <int, int> pii;
    vector <pii> ans;
    for (int i = 0; i < m; i ++) {
        for (auto x : add[i]) S.insert(x);
        for (auto x : del[i]) S.erase(S.find(x));
        int d = *(--S.end());
        if (c == d) continue;
        ans.emplace_back(x[i], c), ans.emplace_back(x[i], d);
        c = d;
    }
    int sz = ans.size();
    printf("%d\n", sz);
    for (int i = 0; i < sz; i ++) printf("%d %d\n", ans[i].first, ans[i].second);

    return 0;
}