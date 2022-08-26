#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define all(c) (c).begin(), (c).end()
#define sz(c) int((c).size())
#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define FILE "a"

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stdout)
#else
#define eprintf(args...) ;
#endif

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int MAXN = (int)2e5 + 500;

int n, m, S, L, v;
int st[MAXN], lf[MAXN];
int Q;
pair<pii, pii> qs[MAXN];

void read(pii &p) {
    cin >> p.fst >> p.snd;
    p.fst--, p.snd--;
}

bool read() {
    if (!(cin >> n >> m >> S >> L >> v)) {
        return 0;
    }
    forn(i, S) {
        cin >> st[i];
        st[i]--;
    }
    forn(i, L) {
        cin >> lf[i];
        lf[i]--;
    }
    cin >> Q;
    forn(i, Q) {
        read(qs[i].fst);
        read(qs[i].snd);
    }
    return 1;
}

const int INF = (int)1e9;
set<int> sts, lfs;

void solve() {
    sts.clear();
    sts.insert(-INF);
    sts.insert(+INF);
    forn(i, S) {
        sts.insert(st[i]);
    }

    lfs.clear();
    lfs.insert(-INF);
    lfs.insert(+INF);
    forn(i, L) {
        lfs.insert(lf[i]);
    }

    forn(i, Q) {
        int dh = abs(qs[i].fst.fst - qs[i].snd.fst);
        int xa = qs[i].fst.snd, xb = qs[i].snd.snd;
        if (xa > xb) {
            swap(xa, xb);
        }

        int ans = INF;
        if (dh == 0) {
            ans = min(ans, abs(xa - xb));
        }

        // stairs
        auto ptr = sts.lower_bound(xa);
        forn(it, 2) {
            int x = *ptr;
            if (x == -INF) {
                break;
            }
            if (x < +INF) {
                ans = min(ans, abs(x - xa) + dh + abs(x - xb));
            }
            ptr--;
        }
        
        // lifts
        ptr = lfs.lower_bound(xa);
        forn(it, 2) {
            int x = *ptr;
            if (x == -INF) {
                break;
            }
            if (x < +INF) {
                ans = min(ans, abs(x - xa) + (dh + v - 1) / v + abs(x - xb));
            }
            ptr--;
        }

        assert(ans < INF);
        cout << ans << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

#ifdef LOCAL
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
#endif

    while (read()) {
        solve();
    }

#ifdef LOCAL
    eprintf("Time %.5f\n", clock() * 1.0 / CLOCKS_PER_SEC);
#endif
}