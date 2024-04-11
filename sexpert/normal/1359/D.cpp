#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 1e9;

ll solve(vector<ll> &v) {
    ll pv = 0, res = -INF;
    for(auto &x : v) {
        res = max(res, pv + x);
        pv = max(pv + x, x);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<ll> u(n), v(n, -INF);
    for(auto &x : u)
        cin >> x;
    ll ans = 0;
    for(int mx = -30; mx <= 30; mx++) {
        for(int i = 0; i < n; i++) {
            if(u[i] == mx)
                v[i] = mx;
        }
        ans = max(ans, solve(v) - mx);
    }
    cout << ans << endl;
}