#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = (ll)1e18;

ll f, T, t0;
ll a1, t1, p1, a2, t2, p2;

int main() {
    cin >> f >> T >> t0;
    cin >> a1 >> t1 >> p1;
    cin >> a2 >> t2 >> p2;

    ll res = INF;
    for(int swapped = 0; swapped < 2; swapped++) {
        if(swapped) {
            swap(a1, a2);
            swap(t1, t2);
            swap(p1, p2);
        }
        for(ll c1 = 0; c1 * a1 <= f + a1; c1++) {
            ll rem_f = max(0LL, f - c1 * a1);
            if(t1 * min(a1 * c1, f) + min(t2, t0) * rem_f > T) continue;
            if(t2 >= t0) {
                res = min(res, c1 * p1);
            }
            else {
                res = min(res, c1 * p1 + (rem_f + a2 - 1) / a2 * p2);
                ll over_t = max(0LL, rem_f * t0 + t1 * (f - rem_f) - T);
                ll mn_c2 = (over_t + a2 * (t0 - t2) - 1) / ((t0 - t2) * a2);
                if(mn_c2 * a2 <= rem_f) {
                    res = min(res, c1 * p1 + mn_c2 * p2);
                }
            }
        }
    }
    cout << (res == INF ? -1 : res) << '\n';
}