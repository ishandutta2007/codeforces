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

    int N, M;
    cin >> N >> M;

    vi ct(M);
    for (int i = 0, t; i < N; i++) {
        cin >> t;
        ct[t - 1]++;
    }

    array<int, 9> dp, upd;
    fill(all(dp), 0);

    for (int v : ct) {
        fill(all(upd), 0);
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                for (int z = 0; z < 3; z++) {
                    if (x + y + z <= v)
                        upd[3*z+y] = max(upd[3*z+y], dp[3*y+x] + z + (v - x - y - z) / 3);
                }
            }
        }
        swap(dp, upd);
    }

    cout << dp[0] << "\n";
    return 0;
}