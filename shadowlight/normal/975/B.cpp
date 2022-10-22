#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 1e6 + 7;
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
    vector <ll> a(14);
    for (ll i = 0; i < 14; i++) {
        cin >> a[i];
    }
    ll res = 0;
    for (ll i = 0; i < 14; i++) {
        ll x = a[i];
        auto b = a;
        b[i] = 0;
        for (ll j = 0; j < 14; j++) {
            b[j] += x / 14;
        }
        for (ll j = 0; j < x % 14; j++) {
            b[(j + i + 1) % 14]++;
        }
        ll now = 0;
        for (ll j = 0; j < 14; j++) {
            if (b[j] % 2 == 0) {
                now += b[j];
            }
        }
        res = max(res, now);
    }
    cout << res;
}