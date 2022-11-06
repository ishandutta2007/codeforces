#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, d, m;
    cin >> n >> d >> m;
    vector<int> a, b;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        if (val <= m) a.push_back(val); else b.push_back(val);
    }
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    int cnt_a = a.size(), cnt_b = b.size();
    vector<int> pa(cnt_a + 1, 0);
    for (int i = 0; i < cnt_a; ++i) pa[i + 1] = pa[i] + a[i];
    vector<int> pb(cnt_b + 1, 0);
    for (int i = 0; i < cnt_b; ++i) pb[i + 1] = pb[i] + b[i];
    int ans = 0;
    for (int i = 0; i <= cnt_b; ++i) {
        int need = max(0LL, i - 1) * d;
        if (need > n - i) continue;
        int j = min(cnt_a, cnt_a - need + cnt_b - i);
        ans = max(ans, pa[j] + pb[i]);
    }
    cout << ans;
    return 0;
}