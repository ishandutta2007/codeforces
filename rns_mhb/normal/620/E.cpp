#include <bits/stdc++.h>
using namespace std;
#define N 400010
#define inf 1000000007
#define eps 1e-7
#define pi acos(-1)
#define gc getchar
#define pc putchar
#define pb push_back

typedef pair <int, int> pii;
typedef long long ll;

template <class T>
inline void chkmax(T &x, T y) {if (x < y) x = y;}

template <class T>
inline void chkmin(T &x, T y) {if (x > y) x = y;}

int n, m, tot, c[N], st[N], en[N], id[N];
bool addv[4*N];
ll tree[4*N];

vector <int> adj[N];

void dfs(int u, int pa) {
    st[u] = ++tot;
    int i, v, sz = adj[u].size();
    for (i = 0; i < sz; i ++) {
        v = adj[u][i];
        if (v == pa) continue;
        dfs(v, u);
    }
    en[u] = tot;
}

#define le v << 1
#define ri v << 1 | 1
#define mi (vl + vr >> 1)

void push_up(int v) {
    tree[v] = tree[le] | tree[ri];
    //if (tree[le] == tree[ri] && addv[le] && addv[ri]) addv[v] = 1;
}

void push_down(int v) {
    if (addv[v]) {
        tree[le] = tree[ri] = tree[v];
        addv[le] = addv[ri] = 1;
        addv[v] = 0;
    }
}

void build(int v, int vl, int vr) {
    if (vl == vr) {
        tree[v] = 1ll << c[id[vl]];
        addv[v] = 1;
    }
    else {
        build(le, vl, mi), build(ri, mi + 1, vr);
        push_up(v);
    }
}

void modify(int v, int vl, int vr, int l, int r, int val) {
    if (l <= vl && vr <= r) {
        tree[v] = 1ll << val, addv[v] = 1;
    }
    else if (l > vr || vl > r) return;
    else {
        push_down(v);
        modify(le, vl, mi, l, r, val);
        modify(ri, mi + 1, vr, l, r, val);
        push_up(v);
    }
}

ll query(int v, int vl, int vr, int l, int r) {
    if (l > vr || vl > r) return 0;
    if ((l <= vl && vr <= r) || addv[v]) return tree[v];
    return query(le, vl, mi, l, r) | query(ri, mi + 1, vr, l, r);
}

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++) scanf("%d", &c[i]);
    for (int i = 1, u, v; i < n; i ++) {
        scanf("%d %d", &u, &v);
        adj[u].pb(v), adj[v].pb(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i ++) id[st[i]] = i;
    build(1, 1, n);
    //for (int i = 1; i <= n; i ++) modify(1, 1, n, st[i], st[i], c[i]);
    while (m --) {
        int u, v;
        scanf("%d", &u);
        if (u == 1) {
            scanf("%d %d", &u, &v);
            modify(1, 1, n, st[u], en[u], v);
        }
        else {
            scanf("%d", &u);
            printf("%d\n", __builtin_popcountll(query(1, 1, n, st[u], en[u])));
        }

    }

    return 0;
}