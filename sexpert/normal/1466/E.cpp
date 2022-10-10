#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 5e5 + 10;
const ll MOD = 1e9 + 7;
ll S[MAXN], T[MAXN], vs[100];

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n), cnt(62);
    for(auto &x : v) {
        cin >> x;
        for(ll b = 0; b < 62; b++) {
            if(x & (1LL << b))
                cnt[b]++;
        }
    }
    for(int j = 0; j < n; j++) {
        S[j] = T[j] = 0;
        for(ll b = 0; b < 62; b++) {
            if(v[j] & (1LL << b)) {
                S[j] = (S[j] + n * vs[b]) % MOD;
                T[j] = (T[j] + cnt[b]*vs[b]) % MOD;
            }
            else
                S[j] = (S[j] + cnt[b] * vs[b]) % MOD;
        }
    }
    /*for(int i = 0; i < n; i++)
        cout << S[i] << " ";
    cout << '\n';
    for(int i = 0; i < n; i++)
        cout << T[i] << " ";
    cout << '\n';*/
    ll ans = 0;
    for(int i = 0; i < n; i++)
        ans = (ans + S[i] * T[i]) % MOD;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(ll b = 0; b < 62; b++)
        vs[b] = (1LL << b) % MOD;
    int t;
    cin >> t;
    while(t--)
        solve();
}