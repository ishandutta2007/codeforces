#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<ll> ct(n + 1);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ct[x]++;
    }
    sort(ct.rbegin(), ct.rend());
    ll ans = 0, cur = n + 1;
    for(int i = 0; i < n + 1; i++) {
        ll take = min(ct[i], cur - 1);
        if(take < 0)
            take = 0;
        ans += take;
        cur = take;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while(q--)
        solve();
}