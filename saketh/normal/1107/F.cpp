#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    vector<array<int, 3>> offer(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++)
            cin >> offer[i][j];
    }

    sort(all(offer), [](auto& a, auto& b) {
        return a[1] > b[1];
    });

    vvll dp(N + 1, vll(N + 1));
    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j <= N; j++) {
            dp[i][j] = max({ offer[i][0] - ll(j) * offer[i][1] + dp[i + 1][j + 1],
                             offer[i][0] - ll(offer[i][2]) * offer[i][1] + dp[i + 1][j],
                             dp[i + 1][j] });
        }
    }
    cout << dp[0][0] << endl;

    return 0;
}