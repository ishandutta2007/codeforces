#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

#define dp(a, b, c) arr[a * 3 * (X + 1) + 3 * b + c]

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

const int MOD = 1e9 + 7;
int sum(int a, int b) { return (a + b) % MOD; }
int add(int &a, int b) { a = sum(a, b); }
int prod(int a, int b) { return a * 1ll * b % MOD; }

int res[16][4];

void combine(vi &arr, int X, int par, int child) {
    memset(res, 0, sizeof(res));
    for (int ph = X; ph >= 0; ph--) {
        for (int ch = X; ch >= 0; ch--) {
            if (ph + ch > X) continue;
            int tp0 = prod(dp(par, ph, 0),
                    sum(sum(dp(child, ch, 0), dp(child, ch, 1)), dp(child, ch, 2)));
            int tp1 = prod(dp(par, ph, 1),
                    sum(dp(child, ch, 0), dp(child, ch, 1)));
            int tp2 = prod(dp(par, ph, 2),
                    dp(child, ch, 0));

            add(res[ch + ph][0], tp0);
            add(res[ch + ph][1], tp1);
            add(res[ch + ph][2], tp2);
        }
    }

    for (int ph = 0; ph <= X; ph++)
        for (int pt = 0; pt <= 2; pt++)
            dp(par, ph, pt) = res[ph][pt];
}

void solve(int loc, int par, vvi &adj, vi &arr, int X, int K, int M) {
    dp(loc, 0, 0) = K - 1;
    dp(loc, 0, 1) = M - K;
    dp(loc, 1, 2) = 1;

    for (int ch : adj[loc]) {
        if (ch == par) continue;
        solve(ch, loc, adj, arr, X, K, M);
        combine(arr, X, loc, ch);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, M;
    cin >> N >> M;

    vvi tree(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u - 1].push_back(v - 1);
        tree[v - 1].push_back(u - 1);
    }

    int K, X;
    cin >> K >> X;

    vi arr(N * (X + 1) * 3);
    solve(0, 0, tree, arr, X, K, M);

    int ans = 0;
    for (int qk = 0; qk <= X; qk++) {
        for (int tp = 0; tp <= 2; tp++)
            ans = sum(ans, dp(0, qk, tp));
    }
    cout << ans << endl;

    return 0;
}