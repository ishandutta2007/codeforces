#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 1e5 + 10;
int rep[MAXN], eq[MAXN], sz[MAXN], res[MAXN], ans = 1, n, q;
map<ii, vector<ii>> qs;
vector<array<int, 4>> ops;

ii find(int u) {
    if(u == rep[u])
        return {u, 0};
    auto p = find(rep[u]);
    return {p.first, p.second ^ eq[u]};
}

void join(int u, int v) {
    auto p1 = find(u), p2 = find(v);
    u = p1.first;
    v = p2.first;
    int pa = ans;
    int na = p1.second ^ p2.second;
    if(sz[u] < sz[v])
        swap(u, v);
    if(u == v) {
        ans &= na;
        ops.push_back({u, v, -1, pa});
        return;
    }
    ops.push_back({u, v, 1, pa});
    rep[v] = u;
    sz[v] += sz[u];
    eq[v] = na ^ 1;
}

void undo() {
    auto op = ops.back(); ops.pop_back();
    if(op[2] == -1)
        ans = op[3];
    else {
        rep[op[1]] = op[1];
        eq[op[1]] = 0;
        sz[op[0]] -= sz[op[1]];
    }
}

void solve(int l, int r) {
    for(auto q : qs[{l, r}])
        join(q.first, q.second);
    if(l == r)
        res[l] = ans;
    else {
        int m = (l + r)/2;
        solve(l, m);
        solve(m + 1, r);
    }
    for(auto q : qs[{l, r}])
        undo();
}

void decomp(int l, int r, int rl, int rr, ii e) {
    if(r < rl || rr < l)
        return;
    if(rl <= l && r <= rr) {
        //cout << "[" << l << ", " << r << "] " << e.first << "-" << e.second << '\n';
        qs[{l, r}].push_back(e);
        return;
    }
    int m = (l + r)/2;
    decomp(l, m, rl, rr, e);
    decomp(m + 1, r, rl, rr, e);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    iota(rep, rep + MAXN, 0);
    fill(sz, sz + MAXN, 1);
    map<ii, int> lst;

    cin >> n >> q;
    for(int i = 1; i <= q; i++) {
        int u, v;
        cin >> u >> v;
        if(lst.count({u, v})) {
            int l = lst[{u, v}];
            lst.erase({u, v});
            decomp(1, q, l, i - 1, {u, v});
        }
        else
            lst[{u, v}] = i;
    }
    for(auto p : lst) {
        int l = p.second;
        decomp(1, q, l, q, p.first);
    }
    solve(1, q);
    for(int i = 1; i <= q; i++)
        cout << (res[i] ? "YES" : "NO") << '\n';
}