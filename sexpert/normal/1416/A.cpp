#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n), mn(n + 1, 0), ans(n + 2, n + 1), pv(n + 1, -1);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        //cout << v[i] << " " << pv[v[i]] << " " << i << endl;
        mn[v[i]] = max(mn[v[i]], i - pv[v[i]]);
        pv[v[i]] = i;
    }
    for(int i = n; i >= 1; i--) {
        mn[i] = max(mn[i], n - pv[i]);
        //cout << i << " " << mn[i] << endl;
        ans[mn[i]] = min(ans[mn[i]], i);
    }
    int cur = n + 1;
    for(int i = 1; i <= n; i++) {
        if(ans[i] != -1)
            cur = min(cur, ans[i]);
        cout << (cur == n + 1 ? -1 : cur) << " ";
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}