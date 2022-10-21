#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)1e5 + 50;
typedef pair<ll, ll> pll;

vector<pll> ps;

int n, m;
struct edge {
    int to, cost;
};
vector<edge> G[N];
ll dep[N];
map<ll, ll> rgs;



struct Splay {
#define ls ch[x][0]
#define rs ch[x][1]
    int ch[N][2], fa[N], val[N], sum[N], rev[N];
    ll tim[N], to[N], laz[N];
    void clear(int x) {
        ch[x][0] = ch[x][1] = fa[x] = val[x] = sum[x] = rev[x] = 0;
    }
    int getch(int x) { return (ch[fa[x]][1] == x); }
    int isroot(int x) {
        clear(0);
        return ch[fa[x]][0] != x && ch[fa[x]][1] != x;
    }
    void maintain(int x) {
        clear(0);
//        sum[x] = sum[ls] ^ sum[rs] ^ val[x];
    }
    void pushdown(int x) {
        clear(0);
        if(laz[x]) {
            laz[ls] = laz[rs] = laz[x];
            tim[ls] = tim[rs] = laz[x];
            laz[x] = 0;
        }
        if (rev[x]) {
            rev[ls] ^= 1, swap(ch[ls][0], ch[ls][1]);
            rev[rs] ^= 1, swap(ch[rs][0], ch[rs][1]);
            rev[x] = 0;
        }
    }
    void update(int x) {
        if (!isroot(x)) update(fa[x]);
        pushdown(x);
    }
    void rotate(int x) {
        int y = fa[x], z = fa[y], chx = getch(x), chy = getch(y);
        fa[x] = z;
        if (!isroot(y)) ch[z][chy] = x;
        ch[y][chx] = ch[x][chx ^ 1];
        fa[ch[x][chx ^ 1]] = y;
        ch[x][chx ^ 1] = y;
        fa[y] = x;
        maintain(y);
        maintain(x);
        maintain(z);
    }
    void splay(int x) {
        update(x);
        for (int f = fa[x]; f = fa[x], !isroot(x); rotate(x))
            if (!isroot(f)) rotate(getch(x) == getch(f) ? f : x);
    }
    void access(int x, ll t) {
        for (int f = 0; x; f = x, x = fa[x]) {
            splay(x);
            int lf = f;
            while (ch[lf][0]) lf = ch[lf][0];
            if(lf) splay(lf);
            if(lf && to[x] != lf) {
                to[x] = lf;
                ps.push_back({tim[x] + dep[x] + 1, t + dep[x]});
            }
            if(f) splay(f);
            ch[x][1] = f;
            tim[ch[x][0]] = laz[ch[x][0]] = t;
            if(f) tim[x] = t;
            maintain(x);
        }
    }
} st;


void dfs(int v, ll d) {
    dep[v] = d;
    st.tim[v] = -d;
    for(auto e : G[v]) {
        dfs(e.to, d + e.cost);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n - 1; i++) {
        int u, v, c; cin >> u >> v >> c;
        st.fa[v] = u;
        st.to[u] = v;
        G[u].push_back({v, c});
    }
    dfs(1, 0);
    rep(i, 0, m) {
        int s, t; cin >> s >> t;
        st.access(s, t);
    }
    sort(all(ps), [](const pll &p1, const pll &p2) {
        return p1.second < p2.second;
    });
    rgs[(ll)1e15] = 1;
    int r = 0;
    for(int i = 0; i < sz(ps); i = r) {
        while(r < sz(ps) && ps[i].second == ps[r].second) r++;
        for(int j = i; j < r; j++) {
//            cout << ps[j].first << ", " << ps[j].second << endl;
            auto it = rgs.lower_bound(ps[j].first);
            ll rb = it->first, lb = it->second;
            if(lb > ps[j].second) return cout << ps[j].second << " " << i << "\n", 0;
            rgs.erase(it);
            ll tk = max(lb, ps[j].first);
            if(tk < rb) rgs[rb] = tk + 1;
            if(lb < tk) rgs[tk - 1] = lb;
//            for(auto p : rgs) cout << "(" << p.second << ", " << p.first << "), ";
//            cout << endl;
        }
    }
    cout << -1 << " " << sz(ps) << '\n';


}