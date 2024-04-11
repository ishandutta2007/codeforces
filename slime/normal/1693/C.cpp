//Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 1000000007
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 500005;
int dp[maxn];
vi in[maxn], out[maxn];
int done[maxn];
int hv[maxn];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        in[v].pb(u), out[u].pb(v);
    }
    priority_queue<pi> cur;
    cur.push(mp(0, n));
    for (int i = 0; i < maxn; i++)
        dp[i] = 1e9;
    dp[n] = 0;
    while (!cur.empty()) {
        pi fr = cur.top(); cur.pop();
        if (-fr.fi != dp[fr.se]) continue;
        if (done[fr.se]) continue;
        int id = fr.se;
        done[id] = 1;
        for (auto v : in[id]) {
            hv[v] += 1;
            int nans = dp[id] + (int)out[v].size() - hv[v] + 1;
            if (chkmin(dp[v], nans))
                cur.push(mp(-dp[v], v));
        }
    }
    cout << dp[1] << endl;
    return (0-0); //<3
}