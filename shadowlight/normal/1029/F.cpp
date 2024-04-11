#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e18 + 7;
const ll N = 2e7 + 7;
const double EPS = 1e-8;

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
    ll a, b;
    cin >> a >> b;
    vector <ll> ad, bd;
    for (ll i = 1; i < N; i++) {
        if (a % i == 0) {
            ad.push_back(i);
        }
        if (b % i == 0) {
            bd.push_back(i);
        }
    }
    ll res = INF;
    ll la = -1, lb = -1;
    for (ll i = 1; i < N; i++) {
        if ((a + b) % i) {
            continue;
        }
        ll x = (a + b) / i;
        //cout << i << " " << (a + b) / i << "\n";
        while (la + 1 < ad.size() && ad[la + 1] <= i) {
            la++;
        }
        while (lb + 1 < bd.size() && bd[lb + 1] <= i) {
            lb++;
        }
        bool can = false;
        if (la > -1 && a / ad[la] <= x) {
            can = true;
        }
        if (lb > -1 && b / bd[lb] <= x) {
            can = true;
        }
        if (can) {
            res = min(res, 2 * (i + x));
        }
    }
    cout << res;
}