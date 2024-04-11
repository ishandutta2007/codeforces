#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

ll C(ll n, ll k) {
    ll res = 1;
    for (ll i = n; i > n - k; i--) {
        res *= i;
    }
    for (ll i = 1; i <= k; i++) {
        res /= i;
    }
    return res;
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
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    vector <ll> coef = {1, 0, 1, 2, 9};
    for (ll i = 0; i <= k; i++) {
        ans += C(n, i) * coef[i];
    }
    cout << ans;
}