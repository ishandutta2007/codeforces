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
    vector <ll> d(MAXN, -1);
    vector <ll> p;
    for (ll i = 2; i < MAXN; i++) {
        if (d[i] == -1) {
            p.push_back(i);
            d[i] = p.size() - 1;
        }
        for (ll j = 0; j <= d[i]; j++) {
            if (i * p[j] >= MAXN) break;
            d[i * p[j]] = j;
        }
    }
    ll x;
    cin >> x;
    vector <ll> fact;
    ll y = x;
    while (x != 1) {
        fact.push_back(p[d[x]]);
        x /= p[d[x]];
    }
    x = y;
    ll s = x / fact.back();
    if (s % fact.back() == 0) {
        s++;
    }
    ll val = max(fact.back() + 1, s);
    ll res = INF;
    for (ll i = 4; i <= x; i++) {
        ll a = i;
        vector <ll> fact1;
        while (a != 1) {
            fact1.push_back(p[d[a]]);
            a /= p[d[a]];
        }
        bool can = false;
        for (ll pk : fact) {
            ll now = i;
            if (i % pk) {
                now += pk - i % pk;
            }
            if (now == x) {
                can = true;
                break;
            }
        }
        if (!can) continue;
        if (fact1.size() == 1) continue;
        for (ll pk : fact1) {
            ll b = i - pk + 1;
            res = min(res, b);
        }
    }
    cout << res;
}