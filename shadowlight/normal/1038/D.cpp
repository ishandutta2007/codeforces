#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e18 + 7;
const int MAXN = 1e6 + 7;
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
    ll n;
    cin >> n;
    vector <ll> a(n);
    vector <ll> pref(n), suf(n);
    ll sum = 0;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        sum += abs(a[i]);
    }
    pref[0] = -abs(a[0]) - a[0];
    for (ll i = 1; i < n; i++) {
        pref[i] = max(pref[i - 1], -abs(a[i]) - a[i]);
    }
    suf[n - 1] = -abs(a[n - 1]) - a[n - 1];
    for (ll i = n - 2; i >= 0; i--) {
        suf[i] = max(suf[i + 1], -abs(a[i]) - a[i]);
    }
    if (n == 1) {
        cout << a[0];
        return 0;
    }
    ll maxk = sum - abs(a[0]) + a[0] + suf[1];
    maxk = max(maxk, sum - abs(a[n - 1]) + a[n - 1] + pref[n - 2]);
    for (ll i = 1; i < n - 1; i++) {
        ll now = sum - abs(a[i]) + a[i];
        maxk = max(maxk, now + pref[i - 1] + suf[i + 1]);
    }
    cout << maxk;
}