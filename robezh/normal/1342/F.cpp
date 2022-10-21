#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 998244353;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int M = (1 << 15) + 5, N = 16;
const int INF = (int)1e9;
int sum[M];
struct P {
    int mask, pos;
};
P back[N][M][N];
int n, a[N];
int dp[N][M][N];

int getidx(int i) {
    int res = 0;
    for(int j = 0; j < i; j++) if(a[j]) res++;
    return res;
}

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    rep(i, 0, n + 1) rep(j, 0, 1 << n) rep(k, 0, n) dp[i][j][k] = INF;

    dp[0][0][0] = 0;
    rep(mask, 0, 1 << n) {
        sum[mask] = 0;
        rep(j, 0, n) if(mask >> j & 1) sum[mask] += a[j];
    }
    for(int cnt = 0; cnt < n; cnt++) {
        for(int mask = 0; mask < (1 << n); mask++) {
            for(int pos = 0; pos < n; pos++) {
                if(dp[cnt][mask][pos] == INF) continue;
                int comp = ((1 << n) - 1) ^ mask;
                for(int sub = comp; sub; sub = (sub - 1) & comp) {
                    if(dp[cnt][mask][pos] >= sum[sub] || (sub >> pos) == 0) continue;
                    int npos = pos + __builtin_ctz(sub >> pos);
                    int &nxtdp = dp[cnt+1][mask | sub][npos];
                    if(sum[sub] < nxtdp) {
                        nxtdp = sum[sub];
                        back[cnt+1][mask | sub][npos] = {mask, pos};
                    }
                }
            }
        }
    }
    int cnt = -1, pos = -1;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j < n; j++) {
            if(dp[i][(1 << n) - 1][j] != INF) cnt = i, pos = j;
        }
    }
    cout << n - cnt << '\n';
    vector<pii> ss;
    int mask = (1 << n) - 1;
    for(int i = cnt; i >= 1; i--) {
        P bk = back[i][mask][pos];
        ss.push_back({mask ^ bk.mask, pos});
        mask = bk.mask;
        pos = bk.pos;
    }

//    for(auto s : ss) cout << bitset<15>(s) << endl;
    vector<pii> res;
    reverse(all(ss));
    for(auto s : ss) {
        for(int j = 0; j < n; j++) {
            if((s.first >> j & 1) && (s.second != j)) {
                res.push_back({getidx(j), getidx(s.second)});
                a[j] = 0;
            }
        }
    }
    for(pii p : res) cout << p.first + 1 << " " << p.second + 1 << '\n';



}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while(T--) {
        solve();
    }

}