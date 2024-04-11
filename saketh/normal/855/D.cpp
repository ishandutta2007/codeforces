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

    const int LOGN = 17;

    int N;
    cin >> N;

    vvi par(LOGN, vi(N));
    vvi typ(LOGN, vi(N));
    vi depth(N);

    for (int i = 0; i < N; i++) {
        int parent, type;
        cin >> parent >> type;
        if (parent == -1) {
            par[0][i] = i;
        } else {
            par[0][i] = parent - 1;
            typ[0][i] = 1 << type;
            depth[i] = depth[parent - 1] + 1;
        }
    }

    for (int l = 1; l < LOGN; l++) {
        for (int i = 0; i < N; i++) {
            par[l][i] = par[l-1][par[l-1][i]];
            typ[l][i] = typ[l-1][i] | typ[l-1][par[l-1][i]];
        }
    }

    auto up = [&](int loc, int dist) {
        int t = 0;
        for (int l = LOGN - 1; l >= 0; l--) {
            if (dist >= (1 << l)) {
                t |= typ[l][loc];
                loc = par[l][loc];
                dist -= 1 << l;
            }
        }
        return make_tuple(loc, t);
    };

    auto lca = [&](int a, int b) {
        int ta = 0, tb = 0;
        if (depth[a] > depth[b])
            tie(a, ta) = up(a, depth[a] - depth[b]);
        if (depth[b] > depth[a])
            tie(b, tb) = up(b, depth[b] - depth[a]);

        if (a != b) {
            for (int l = LOGN - 1; l >= 0; l--) {
                if (par[l][a] != par[l][b]) {
                    ta |= typ[l][a];
                    a = par[l][a];
                    tb |= typ[l][b];
                    b = par[l][b];
                }
            }

            ta |= typ[0][a];
            a = par[0][a];
            tb |= typ[0][b];
            b = par[0][b];
        }

        return make_tuple(a == b ? a : -1, ta, tb);
    };

    int Q;
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        int t, a, b, p, ta, tb;
        cin >> t >> a >> b;
        a--, b--;
        tie(p, ta, tb) = lca(a, b);
        //TRACE(cout << p << " " << ta << " " << tb << endl;)
        if (t == 1) {
            cout << (p == a && b != a && !(tb & 2) ? "YES" : "NO") << "\n";
        } else {
            cout << (p != -1 && b != p && !(ta & 2) && !(tb & 1) ? "YES" : "NO") << "\n";
        }
    }

    return 0;
}