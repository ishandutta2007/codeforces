#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<string> vs;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bitset<10001> dpf[101][101];
bitset<10001> dpb[101][101];

void do_dp(int N, vi &vals, auto &dp) {
    dp[0][0][0] = 1;
    for (int l = 0; l < N; l++) {
        for (int u = 0; u <= l; u++) {
            dp[l+1][u] |= dp[l][u];
            dp[l+1][u+1] |= dp[l][u] << vals[l];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    const int MAXV = 101;
    vi ct(MAXV);

    int N;
    cin >> N;
    vi vals(N);
    for (int i = 0; i < N; i++) {
        cin >> vals[i];
    }

    sort(all(vals));
    do_dp(N, vals, dpf);

    vi slav = vals;
    reverse(all(slav));
    do_dp(N, slav, dpb);

    vi uniq = vals;
    uniq.erase(unique(all(uniq)), uniq.end());

    int ans = 0;
    for (int v = 1; v <= 100; v++) {
        int ct = 0;
        for (int w : vals)
            if (w == v)
                ct++;
        if (!ct) continue;

        int i = 0;
        while (vals[i] < v) i++;
        int j = 0;
        while (slav[j] > v) j++;

        for (int k = 1; k <= ct; k++) {
            bool make = false;
            for (int b = 0; b <= k; b++) {
                for (int bs = 0; bs <= v * k; bs++) {
                    if (dpf[i][b][bs] && dpb[j][k-b][v*k-bs]) {
                        make = true;
                    }
                }
            }
            if (!make) {
                ans = max(ans, k);
                if (k == ct && uniq.size() <= 2) {
                    ans = N;
                }
            } else break;
        }
    }

    cout << ans << endl;
    return 0;
}