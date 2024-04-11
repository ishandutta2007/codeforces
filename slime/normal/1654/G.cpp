//Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<ll>
#define pi pair<int, int>
#define mod 1000000007
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 200005;
const int S = 35, T = 205;
vi eg[maxn];
int bst[T][maxn]; // best to reach with energy

int fl[maxn];

int tp[maxn];
int h[maxn];
void dfs1(int a, int fa) {
    h[a] = maxn;
    if (tp[a]) h[a] = 0; 
    for (auto v : eg[a]) {
        if (v == fa) continue;
        dfs1(v, a);
        chkmin(h[a], h[v] + 1);
    }
}
void dfs2(int a, int fa) {
    for (auto v : eg[a]) {
        if (v == fa) continue;
        chkmin(h[v], h[a] + 1);
        dfs2(v, a);
    }
}

int nd[maxn];

vi leg[maxn], seg[maxn], geg[maxn];

void dfs3(int a, int fa) {
    for (auto v : eg[a]) {
        if (v == fa) continue;
        dfs3(v, a);
    }
    for (auto v : leg[a]) chkmin(nd[a], max(0, nd[v] - 1));
    for (auto v : seg[a]) chkmin(nd[a], nd[v] + 1);
}
void dfs4(int a, int fa) {
    for (auto v : geg[a]) chkmin(nd[v], max(0, nd[a] - 1));
    for (auto v : seg[a]) chkmin(nd[v], nd[a] + 1);
    for (auto v : eg[a]) {
        if (v == fa) continue;
        dfs4(v, a);
    }
}
int res[maxn];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%d", &tp[i]);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        eg[u].pb(v), eg[v].pb(u);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    for (int i = 1; i <= n; i++)
        for (auto v : eg[i])
            if (h[v] < h[i]) leg[i].pb(v);
            else if (h[v] == h[i]) seg[i].pb(v);
            else geg[i].pb(v);
    vi cur;
    vector<pi> s;
    for (int i = 1; i <= n; i++)
        s.pb(mp(h[i], i));
    for (int i = 1; i <= n; i++)
        if (seg[i].size()) fl[i] = 1;
    sort(s.begin(), s.end());
    for (int i = 1; i <= n; i++) 
        for (int j = 0; j < T; j++)
            bst[j][i] = maxn;
    for (int i = 0; i < s.size(); ) {
        int j = i;
        while (j < s.size() && s[j].fi == s[i].fi) j++;
        vi nid(j - i);
        for (int k = i; k < j; k++)
            nid[k - i] = s[k].se;
    
        // compute bst
        for (auto v : nid)
            if (fl[v]) 
                for (int j = 0; j < T; j++)
                    bst[j][v] = h[v];
        
        for (int l = 0; l < T; l++) {
            int nx = min(T - 1, l + 1);
            for (auto v : nid) 
                for (auto e : leg[v]) 
                    chkmin(bst[l][v], bst[nx][e]);
                        
            if (l)
                for (auto v : nid)
                    for (auto e : seg[v])
                        chkmin(bst[l][v], bst[l-1][e]);
        }
        i = j;
    }
    for (int i = 1; i <= n; i++)
        res[i] = bst[0][i];
    for (int j = 0; j < S; j++) {
        for (int i = 1; i <= n; i++) {
            nd[i] = maxn;
            if (fl[i] && h[i] <= j) nd[i] = 0;
        }
        dfs3(1, 0);
        dfs4(1, 0);
        for (int i = 1; i <= n; i++)
            if (!nd[i]) chkmin(res[i], j);
    }
    for (int i = 1; i <= n; i++) {
        int ans = h[i] + h[i] - min(h[i], res[i]);
        printf("%d ", ans);
    }
    printf("\n");
    return (0-0); //<3
}