#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

ll go(ll l, ll r, const vector<ll> &pos, ll a, ll b) {
    if (pos.empty()) return a;
    if (l + 1 == r) return b * (ll)pos.size();
    ll m = (l + r) / 2;
    vector<ll> posl, posr;
    for (const ll &p : pos) {
        if (p < m) posl.push_back(p);
        else posr.push_back(p);
    }

    return min(b * (ll)pos.size() * (r - l), go(l, m, posl, a, b) + go(m, r, posr, a, b));
}

void solve() {
    ll n, k, a, b;
    cin >> n >> k >> a >> b;
    vector<ll> pos(k);
    for (ll &x : pos) {
        cin >> x;
        x--;
    }
    sort(all(pos));

    cout << go(0, (1ll << n), pos, a, b) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
#ifdef MADE_BY_SERT
    int T = 2;
    for (int i = 1; i < T; i++) solve();    
#endif
}