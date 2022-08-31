//Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 3
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 200005;
int mx[maxn];
ll dp[maxn];
int mxl[maxn];
vi eg[maxn];
int h[maxn];
int mpl;
int epl;
void dfs(int a, int fa) {
    mx[a] = h[a];
    dp[a] = 0;
    int son = 0, nmx = 0;
    for (auto v : eg[a]) {
        if (v == fa) continue;
        dfs(v, a);
        chkmax(mx[a], mx[v]);
        dp[a] += dp[v];
        if (chkmax(nmx, mx[v]))
            mxl[a] = mxl[v];
        son ++;
    }
    if (son == 0) 
        dp[a] = mx[a], 
        mxl[a] = a;
    else {
        dp[a] += mx[a] - nmx;
    }
    if (a == mpl) epl = mxl[a];
}
ll ans = 1e18;
void work(int a) {
    dfs(a, 0);
    chkmin(ans, dp[a] + h[mpl]);
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        eg[u].pb(v), eg[v].pb(u);    
    }
    for (int i = 1; i <= n; i++)
        if (h[i] > h[mpl]) mpl = i;
    epl = mpl;
    work(mpl);
    work(epl);
    work(epl);
    cout << ans << endl;
    return (0-0); //<3
}
/*
1

4 12
-9 -16 12 3
-20 -18
-14 -13
-10 -7
-3 -1
0 4
6 11
7 9
8 10
13 15
14 18
16 17
18 19*/