#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const ll INF = 2e18 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-6;

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
    ll n, b;
    cin >> n >> b;
    vector <pair <ll, ll> > t;
    ll res = INF;
    for (ll i = 2; i < MAXN; i++) {
        ll cnt = 0;
        while (b % i == 0) {
            cnt++;
            b /= i;
        }
        if (cnt) {
            ll now = 0;
            ll x = i;
            while (true) {
                now += n / x;
                if (x > n / i) break;
                x *= i;
            }
            res = min(res, now / cnt);
        }
    }
    if (b != 1) {
        ll now = 0;
        ll x = b;
        while (x <= n) {
            now += n / x;
            if (x > n / b) break;
            x *= b;
        }
        res = min(res, now);
    }
    cout << res;
}