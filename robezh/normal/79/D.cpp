#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int N = 10005, K = 20;
const int INF = (int)1e9;

int n, k, l;
int x[K], a[N];
int dist[N];
int dis[K][K];
int dp[1 << K];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k >> l;
    rep(i, 0, k) cin >> x[i], x[i]--;
    rep(i, 0, l) cin >> a[i];
    rep(i, 0, 2 * k) {
        int loc = x[i / 2] + i % 2;
        fill(dist, dist + n + 1, INF);
        queue<int> que;
        dist[loc] = 0;
        que.push(loc);
        while(!que.empty()) {
            int v = que.front(); que.pop();
            rep(j, 0, l) {
                int nv = v + a[j];
                if(nv <= n && dist[nv] == INF) {
                    dist[nv] = dist[v] + 1;
                    que.push(nv);
                }
                nv = v - a[j];
                if(nv >= 0 && dist[nv] == INF) {
                    dist[nv] = dist[v] + 1;
                    que.push(nv);
                }
            }
        }
        rep(j, 0, 2 * k) {
            dis[i][j] = dist[x[j / 2] + j % 2];
        }
    }
    fill(dp, dp + (1 << (2 * k)), INF);
    dp[0] = 0;
    rep(mask, 1, (1 << (2 * k))) {
        int fir = 0;
        while(!(mask >> fir & 1)) fir++;
        rep(j, fir + 1, 2 * k) {
            if(mask >> j & 1)
                dp[mask] = min(dp[mask], dp[mask ^ (1 << fir) ^ (1 << j)] + dis[fir][j]);
        }
    }
    int res = dp[(1 << (2 * k)) - 1];
    if(res == INF) res = -1;
    cout << res << '\n';


}