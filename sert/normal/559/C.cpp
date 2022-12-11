#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll md = 1e9 + 7;
const ll o5 = 716327852;
const int N = 2e5 + 34;

ll f[N], o[N];
ll ans, n, w, h;
ll dp[N];
pair <ll, ll> a[N];

ll c(ll h, ll w) {
    return (((f[h + w] * o[h]) % md) * o[w]) % md;
}


int main() {
    //freopen("a.in", "r", stdin);

    o[0] = f[0] = 1;
    o[100000] = o5;
    for (ll i = 1; i < N; i++)
        f[i] = (f[i - 1] * i) % md;
    for (ll i = 99999; i > 0; i--)
        o[i] = (o[i + 1] * (i + 1)) % md;

    cin >> h >> w >> n;
    ans = c(h - 1, w - 1);

    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        a[i].first--;
        a[i].second--;
    }

    sort(a, a + n);

    for (int i = 0; i < n; i++) {
        dp[i] = c(a[i].second, a[i].first);
        for (int j = 0; j < i; j++)
            if (a[j].first <= a[i].first && a[j].second <= a[i].second)
                dp[i] = (dp[i] - dp[j] * c(a[i].first - a[j].first, a[i].second - a[j].second) + md * md) % md;
        ans = (ans + md * md - dp[i] * c(w - a[i].second - 1, h - a[i].first - 1)) % md;
    }

    cout << ans;



}