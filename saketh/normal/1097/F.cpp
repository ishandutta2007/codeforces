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

const int MAXV = 7007;
using bs = bitset<MAXV>;

const int MAXN = 1e5;

bs sqfree;
bs init[MAXV];
bs prod[MAXV];
bs vals[MAXN];

void debug(bs b) {
    for (int i = 0; i < MAXV; i++)
        if (b[i])
            cout << i << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    for (int v = 1; v < MAXV; v++) {
        sqfree[v] = true;
        for (int u = 2; u * u <= v; u++) {
            if (v % (u * u) == 0)
                sqfree[v] = false;
        }
    }
    //debug(sqfree);

    for (int v = 1; v < MAXV; v++) {
        for (int d = 1; d <= v; d++)
            if (v % d == 0)
                init[v][d] = true;
        for (int u = v * 2; u < MAXV; u += v)
            if (sqfree[u / v]) prod[v][u] = true;
    }

    int N, Q, t, x, v, y, z;
    cin >> N >> Q;
    for (int q = 0; q < Q; q++) {
        cin >> t >> x;
        if (t == 1) {
            cin >> v;
            vals[x - 1] = init[v];
        } else if (t == 2) {
            cin >> y >> z;
            vals[x - 1] = vals[y - 1] ^ vals[z - 1];
        } else if (t == 3) {
            cin >> y >> z;
            vals[x - 1] = vals[y - 1] & vals[z - 1];
        } else {
            cin >> v;
            int app = (vals[x - 1] & prod[v]).count() & 1;
            int inc = vals[x - 1][v];
            cout << (app != inc);
        }

        /*cout << q + 1 << ": ";
        for (int s = 0; s < N; s++) {
            debug(vals[s]);
        }*/
    }
    cout << endl;

    return 0;
}