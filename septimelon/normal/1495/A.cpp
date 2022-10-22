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

void solve() {
    int n;
    cin >> n;
    vector<double> x, y;
    for (int i = 0; i < 2 * n; ++i) {
        int a, b;
        cin >> a >> b;
        if (a == 0) {
           x.push_back(abs(b));
        } else {
            y.push_back(abs(a));
        }
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    ld ans = 0;
    for (int i = 0; i < n; ++i) {
        //cout << x[i] << "_" << y[i] << "\n";
        ans += sqrt(x[i] * x[i] + y[i] * y[i]);
    }

    cout << setprecision(13) << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        solve();
    }

    return 0;
}