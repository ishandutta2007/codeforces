#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

#define TRACE(x)
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
    
    int N, M, K;
    cin >> N >> M >> K;

    vi x(K), y(K);
    vll ans(K, LLONG_MAX);
    vvi sums(N + M + 1), difs(N + M + 1);

    for (int i = 0; i < K; i++) {
        cin >> x[i] >> y[i];
        WATCH(x[i] + y[i]);
        WATCH(x[i] - y[i] + M);
        sums[x[i] + y[i]].push_back(i);
        difs[x[i] - y[i] + M].push_back(i);
    }

    ll time = 0;
    int lx = 0, ly = 0;
    int dx = 1, dy = 1;

    for (int r = 0; r < 1000000; r++) {
        vi &elts = (dx == dy) ? difs[lx + M  - ly]
                              : sums[lx + ly];
        for (int p : elts)
            ans[p] = min(ans[p], time + (x[p] - lx) / dx);
        elts.clear();

        int tx = (dx > 0) ? (N - lx) : lx;
        int ty = (dy > 0) ? (M - ly) : ly;

        lx += dx * min(tx, ty);
        ly += dy * min(tx, ty);
        time += min(tx, ty);

        if (tx <= ty) {
            dx *= -1;
        } else {
            dy *= -1;
        }
    }

    for (int i = 0; i < K; i++) {
        cout << ((ans[i] == LLONG_MAX) ? -1 : ans[i]) << "\n";
    }
    return 0;
}