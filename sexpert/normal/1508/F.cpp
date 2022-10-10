#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

const int N = 25005, Q = 100005, D = 80;

int n, q, a[N], l[Q], r[Q], pos[N], ans[Q];

vector<pair<int, int>> edges;
vector<int> in, out, guys[N];
vector<pair<int, int>> l_edge[N], r_edge[N];
vector<array<int, 3>> eve[N];
vector<pair<int, int>> add[N];

struct fenwick_tree {
    int bit[N];

    void init() {
        fill(bit + 1, bit + n + 1, Q);
    }

    void update(int u, int v) {
        for (; u > 0; u -= u & -u) {
            bit[u] = min(bit[u], v);
        }
    }
    
    int query(int u) {
        int ans = Q;
        for (; u <= n; u += u & -u) {
            ans = min(ans, bit[u]);
        }
        return ans;
    }
} bit;

int bit2[N];

void update(int u, int v) {
    for(; u <= n; u += u & -u)
        bit2[u] += v;
}

int query(int u) {
    if(u == 0)
        return 0;
    int ans = 0;
    for(; u; u -= u & -u)
        ans += bit2[u];
    return ans;
}

int find_last(int s) {
    if(s == -1)
        return -1;
    int p = 0;
    for(int l = 14; l >= 0; l--) {
        if(p + (1 << l) <= n && bit2[p + (1 << l)] <= s) {
            p += (1 << l);
            s -= bit2[p];
        }
    }
    return p;
}

void r_sort(vector<pair<int, int>> &v) {
    int m = v.size();
    for(auto &[l, r] : v)
        guys[r].push_back(l);
    int p = 0;
    for(int r = 1; r <= n; r++) {
        for(auto l : guys[r])
            v[p++] = {l, r};
        guys[r].clear();
    }
    for(auto &[l, r] : v)
        guys[l].push_back(r);
    p = 0;
    for(int l = 1; l <= n; l++)
        for(auto r : guys[l])
            v[p++] = {l, r};
}

void find_all_edges() {
    auto add = [&](int u) {
        int val = a[u], su = query(val);
        int ri = find_last(su), le = find_last(su - 1);
        if(le != -1)
            edges.push_back({le + 1, val});
        if(ri != n)
            edges.push_back({val, ri + 1});
        update(val, 1);
    };

    auto rem = [&](int u) {
        int val = a[u];
        update(val, -1);
        int su = query(val);
        int ri = find_last(su), le = find_last(su - 1);
        if(le != -1 && ri != n)
            edges.push_back({le + 1, ri + 1});
    };

    vector<int> segs(q);
    iota(segs.begin(), segs.end(), 1);
    sort(segs.begin(), segs.end(), [](const int u, const int v) {
        if(l[u] / D != l[v] / D)
            return l[u] / D < l[v] / D;
        if((l[u] / D) % 2)
            return r[u] > r[v];
        else
            return r[u] < r[v];
    });

    int pr = 0, pl = 1;
    for (auto &idx : segs) {
        while(pr < r[idx]) add(++pr);
        while(pl > l[idx]) add(--pl);
        while(pr > r[idx]) rem(pr--);
        while(pl < l[idx]) rem(pl++);
    }

    r_sort(edges);
    edges.erase(unique(edges.begin(), edges.end()), edges.end());
    in = vector<int>(edges.size(), Q - 1);
    out = vector<int>(edges.size(), Q - 1);
}

void build_events() {
    for (int i = 0; i < edges.size(); i++) {
        auto [u, v] = edges[i];
        int iu = pos[u], iv = pos[v];
        (iv > iu ? r_edge : l_edge)[iu].push_back({iv, i});
    }
    for (int i = 1; i <= n; i++) {
        vector<pair<int, int>> &le = l_edge[i], &re = r_edge[i];
        reverse(le.begin(), le.end());
        reverse(re.begin(), re.end());
        // border values to make the implementation easier
        le.push_back({0, -1});
        re.push_back({n + 1, -1});

        int pl = 0, pr = 0;
        while (pl < le.size() - 1 || pr < re.size() - 1) {
            if (a[le[pl].first] > a[re[pr].first]) {
                int qi = le[pl].second;
                int u = i, v = le[pl].first; // (edge u => v, go to left)
                int t = re[pr].first;
                int vn = le[pl + 1].first;

                // edge (u => v) appears when there's a query covers the range [v, u],
                // and disappear when there's a query covers the range [v, t] or [vn, u]
                eve[v].push_back({u, qi, 0});
                eve[vn].push_back({u, qi, 1});
                eve[v].push_back({t, qi, 1});

                pl++;
            } else {
                int qi = re[pr].second;
                int u = i, w = re[pr].first; // (edge u => w, go to right)
                int t = le[pl].first;
                int wn = re[pr + 1].first;

                // edge (u => w) appears when there's a query covers the range [u, w],
                // and disappear when there's a query covers the range [t, w] or [u, wn]
                eve[u].push_back({w, qi, 0});
                eve[t].push_back({w, qi, 1});
                eve[u].push_back({wn, qi, 1});

                pr++;
            }
        }
    }

    for (int i = 1; i <= q; i++) {
        add[l[i]].push_back({r[i], i});
    }
}

void solve() {
    bit.init();
    for (int i = 1; i <= n; i++) {
        for (auto [r, v] : add[i]) {
            bit.update(r, v);
        }
        for (auto [r, i, t] : eve[i]) {
            int &upd = (t == 0 ? in[i] : out[i]);
            upd = min(upd, bit.query(r));
        }
    }
    for (int i = 0; i < edges.size(); i++) {
        ans[in[i]]++;
        ans[out[i]]--;
    }
    for (int i = 1; i <= q; i++) {
        ans[i] += ans[i - 1];
        cout << ans[i] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    for (int i = 1; i <= q; i++) {
        cin >> l[i] >> r[i];
    }
    find_all_edges();
    build_events();
    solve();
}