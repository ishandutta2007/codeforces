#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;
const int M = 998244353;
const int N = 200007;
const int K = 55;
ld dp[N][K];

struct line {
    ld k, b;
};

struct point {
    ld x, y;
};

point intersec(line w1, line w2) {
    ld k1 = w1.k, b1 = w1.b;
    ld k2 = w2.k, b2 = w2.b;
    ld x = (b2 - b1) / (k1 - k2);
    ld y = k1 * x + b1;
    point ans;
    ans.x = x;
    ans.y = y;
    return ans;
}

vector<line> s[K];

void add_line(line p, int i) {
    while (s[i].size() >= 2) {
        ld x1 = intersec(s[i][s[i].size() - 2], s[i][s[i].size() - 1]).x;
        ld x2 = intersec(s[i][s[i].size() - 2], p).x;
        if (x1 >= x2) {
            s[i].pop_back();
        } else {
            break;
        }
    }
    s[i].pb(p);
}

ld my_lower_bound(ld h, int i) {
    int left = 0;
    int right = (int) s[i].size();
    while (right - left > 1) {
        int mid = (left + right) / 2;
        point lol = intersec(s[i][mid - 1], s[i][mid]);
        if (lol.x >= h) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return h * s[i][left].k + s[i][left].b;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> T(n + 1);
    for (int i = 1; i <= n; i++) cin >> T[i];
    vector<int> P(n + 1);
    for (int i = 1; i <= n; i++) {
        P[i] = P[i - 1] + T[i];
    }
    vector<ld> X(n + 1);
    for (int i = 1; i <= n; i++) {
        X[i] = 1.0 * P[i] / T[i];
    }
    vector<ld> PX(n + 1);
    for (int i = 1; i <= n; i++) {
        PX[i] = PX[i - 1] + X[i];
    }
    vector<ld> INVT(n + 1);
    for (int i = 1; i <= n; i++) {
        INVT[i] = 1.0 / T[i];
    }
    vector<ld> PINVT(n + 1);
    for (int i = 1; i <= n; i++) {
        PINVT[i] = PINVT[i - 1] + INVT[i];
    }
    line d;
    d.k = 0;
    d.b = 0;
    add_line(d, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = min(i, k); j >= 1; j--) {
            dp[i][j] = PX[i];
            dp[i][j] += my_lower_bound(PINVT[i], j - 1);
            line d;
            d.k = -P[i];
            d.b = dp[i][j] + PINVT[i] * P[i] - PX[i];
            add_line(d, j);
        }
    }
    cout << fixed << setprecision(20) << dp[n][k] << '\n';
}