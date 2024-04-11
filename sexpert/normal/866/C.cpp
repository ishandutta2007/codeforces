#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const double inf = 1e9;
int n, R;
int F[105], S[105];
double P[105], dp[55][5005];

bool check(double cost) {
    for(int i = 0; i <= n; i++) {
        for(int tot = 0; tot <= R; tot++) {
            dp[i][tot] = (i == n ? 0.0 : inf);
        }
    }
    for(int en = R; en >= 0; en--) {
        for(int i = 0; i <= n - 1; i++) {
            dp[i][en] = min(cost, P[i] * (F[i] + ((en + F[i]) <= R ? dp[i + 1][en + F[i]] : cost)) + (1.0 - P[i]) * (S[i] + ((en + S[i]) <= R ? dp[i + 1][en + S[i]] : cost)));
        }
    }
    double res = P[0] * (F[0] + dp[1][F[0]]) + (1.0 - P[0]) * (S[0] + (S[0] > R ? cost : dp[1][S[0]]));
    return res < cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> R;
    for(int i = 0; i < n; i++) {
        cin >> F[i] >> S[i] >> P[i];
        P[i] /= 100.0;
    }
    double lo = 0.0, hi = inf;
    for(int i = 0; i < 200; i++) {
        double mi = (lo + hi) * 0.5;
        if(check(mi))
            hi = mi;
        else
            lo = mi;
    }
    cout << fixed << setprecision(9) << lo << '\n';
}