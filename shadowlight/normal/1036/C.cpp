#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

ll calc(ll r) {
    ll st = 1;
    ll cnt = 0;
    for (ll len = 1; ; len++) {
        if (st <= r / 10) {
            cnt += 9 + 81 * (len - 1) + 729 * (len - 1) * (len - 2) / 2;
            st = st * 10LL;
            continue;
        }
        ll d = r / st;
        //cout << r << " " << st << " " << d << "\n";
        cnt += d + 9 * (d - 1) * (len - 1) + 81 * (d - 1) * (len - 1) * (len - 2) / 2;
        r -= d * st;
        while (st > r) {
            st /= 10LL;
            len--;
        }
        if (!st) {
            break;
        }
        cnt += 9 * (len - 1) + 81 * (len - 1) * (len - 2) / 2;
        d = r / st;
        cnt += d + 9 * (d - 1) * (len - 1);
        r -= d * st;
        while (st > r) {
            st /= 10LL;
            len--;
        }
        if (!st) {
            break;
        }
        d = r / st;
        if (!d) break;
        cnt += d;
        cnt += 9 * (len - 1);
        break;
    }
    return cnt;
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
    ll t;
    cin >> t;
    for (ll i = 0; i < t; i++) {
        ll l, r;
        cin >> l >> r;
        cout << calc(r) - calc(l - 1) << "\n";
    }
}