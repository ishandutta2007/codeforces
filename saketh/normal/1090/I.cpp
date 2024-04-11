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

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, L, R;
        unsigned int X, Y, Z;
        cin >> N >> L >> R >> X >> Y >> Z;

        vector<unsigned int> b(N);
        cin >> b[0] >> b[1];
        for (int i = 2; i < N; i++) {
            b[i] = b[i-2] * X  + b[i-1] * Y + Z;
        }

        vi a(N);
        for (int i = 0; i < N; i++) {
            a[i] = int(L + ll((b[i] % (R - L + 1))));
        }

        ll ans = LLONG_MAX;

        int minv = INT_MAX;
        for (int i = 0; i < N; i++) {
            if (a[i] > minv)
                ans = min(ans, minv * 1ll * a[i]);
            minv = min(minv, a[i]);
        }

        int maxv = INT_MIN;
        for (int i = N - 1; i >= 0; i--) {
            if (a[i] < maxv) {
                ans = min(ans, maxv * 1ll * a[i]);
            }
            maxv = max(maxv, a[i]);
        }

        if (ans < LLONG_MAX) {
            cout << ans << "\n";
        } else {
            cout << "IMPOSSIBLE\n";
        }
    }

    return 0;
}