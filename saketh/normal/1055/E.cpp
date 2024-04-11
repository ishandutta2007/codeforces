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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, S, M, K;
    cin >> N >> S >> M >> K;

    vi a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    vector<array<int, 2>> seg(S);
    for (int i = 0; i < S; i++) {
        cin >> seg[i][0] >> seg[i][1];
        seg[i][0]--;
        seg[i][1]--;
    }
    sort(all(seg));

    vi ext(N, INT_MAX);
    for (int i = 0, j = 0; i < N; i++) {
        while (j < seg.size() && seg[j][1] < i)
            j++;
        if (j < seg.size())
            ext[i] = seg[j][0];
    }

    auto cover = [&](int lim) {
        vi pref(N + 1);
        for (int i = 0; i < N; i++) {
            pref[i+1] = pref[i] + (a[i] <= lim);
        }

        vvi g(N + 1, vi(M + 1));
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= M; k++) {
                int i = ext[j-1];
                g[j][k] = max(g[j-1][k], i < j ? (pref[j] - pref[i] + g[i][k-1]) : 0);
            }
        }

        return g[N][M];
    };

    int ans = -1;
    int lo = 1, hi = 1e9;
    while (lo <= hi) {
        int mi = (lo + hi) / 2;
        if (cover(mi) >= K) {
            ans = mi;
            hi = mi - 1;
        } else {
            lo = mi + 1;
        }
    }

    cout << ans << endl;
    return 0;
}