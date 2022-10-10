#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n), df(n);
    ll ans, cur = 0;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        df[i] = v[i] - (n - i - 1);
        cur += v[i];
    }
    ans = cur;
    sort(df.rbegin(), df.rend());
    for(int i = 0; i < k; i++) {
        cur -= df[i];
        cur -= i;
        ans = min(ans, cur);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}