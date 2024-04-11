#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //  freopen("output.txt", "w", stdout);
    #endif
    ll n;
    cin >> n;
    vector <ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector <ll> pref(n + 1, 0), kpref(n + 1, 0);
    for (ll i = 0; i < n - 1; i++) {
        pref[i + 1] = pref[i];
        kpref[i + 1] = kpref[i];
        if (i % 2) {
            pref[i + 1] += abs(a[i + 1] - a[i]) * -1;
            kpref[i + 1] += abs(a[i + 1] - a[i]);
        } else {
            pref[i + 1] += abs(a[i + 1] - a[i]);
            kpref[i + 1] += abs(a[i + 1] - a[i]) * -1;
        }
        //cout << pref[i + 1] << " ";
    }
   // cout << endl;
    ll mink = 0, kmink = 0;
    ll ans = 0;
    for (ll i = 1; i < n; i++) {
        ans = max(ans, pref[i] - mink);
        ans = max(ans, kpref[i] - kmink);
        mink = min(mink, pref[i]);
        kmink = min(kmink, kpref[i]);
    }
    cout << ans;
}