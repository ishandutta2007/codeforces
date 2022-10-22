#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
template<int MOD, int RT> struct mint {
	static const int mod = MOD;
	static constexpr mint rt() { return RT; } // primitive root for FFT
	int v; explicit operator int() const { return v; } // explicit -> don't silently convert to int
	mint() { v = 0; }
	mint(LL _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
		if (v < 0) v += MOD; }
	friend bool operator==(const mint& a, const mint& b) { 
		return a.v == b.v; }
	friend bool operator!=(const mint& a, const mint& b) { 
		return !(a == b); }
	friend bool operator<(const mint& a, const mint& b) { 
		return a.v < b.v; }
	friend void read(mint& a) { LL x; scanf("%lld",&x); a = mint(x); }
   
	mint& operator+=(const mint& m) { 
		if ((v += m.v) >= MOD) v -= MOD; 
		return *this; }
	mint& operator-=(const mint& m) { 
		if ((v -= m.v) < 0) v += MOD; 
		return *this; }
	mint& operator*=(const mint& m) { 
		v = int((LL)v*m.v%MOD); return *this; }
	mint& operator/=(const mint& m) { return (*this) *= inv(m); }
	friend mint pow(mint a, LL p) {
		mint ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans; }
	friend mint inv(const mint& a) { assert(a.v != 0); 
		return pow(a,MOD-2); }
		
	mint operator-() const { return mint(-v); }
	mint& operator++() { return *this += 1; }
	mint& operator--() { return *this -= 1; }
	friend mint operator+(mint a, const mint& b) { return a += b; }
	friend mint operator-(mint a, const mint& b) { return a -= b; }
	friend mint operator*(mint a, const mint& b) { return a *= b; }
	friend mint operator/(mint a, const mint& b) { return a /= b; }
};

const int MOD = 1e9 + 7;
typedef mint<MOD,5> mi; // 5 is primitive root for both common mods

struct RootedTree {
    using len_type = long long;
    using pr = pair<len_type, int>;
    static const int MAXD = 9; // for LCA; (1 << (MAXD - 1)) >= N
    vector<vector<pr> >e;
    vector<int> fa;
    vector<len_type> dis_to_root; // dis from root
    vector<int> dep; // Root has a dep of 1
    vector<vector<int> > anc; // anc[i][j] is the (2^j) ancestor of i
    vector<int> dfn, dfnL, dfnR;
    vector<int> size, hson, top; // for heavy-light-decomposite

    int N, Root;
    RootedTree() {}
    RootedTree(int _N, int _Root = 1) : N(_N), Root(_Root) {
        e.assign(N + 1, vector<pr>());
        fa.assign(N + 1, 0);
        dis_to_root.assign(N + 1, 0);
        dep.assign(N + 1, 0);
        dfn.assign(N + 1, 0); // If need multiple dfn, modify to 2 * N + 1?
        dfnL.assign(N + 1, 0);
        dfnR.assign(N + 1, 0);
        size.assign(N + 1, 0);
        hson.assign(N + 1, 0);
    }
    void add_edge(int u, int v, len_type w = 1) {
        e[u].push_back(pr(w, v));
        e[v].push_back(pr(w, u));
    }
    void dfs(int x, int FA, bool calc_lca, int &time_tag) {
        dfn[++time_tag] = x;
        dfnL[x] = time_tag;
        fa[x] = FA;
        if (calc_lca) {
            anc[x][0] = FA;
            for (int i = 1; i < MAXD; i++) anc[x][i] = anc[anc[x][i - 1]][i - 1];
        }
        size[x] = 1;
        hson[x] = 0;
        for (auto &t : e[x]) {
            if (t.second == FA) continue;
            dep[t.second] = dep[x] + 1;
            dis_to_root[t.second] = dis_to_root[x] + t.first;
            dfs(t.second, x, calc_lca, time_tag);
            size[x] += size[t.second];
            if (hson[x] == 0 || size[t.second] > size[hson[x]]) {
                hson[x] = t.second;
            }
        }
        dfnR[x] = time_tag;
    }
    void init(bool calc_lca = false) {
        dep[Root] = 1;
        dis_to_root[Root] = 0;
        if (calc_lca) anc.assign(N + 1, vector<int>(MAXD, 0));
        int time_tag = 0;
        dfs(Root, 0, calc_lca, time_tag);
    }
    int lca(int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        int delta = dep[u] - dep[v];
        for (int i = MAXD - 1; i >= 0; i--) {
            if (delta & (1 << i)) {
                u = anc[u][i];
            }
        }
        if (u == v) return u;
        for (int i = MAXD - 1; i >= 0; i--) {
            if (anc[u][i] != anc[v][i]) {
                u = anc[u][i];
                v = anc[v][i];
            }
        }
        return anc[u][0];
    }
    int K_ancestor(int x, int K) {
        for (int i = 0; i < MAXD; i++) {
            if ((K >> i) & 1) x = anc[x][i];
        }
        return x;
    }
    void hld_dfs(int x, int &time_tag) {
        dfn[++time_tag] = x;
        dfnL[x] = time_tag;
        if (fa[x] && x == hson[fa[x]]) {
            top[x] = top[fa[x]];
        } else {
            top[x] = x;
        }
        if (hson[x]) hld_dfs(hson[x], time_tag);
        for (auto &t : e[x]) {
            if (t.second != fa[x] && t.second != hson[x]) {
                hld_dfs(t.second, time_tag);
            }
        }
        dfnR[x] = time_tag;
    }
    void heavy_light_decomposite() {
        // reset dfn
        int time_tag = 0;
        hld_dfs(Root, time_tag);
    }
    int unweighted_dis(int u, int v) {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }
    len_type weighted_dis(int u, int v) {
        return dis_to_root[u] + dis_to_root[v] - 2 * dis_to_root[lca(u, v)];
    }
};


// prob of achieve A_i, B_j
mi dp[210][210];
mi s1[210][210];
mi s2[210][210];
int n;

int main() {
    dp[0][0] = 1;
    for (int i = 0; i <= 200; i++) {
        for (int j = 0; j <= 200; j++) {
            dp[i + 1][j] += dp[i][j] / 2;
            dp[i][j + 1] += dp[i][j] / 2;
        }
    }
    for (int i = 0; i <= 200; i++) {
        for (int j = 1; j <= 200; j++) {
            dp[i][j] += dp[i][j - 1];
        }
    }
    scanf("%d",&n);
    RootedTree T(n);
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        scanf("%d%d",&u,&v);
        T.add_edge(u, v);
    }
    mi ans = 0;
    for (int i = 1; i <= n; i++) {
        T.Root = i;
        T.init(true);
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k < j; k++) {
                // j appear earlier than k
                int dep_lca = T.dep[T.lca(j, k)];
                int depj = T.dep[j] - dep_lca;
                int depk = T.dep[k] - dep_lca;
                mi delta = 0;
                if (depk > 0) {
                    if (depj == 0) {
                        ans += 1;
                        delta = 1;
                    } else {
                        ans += dp[depj - 1][depk - 1] / 2;
                        delta = dp[depj - 1][depk - 1] / 2;
                    }
                }
                //printf("%d %d %d %d %d %d\n",i,j,k,depj,depk,int(delta));
            }
        }
    }
    ans /= n;
    printf("%d\n",int(ans));
}