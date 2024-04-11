#include <bits/stdc++.h>
using namespace std;

#define TRACE(x)
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

const int MOD = 1e9 + 7;
int sum(int a, int b) { return (a + b) % MOD; }
int prod(int a, int b) { return a * 1ll * b % MOD; }

int K;

// dp[x][y] = # of ways to color such that the shallowest colored
// node is at depth x, and the deepest unsatisfied is at depth y
// depth of K means none exists

// creates dp for a single node
vvi init() {
    vvi dp(K + 1, vi(K + 1));
    dp[0][K] = 1; // color the root
    dp[K][0] = 1; // don't color it
    return dp;
}

// update a parent's dp with values from the child
vvi merge(vvi &par, vvi &ch) {
    vvi res(K + 1, vi(K + 1));
    for (int px = 0; px <= K; px++) {
        for (int py = 0; py <= K; py++) {
            if (par[px][py] == 0) continue;
            for (int cx = 0; cx <= K; cx++) {
                for (int cy = 0; cy <= K; cy++) {
                    if (ch[cx][cy] == 0) continue;
                    if (cy == K - 1 && px != 0) {
                        // if this is true we need the root colored
                        continue;
                    }

                    int resx = min(px, min(cx + 1, K));

                    int resy = -1;
                    if (cy != K && px + cy + 1 > K)
                        resy = max(resy, cy + 1);
                    if (py != K && py + cx + 1 > K)
                        resy = max(resy, py);
                    if (resy == -1) resy = K;

                    TRACE(cout << "(" << px << " " << py << ")[" << par[px][py] << "] + (" << cx << " " << cy 
                               << ")[" << ch[cx][cy] << "] combines to (" << resx << " " << resy << ")" << endl;)

                    res[resx][resy] = sum(res[resx][resy],
                            prod(par[px][py], ch[cx][cy]));
                }
            }
        }
    }
    return res;
}

vvi go(int loc, int par, vvi &adj) {
    vvi ret = init();
    for (int ch : adj[loc]) {
        if (ch != par) {
            vvi blw = go(ch, loc, adj);
            ret = merge(ret, blw);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N >> K;

    vvi adj(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;

        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    int ans = 0;
    vvi res = go(0, 0, adj);
    for (int i = 0; i <= K; i++) {
        TRACE(cout << i << " " << res[i][K] << "\n";)
        ans = sum(ans, res[i][K]);
    }
    cout << ans << "\n";

    return 0;
}