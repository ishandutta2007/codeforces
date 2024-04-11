#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    ll n, T, a, b;
    cin >> n >> T >> a >> b;
    ll ce = 0, ch = 0, re = 0, rh = 0;
    vector<ll> v(n);
    for(auto &x : v) {
        cin >> x;
        ch += x;
        ce += (1 - x);
    }
    vector<ii> owo;
    vector<ll> times;
    for(int i = 0; i < n; i++) {
        ll t;
        cin >> t;
        owo.push_back({t, v[i]});
        times.push_back(t);
    }
    sort(owo.begin(), owo.end());
    times.push_back(T + 1);
    sort(times.begin(), times.end());
    times.erase(unique(times.begin(), times.end()), times.end());
    ll ans = 0;
    int p = 0;
    for(auto t : times) {
        //cout << "owo " << t << " " << re << " " << rh;
        ll remT = t - 1 - re * a - rh * b;
        ll tot = re + rh;
        ll ne = ce - re, nh = ch - rh;
        while(p < n && owo[p].first == t) {
            rh += owo[p].second;
            re += (1 - owo[p].second);
            p++;
        }
        if(remT < 0) {
            //cout << " nyaa~\n";
            continue;
        }
        int cn = min(ne, remT / a);
        tot += cn;
        remT -= cn * a;
        cn = min(nh, remT / b);
        tot += cn;
        //cout << " " << tot << '\n';
        ans = max(ans, tot);
    }
    //cout << endl;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m;
    cin >> m;
    while(m--)
        solve();
}