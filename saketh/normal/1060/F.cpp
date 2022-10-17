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
using vd = vector<double>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    const int MAXV = 51;

    ll pasc[MAXV][MAXV];
    memset(pasc, 0, sizeof(pasc));
    pasc[0][0] = 1;

    for (int n = 1; n < MAXV; n++) {
        pasc[n][0] = pasc[n-1][0];
        for (int r = 1; r <= n; r++) {
            pasc[n][r] = pasc[n-1][r] + pasc[n-1][r-1];
        }
    }

    int N;
    cin >> N;
    vvi tree(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u-1].push_back(v-1);
        tree[v-1].push_back(u-1);
    }

    auto extend = [&pasc](const vd& a) {
        vd b(a.size() + 1);
        for (int e = 0; e <= a.size(); e++) {
            for (int ea = 0; ea < e; ea++) {
                b[e] += 1. / a.size() * 0.5 * a[ea];
            }
            b[e] += (a.size() - e) / double(a.size()) * a[e];
        }
        return b;
    };

    auto combine = [&pasc](const vd& a, const vd& b) {
        int A = a.size() - 1, B = b.size() - 1;
        vd c(A + B + 1);
        for (int ae = 0; ae <= A; ae++) {
            for (int be = 0; be <= B; be++) {
                c[ae + be] += a[ae] * b[be] *
                    double(pasc[ae + be][ae]) * pasc[A + B - ae - be][A - ae] / pasc[A + B][A];
            }
        }
        return c;
    };

    function<vd(int, int)> solve = [&](int loc, int par) {
        vd res(1, 1);
        for (int nbr : tree[loc]) if (nbr != par) {
            res = combine(res, extend(solve(nbr, loc)));
        }
        return res;
    };

    cout << fixed << setprecision(15);
    for (int i = 0; i < N; i++)
        cout << solve(i, i).back() << "\n";

    return 0;
}