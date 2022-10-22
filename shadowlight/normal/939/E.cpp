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
    ll q;
    cin >> q;
    double res = 0;
    vector <double> a, pref;
    cout.precision(20);
    for (ll i = 0; i < q; i++) {
        ll tp;
        cin >> tp;
        if (tp == 1) {
            ll x;
            cin >> x;
            ll l = 0, r = (ll) a.size() - 1;
            while (r - l > 2) {
                ll m1 = l + (r - l) / 3;
                ll m2 = l + 2 * (r - l) / 3;
                if ((pref[m1] + x) / (m1 + 2) > (pref[m2] + x) / (m2 + 2)) {
                    l = m1;
                } else {
                    r = m2;
                }
            }
            //cout << l << " " << r << "\n";
            for (ll j = l; j <= r; j++) {
                res = max(res, x - (pref[j] + x) / (j + 2));
            }
            a.push_back(x);
            if (!pref.size()) {
                pref.push_back(x);
            } else {
                pref.push_back(x + pref.back());
            }
        } else {
            cout << res << "\n";
        }
    }
}