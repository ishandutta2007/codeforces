#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const ll MOD = 998244353;
const int MAXN = 3e5 + 5;
ll fac[MAXN], fct[MAXN], sct[MAXN];
map<ii, ll> pct;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fac[0] = 1;
    for(ll i = 1; i < MAXN; i++)
        fac[i] = (i * fac[i - 1]) % MOD;

    int n;
    cin >> n;
    vector<int> fst, snd;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        fct[x]++;
        sct[y]++;
        pct[{x, y}]++;
        fst.push_back(x);
        snd.push_back(y);
    }
    ll fix1 = 1, fix2 = 1;
    for(int i = 1; i <= n; i++) {
        fix1 = (fix1 * fac[fct[i]]) % MOD;
        fix2 = (fix2 * fac[sct[i]]) % MOD;
    }
    sort(fst.rbegin(), fst.rend());
    sort(snd.rbegin(), snd.rend());
    ll ex = 1;
    for(int i = 0; i < n; i++) {
        ll choices = pct[{fst.back(), snd.back()}];
        ex = (ex * choices) % MOD;
        pct[{fst.back(), snd.back()}]--;
        fst.pop_back();
        snd.pop_back();
    }
    ll ans = (fix1 + fix2 - ex) % MOD;
    ans = (fac[n] - ans) % MOD;
    if(ans < 0)
        ans += MOD;
    cout << ans << '\n';
}