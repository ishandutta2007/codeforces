/*
    Soheil Mohammadkhani
    i'm sad :(
    aghayi ke dari in code ro mikhooi, in kod copyie :|
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define bug(x)                      cerr << #x << ": " <<  x <<  " ";
#define alog(a, n)                  for (int i = 1; i <= n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    if (b == -1) return poww(a, md - 2, md);
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n;
vector<int> adj[MAXN];
ll dp[MAXN] = {0}, score[MAXN] = {0};

void DFS(ll v, ll p) {
    dp[v] = score[v];
    for (ll u : adj[v]) {
        if (u != p) {
            DFS(u, v);
            if (dp[u] > 0) {
                dp[v] += dp[u];
            }
        }
    }
}

ll DFS2(ll v = 1, ll p = -1) {
    for (ll u : adj[v]) {
        if (u != p) {
            ll tmp_dp = dp[v];
            if (dp[u] > 0) {
                tmp_dp -= dp[u];
            }

            if (tmp_dp > 0) dp[u] += tmp_dp;

            DFS2(u, v);
        }
    }
}

int main() {
    fast_io;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> score[i];
        if (score[i] == 0) score[i] = -1;
    }
    for (int i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(1, -1);
    DFS2(1, -1);

    alog(dp, n);

    return 0;
}