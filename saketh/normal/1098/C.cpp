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

    int N;
    ll S;
    cin >> N >> S;

    int BF = INT_MAX;
    for (int lo = 1, hi = N - 1; lo <= hi; ) {
        int bf = (lo + hi) / 2;

        ll msum = 0;
        for (ll dep = 1, lsz = 1, tmp = N; tmp > 0; dep++, lsz *= bf) {
            msum += min(lsz, tmp) * dep;
            tmp -= min(lsz, tmp);
        }

        if (msum <= S) {
            BF = bf;
            hi = bf - 1;
        } else {
            lo = bf + 1;
        }
    }

    if (BF == INT_MAX || N * 1ll * (N + 1) / 2 < S) {
        cout << "No\n";
        return 0;
    }

    vi par(N), deg(N), dep(N);
    dep[0] = 1;
    for (int t = 0, i = 1; i < N; i++) {
        par[i] = t;
        dep[i] = dep[t] + 1;
        if (++deg[t] == BF) t++;
    }

    ll CS = 0;
    for (int i = 0; i < N; i++)
        CS += dep[i];

    int sp = N - 1;
    while (dep[sp - 1] == dep[sp])
        sp--;

    vb skip(N);
    for (int tmp = sp; tmp > 0; tmp = par[tmp])
        skip[tmp] = true;
    for (int i = N - 1; i > 0 && CS < S; i--) {
        if (skip[i]) continue;
        assert(deg[i] == 0);

        int diff = dep[sp] + 1 - dep[i];
        while (CS + diff > S) {
            assert(sp > 0);
            sp = par[sp];
            diff--;
        }
        assert(deg[sp] < BF);

        deg[par[i]]--;
        par[i] = sp;
        deg[sp]++;
        dep[i] = dep[sp] + 1;
        CS += diff;
        sp = i;
    }

    cout << "Yes\n";
    for (int i = 1; i < N; i++)
        cout << par[i] + 1 << " ";
    cout << endl;

    return 0;
}