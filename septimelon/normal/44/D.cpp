#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MOD = 998244353;
const int MAX = 998244353;

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

ld dist(ld x1, ld y1, ld z1, ld x2, ld y2, ld z2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> ix(n), iy(n), iz(n);
    vector<ld> x(n), y(n), z(n);
    for (int i = 0; i < n; ++i) {
        cin >> ix[i] >> iy[i] >> iz[i];
        x[i] = ix[i];
        y[i] = iy[i];
        z[i] = iz[i];
    }
    
    ld ans = 0. + MAX;
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ld cd = dist(x[i], y[i], z[i], x[j], y[j], z[j]);
            cd += dist(x[0], y[0], z[0], x[j], y[j], z[j]);
            cd += dist(x[i], y[i], z[i], x[0], y[0], z[0]);
            cd /= 2;
            ans = min(ans, cd);
        }
    }
    
    cout << setprecision(10) << ans << "\n";
    
    return 0;
}