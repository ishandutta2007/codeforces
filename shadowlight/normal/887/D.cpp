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
    ll n, a, b, c, d, start, len;
    cin >> n >> a >> b >> c >> d >> start >> len;
    vector <ll> t(n), tp(n);
    for (ll i = 0; i < n; i++) {
        cin >> t[i] >> tp[i];
    }
    vector <ll> pref(n + 1, 0);
    pref[0] = start;
    for (ll i = 1; i <= n; i++) {
        pref[i] = pref[i - 1];
        if (tp[i - 1]) {
            pref[i] += a;
        } else {
            pref[i] -= b;
        }
    }
    ll r = -1;
    ll sum = 0;
    for (ll l = 0; l < n; l++) {
        if (pref[l] < 0) {
            cout << -1;
            return 0;
        }
        ll p;
        if (l) {
            if (tp[l - 1]) {
                sum -= c;
            } else {
                sum += d;
            }
            p = t[l - 1] + 1;
        } else {
            p = 0;
        }
        if (p + len <= t[l]) {
            cout << p;
            return 0;
        }
        if (r == l - 1) {
            r++;
            if (tp[r]) {
                sum += c;
            } else {
                sum -= d;
            }
        }
        bool fl = false;
        if (sum + pref[l] < 0) {
            //cout << l << " " << r << " " << sum << " " << pref[l] << "\n";
            continue;
        }
        while (r < n - 1 && p + len > t[r + 1]) {
            r++;
            if (tp[r]) {
                sum += c;
            } else {
                sum -= d;
            }
            if (sum + pref[l] < 0) {
                fl = true;
                break;
            }
        }
        //cout << l << " " << r << " " << sum << " " << pref[l] << "\n";
        if (!fl) {
            cout << max(t[r] - len, p);
            return 0;
        }
    }
    if (pref[n] < 0) {
        cout << -1;
        return 0;
    }
    cout << t[n - 1] + 1;
}