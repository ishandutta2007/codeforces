#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, m, k, ans = 0, rmd = 0;
    cin >> n >> m >> k;
    vector<ll> v(m);
    for(auto &x : v) cin >> x;
    reverse(v.begin(), v.end());
    while(!v.empty()) {
        ans++;
        ll t = (v.back() - rmd)/k;
        while(v.back() > k*t + rmd) t++;
        ll tp = 0, bnd = k*t + rmd;
        while(v.size() && v.back() <= bnd) {
            tp++;
            v.pop_back();
        }
        rmd += tp;
    }
    cout << ans << '\n';
}