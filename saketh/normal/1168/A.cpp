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

    vi a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int ans = M, lo = 0, hi = M - 1;
    while (lo <= hi) {
        int mi = (lo + hi) / 2;

        bool succ = true;

        int nxt = M - 1;
        for (int j = N - 1; j >= 0; j--) {
            int cur = a[j];
            int tot = a[j] + mi;
            if ((cur <= nxt && nxt <= tot) || (nxt + M <= tot)) {
                // don't need to decrease nxt
            } else {
                int best = -1;
                if (cur < nxt) best = cur;
                if (tot % M < nxt) best = max(best, tot % M);

                if (best == -1) {
                    succ = false;
                    break;
                }
                nxt = best;
            }
        }

        if (succ) {
            ans = mi;
            hi = mi - 1;
        } else {
            lo = mi + 1;
        }
    }

    cout << ans << endl;

    return 0;
}