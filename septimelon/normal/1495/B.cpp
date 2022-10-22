#include <bits/stdc++.h>

//#pragma GCC optimize("O3")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 1000000007;
const ld EPS = 1e-11;
const ll INFL = 1e18;
const int INF = 1e9 + 7;
const ld PI = acos(-1);
const ld E = exp(1);

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    vector<int> lmin(n), rmin(n);
    int maxm = 0;
    lmin[0] = 0;
    int nma = 1;
    for (int i = 1; i < n; ++i) {
        if (p[i] < p[i - 1]) {
            lmin[i] = 0;
        } else {
            lmin[i] = lmin[i - 1] + 1;
        }
        if (lmin[i] > maxm) {
            nma = 1;
        }
        if (lmin[i] == maxm) {
            ++nma;
        }
        maxm = max(maxm, lmin[i]);
    }
    rmin[n - 1] = 0;
    for (int i = n - 2; i >= 0; --i) {
        if (p[i] < p[i + 1]) {
            rmin[i] = 0;
        } else {
            rmin[i] = rmin[i + 1] + 1;
        }
        if (rmin[i] > maxm) {
            nma = 1;
        }
        if (rmin[i] == maxm) {
            ++nma;
        }
        maxm = max(maxm, rmin[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int mid = min(rmin[i], lmin[i]);
        int mad = max(rmin[i], lmin[i]);
        if (mad == mid && mad % 2 == 0 && mid > 0 && mad == maxm && nma == 2) {
            ++ans;
        }
    }

    cout << ans << "\n";

    return 0;
}