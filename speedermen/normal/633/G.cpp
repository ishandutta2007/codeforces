#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int MD = 1000000007;

#define ll long long
#define pb push_back
#define mp make_pair
#define X first
#define Y second

bitset <1005> t[4 * N];
int n, m, ti, f[N], ord[N];
int tin[N], tout[N];
ll add[4 * N];
vector < int > g[N];

void psh(int i, int l, int r) {
    add[i] %= m;
    if (add[i] > 0) {
        if (l < r) add[2 * i] += add[i], add[2 * i + 1] += add[i];
        int x = add[i];
//      0 -> x, 1 -> x+1, 2 -> x+2, 3 -> x+3, m-x -> 0
        t[i] = (t[i] << x) | (t[i] >> (m - x));
        add[i] = 0;
    }
}

void addv(int i, int tl, int tr, int l, int r, int val) {
    psh(i, tl, tr);
    if (l == tl && tr == r) {
        add[i] += val;
        psh(i, tl, tr);
        return;
    }
    int tm = (tl + tr) >> 1;
    psh(2 * i, tl, tm);
    psh(2 * i + 1, tm + 1, tr);
    if (r <= tm)
        addv(2 * i, tl, tm, l, r, val);
    else if (l > tm)
        addv(2 * i + 1, tm + 1, tr, l, r, val);
    else {
        addv(2 * i, tl, tm, l, tm, val);
        addv(2 * i + 1, tm + 1, tr, tm + 1, r, val);
    }
    t[i] = t[2 * i] | t[2 * i + 1];
}

bitset <1005> getv(int i, int tl , int tr, int l, int r) {
    psh(i, tl, tr);
    if (l == tl && r == tr)
        return t[i];
    int tm = (tl + tr) >> 1;
    psh(2 * i, tl, tm);
    psh(2 * i + 1, tm + 1, tr);
    bitset <1005> rs;
    if (r <= tm)
        rs = getv(2 * i, tl, tm, l, r);
    else if (l > tm)
        rs = getv(2 * i + 1, tm + 1, tr, l, r);
    else rs = getv(2 * i, tl, tm, l, tm) | getv(2 * i + 1, tm + 1, tr, tm + 1, r);
    t[i] = t[2 * i] | t[2 * i + 1];
    return rs;
}

void build(int i, int l, int r) {
    if (l == r) {
        t[i][ord[l]] = 1;
        return;
    }
    int m = (l + r) >> 1;
    build(2 * i, l, m);
    build(2 * i + 1, m + 1, r);
    t[i] = t[2 * i] | t[2 * i + 1];
}

void dfs(int v, int p) {
    ord[ti] = f[v] % m;
    tin[v] = ti++;
    for (int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (to == p) continue;
        dfs(to, v);
    }
    tout[v] = ti;
}

int main()
{
 // freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> f[i];
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    bitset <1005> primes;
    for (int i = 2; i < m; ++i) {
        primes[i] = 1;
        for (int j = 2; j * j <= i; ++j)
            if (i % j == 0)
                primes[i] = 0;
    }
    dfs(1, 0);
    build(1, 0, n - 1);
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int v, x;
            cin >> v >> x;
            addv(1, 0, n - 1, tin[v], tout[v] - 1, x);
        } else {
            int y;
            cin >> y;
            cout << (getv(1, 0, n - 1, tin[y], tout[y] - 1) & primes).count() << '\n';
        }
    }
    return 0;
}