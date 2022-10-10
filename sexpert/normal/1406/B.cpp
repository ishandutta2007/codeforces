#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), ps, ng;
    for(auto &x : a) {
        cin >> x;
        if(x >= 0)
            ps.push_back(x);
        else
            ng.push_back(x);
    }
    sort(ps.rbegin(), ps.rend());
    sort(ng.begin(), ng.end());
    vector<ll> op = ps, on = ng;
    reverse(op.begin(), op.end());
    reverse(on.begin(), on.end());
    ll ans = LLONG_MIN;
    for(int t_p = 0; t_p <= 5; t_p++) {
        int t_n = 5 - t_p;
        if(t_p > ps.size() || t_n > ng.size())
            continue;
        ll tot = 1;
        if(t_n % 2) {
            for(int i = 0; i < t_p; i++)
                tot *= op[i];
            for(int i = 0; i < t_n; i++)
                tot *= on[i];
        }
        else {
            for(int i = 0; i < t_p; i++)
                tot *= ps[i];
            for(int i = 0; i < t_n; i++)
                tot *= ng[i];
        }
        ans = max(ans, tot);
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