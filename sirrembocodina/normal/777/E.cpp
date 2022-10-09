#include <bits/stdc++.h>

using namespace std;

#define int int64_t

struct ring {
    int a, b, h;
};

bool cmp(const ring& x, const ring& y) {
    if (x.b != y.b) {
        return x.b > y.b;
    }
    return x.a > y.a;
}

bool cmp2(const ring& x, int a) {
    return x.b > a;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<ring> r(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i].a >> r[i].b >> r[i].h;
    }
    sort(r.begin(), r.end(), cmp);
    multiset<int> cand;
    cand.insert(0);
    vector<vector<int>> del(n + 1);
    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
        for (int x: del[i]) {
            cand.erase(cand.find(x));
        }
        dp[i] = *--cand.end() + r[i].h;
        cand.insert(dp[i]);
        del[lower_bound(r.begin(), r.end(), r[i].a, cmp2) - r.begin()].push_back(dp[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans;
}