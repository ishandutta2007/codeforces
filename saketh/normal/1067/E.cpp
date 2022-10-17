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

const int MOD = 998244353;
int sum(int a, int b) { return (a + b) % MOD; }
int prod(int a, int b) { return a * 1ll * b % MOD; }
int mpow(int b, int e) {
    if (e == 0) return 1;
    if (e&1) return prod(b, mpow(b, e-1));
    return mpow(prod(b, b), e/2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    const int HALF = mpow(2, MOD - 2);

    int N;
    cin >> N;
    vvi adj(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    int ans = 0;
    function<int(int, int)> calc = [&](int loc, int par) {
        // returns the probability that the root is not available
        int nm = 1;
        for (int nbr : adj[loc]) {
            if (nbr == par) continue;
            int unv = calc(nbr, loc);
            unv = sum(unv, prod(HALF, sum(1, MOD - unv)));
            nm = prod(nm, unv);
        }
        nm = sum(1, MOD - nm);
        ans = sum(ans, nm);
        return nm;
    };

    calc(0, 0);
    for (int i = 0; i < N; i++)
        ans = prod(ans, 2);
    cout << ans << endl;
    return 0;
}