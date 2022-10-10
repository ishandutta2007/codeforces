#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll ans(vector<int> &v, int bnd) {
    ll res = 0;
    int n = v.size();
    int pl = n - 1;
    for(int i = 1; i < n; i++) {
        while(pl && v[pl] + v[i] > bnd)
            pl--;
        if(v[pl] + v[i] <= bnd)
            res += min(pl + 1, i);
    }
    return res;
}

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
    sort(v.begin(), v.end());
    cout << ans(v, r) - ans(v, l - 1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}