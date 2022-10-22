#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

ll n;

ll get_cnt(ll x) {
    if (x <= n) {
        return (x - 1) / 2;
    }
    ll k = x - n;
    return (n - k + 1) / 2;
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    cin >> n;
    ll x = 2 * n - 1;
    ll cnt = 0, last = -1;
    while (x) {
        last = x;
        cnt++;
        x /= 10;
    }
    ll res = 1;
    for (ll i = 0; i < cnt - 1; i++) {
        res *= 10;
    }
    if (10 * res == 2 * n) {
        cout << get_cnt(2 * n - 1);
        return 0;
    }
    if ((last + 1) * res == 2 * n) {
        last++;
    }
    //cout << last << "\n";
    ll ans = 0;
    for (ll i = 0; i < last; i++) {
        ll x = (i + 1) * res - 1;
        ans += get_cnt(x);
    }
    cout << ans;
}