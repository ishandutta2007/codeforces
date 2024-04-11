#include <algorithm>
#include <cmath>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INFL = 1e18;
const int INF = 1000000007;
const ld PI = acos(-1);
const ld EPS = 1e-13;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> d(n);
    cin >> a[0];
    d[0] = a[0];
    for (int i = 1; i < n; ++i) {
        cin >> a[i];
        d[i] = a[i] - a[i - 1];
    }

    int q;
    cin >> q;
    vector<ll> ql(q), qr(q), qx(q);
    for (int i = 0; i < q; ++i) {
        cin >> ql[i] >> qr[i] >> qx[i];
        --ql[i];
        --qr[i];
    }

    ll sum = d[0];
    for (int i = 1; i < n; ++i) {
        if (d[i] > 0LL) {
            sum += d[i];
        }
    }
    cout << (sum + 1LL + 200000000000000000LL) / 2LL - 100000000000000000LL << "\n";

    for (int it = 0; it < q; ++it) {
        ll l = ql[it], r = qr[it], x = qx[it];
        //cout << l << " " << r << ": " << x << "\n";
        
        if (l == 0LL) {
            sum += x;
        }
        else {
            if (d[l] > 0LL) {
                sum -= d[l];
            }
            d[l] += x;
            if (d[l] > 0LL) {
                sum += d[l];
            }
        }

        if (r < n - 1) {
            if (d[r + 1] > 0LL) {
                sum -= d[r + 1];
            }
            d[r + 1] -= x;
            if (d[r + 1] > 0LL) {
                sum += d[r + 1];
            }
        }

        cout << (sum + 1LL + 200000000000000000LL) / 2LL - 100000000000000000LL << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    int t = 1;
    //cin >> t;
    for (int q = 0; q < t; ++q) {
        solve();
    }

    return 0;
}