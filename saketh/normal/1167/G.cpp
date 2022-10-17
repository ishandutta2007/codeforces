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

    const int INF = 1e9;

    int N, D;
    cin >> N >> D;

    vi locs(N + 2);
    locs[0] = -INF;
    for (int i = 1; i <= N; i++) {
        cin >> locs[i];
    }
    locs[N+1] = INF;

    int Q;
    cin >> Q;
    for (int q = 0, i = 0; q < Q; q++) {
        int fold;
        cin >> fold;

        while (locs[i] < fold)
            i++;

        int right = i, left = i - 1;
        int sdist = min(fold - locs[left] - 1, locs[right] - fold);

        double ans = atan2(1, sdist);

        while (1 <= left && right <= N) {
            int rdist = locs[right] - fold;
            int ldist = fold - locs[left] - 1;

            if (abs(rdist - ldist) <= 1) {
                ans = max(ans, 2 * atan2(1, max(ldist, rdist)));
                break;
            }
            if (max(rdist, ldist) > 2 * sdist + 5) {
                break;
            }

            if (rdist < ldist) right++;
            else left--;
        }

        printf("%.15f\n", ans);
    }

    return 0;
}