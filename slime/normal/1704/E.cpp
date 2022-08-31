//Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 998244353
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 1005;
const int md2 = 1e9 + 19;
vi eg[maxn];
int a[maxn], nx[maxn], b[maxn];
int n, m;
bool chk() {
    for (int i = 1; i <= n; i++)
        if (a[i]) return 0;
    return 1;
}
void upd() {
    for (int i = 1; i <= n; i++)
        nx[i] = a[i];
    for (int i = 1; i <= n; i++) {
        if (!a[i]) continue;
        for (auto v : eg[i])
            nx[v]++;
        nx[i]--;
    }
    for (int i = 1; i <= n; i++)
        a[i] = nx[i];
}
int q[maxn], d[maxn];
ll dp[maxn];
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++) eg[i].clear();
        for (int i = 1; i <= m; i++) {
            int x, y;
            cin >> x >> y;
            eg[x].pb(y);
        }
        int ans = 0;
        if (!chk()) {
            for (int j = 1; j <= m; j++) {
                upd();
                if (chk()) {
                    ans = j;
                    break;
                }
            }
            if (ans != 0) {
                printf("%d\n", ans);
                continue;
            }
            ans = m;
            int fr = 0, ed = 0;
            for (int i = 1; i <= n; i++) d[i] = 0;
            for (int i = 1; i <= n; i++) 
                for (auto v : eg[i]) d[v] += 1;
            
            for (int i = 1; i <= n; i++)
                if (!d[i]) q[ed++] = i;
            while (fr < ed) {
                int v = q[fr++];
                for (auto u : eg[v]) {
                    d[u]--;
                    if (!d[u]) q[ed++] = u;
                }
            }
            for (int i = n - 1; i >= 0; i--) {
                int v = q[i];
                if (i == n - 1) {
                    assert(eg[v].size() == 0);
                    dp[v] = 1;
                }
                else {
                    dp[v] = 0;
                    for (auto h : eg[v])
                        dp[v] = (dp[v] + dp[h]) % mod;
                }
                ans += (1ll * dp[v] * a[v] % mod);
                ans %= mod;
            }
        }
        cout << ans << endl;
    }
    return (0-0); //<3
}