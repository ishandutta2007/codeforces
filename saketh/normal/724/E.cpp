#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, C;
    cin >> N >> C;

    vi prod(N), sell(N);

    for (int i = 0; i < N; i++)
        cin >> prod[i];

    for (int i = 0; i < N; i++)
        cin >> sell[i];

    vvll cut(2, vll(N + 1));
    ll ans = LLONG_MAX;

    for (int i = 0; i < N; i++) {
        int l = i&1;
        fill(all(cut[l]), LLONG_MAX);

        for (int pv = 0; pv <= N; pv++) {
            cut[l][pv] = cut[l^1][pv] + pv * 1ll * C + prod[i];
            if (pv > 0) cut[l][pv] = min(cut[l][pv], cut[l^1][pv-1] + sell[i]);

            if (i == N - 1) ans = min(ans, cut[l][pv]);
        }
    }

    cout << ans << endl;
    return 0;
}