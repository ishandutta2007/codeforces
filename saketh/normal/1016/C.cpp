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

    int N;
    cin >> N;

    vvi g(2, vi(N));
    for (int r = 0; r < 2; r++)
        for (int c = 0; c < N; c++)
            cin >> g[r][c];

    vvll rs(2, vll(N));
    vvll ri(2, vll(N));
    vvll rd(2, vll(N));
    for (int r = 0; r < 2; r++)
        for (int c = N-1; c >= 0; c--) {
            rs[r][c] = g[r][c];
            if (c+1<N) rs[r][c] += rs[r][c+1];

            ri[r][c] = g[r][c];
            if (c+1<N) ri[r][c] += ri[r][c+1] + rs[r][c+1];

            rd[r][c] = g[r][c] * 1ll * (N-c);
            if (c+1<N) rd[r][c] += rd[r][c+1];
        }

    ll ans = 0;
    ll collect = 0;

    int r = 0, c = 0;
    ll t = 0;
    while (c < N) {
        collect += t * g[r][c];

        if ((c&1)^(r&1)) {
            ll cand = collect;
            if (c+1<N) cand += rs[r][c+1] * (t) + ri[r][c+1];
            if (c+1<N) cand += rs[r^1][c+1] * (t + N - c - 1) + rd[r^1][c+1];
            ans = max(ans, cand);
            t++, c++;
        }
        else {
            ll cand = collect;
            if (c+1<N) cand += rs[r][c+1] * (t) + ri[r][c+1];
            if (c+1<N) cand += rs[r^1][c] * (t + N - c - 1) + rd[r^1][c];
            ans = max(ans, cand);
            t++, r ^= 1;
        }
    }

    cout << ans << endl;
    return 0;
}