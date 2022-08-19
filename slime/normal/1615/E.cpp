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
const int maxn = 200005;
int n, k;
vi eg[maxn];
int f[maxn], dep[maxn];
int mx[maxn];
vi cur;
void dfs(int a, int fa) {
    if (eg[a].size() == 1 && fa) {
        mx[a] = 1;
        return ;
    }
    vi cr;
    for (auto v : eg[a]) {
        if (v == fa) continue;
        dfs(v, a);
        cr.pb(mx[v]);
    }
    sort(cr.begin(), cr.end());
    mx[a] = cr[cr.size() - 1] + 1;
    for (int j = 0; j < cr.size() - 1; j++) cur.pb(cr[j]);
}
int main() {
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        eg[u].pb(v), eg[v].pb(u);
    }
    dfs(1, 0);
    cur.pb(mx[1]);
    sort(cur.begin(), cur.end());
    reverse(cur.begin(), cur.end());
    int u = 0, v = 0;
    if (k > cur.size()) {
        v = 0; 
        u = cur.size();
        if (k >= n / 2) u = n / 2;
        else u = k;
    }
    else {
        u = k;
        v = n;
        for (int i = 0; i < k; i++)
            v -= cur[i];
        if (v > n / 2) v = n / 2;
    }
    ll ans = 1ll * (n - u - v) * (u - v);
    cout << ans << endl;
    return (0-0); //<3
}