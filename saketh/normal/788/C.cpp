#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, K;
    cin >> N >> K;

    vi vals(K);
    for (int i = 0; i < K; i++) {
        cin >> vals[i];
    }

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    K = vals.size();

    vector<bitset<2000>> dp(2);
    dp[0][1000] = true;

    bool x = 0;

    for (int l = 1; l <= 1010; l++) {
        dp[!x].reset();

        for (int v : vals) {
            if (v >= N) {
                dp[!x] |= dp[x] << (v - N);
            } else {
                dp[!x] |= dp[x] >> (N - v);
            }
        }

        x = !x;
        if (dp[x][1000]) {
            cout << l << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}