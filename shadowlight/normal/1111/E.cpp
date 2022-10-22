#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-6;
const int LOGN = 20;

vector <vector <int> > gr;

vector <int> lt, rt, he;
vector <vector <int> > binup;
int timer = 0;

void dfs(int v, int p, int h) {
    he[v] = h;
    binup[0][v] = p;
    lt[v] = timer++;
    for (int i = 1; i < LOGN; i++) {
        if (binup[i - 1][v] == -1) continue;
        binup[i][v] = binup[i - 1][binup[i - 1][v]];
    }
    for (int u : gr[v]) {
        if (u == p) continue;
        dfs(u, v, h + 1);
    }
    rt[v] = timer - 1;
}

int up(int v, int h) {
    for (int i = LOGN - 1; i >= 0; i--) {
        if ((1 << i) > h) continue;
        v = binup[i][v];
        h -= 1 << i;
    }
    return v;
}

int lca(int v, int u) {
    if (he[v] > he[u]) {
        swap(v, u);
    }
    u = up(u, he[u] - he[v]);
    if (v == u) {
        return v;
    }
    for (int i = LOGN - 1; i >= 0; i--) {
        if (binup[i][v] == binup[i][u]) continue;
        v = binup[i][v];
        u = binup[i][u];
    }
    return binup[0][v];
}

int n;

struct Tree {
    vector <int> t, valt;
    Tree() : t(4 * n, 0), valt(4 * n, 0) {}
    void relax(int v) {
        t[v] = t[2 * v] + t[2 * v + 1];
    }
    void add_val(int v, int val) {
        t[v] += val;
        valt[v] += val;
    }
    void push(int v) {
        add_val(2 * v, valt[v]);
        add_val(2 * v + 1, valt[v]);
        valt[v] = 0;
    }
    void add_seg(int l, int r, int val, int lt = 0, int rt = n, int v = 1) {
        if (l >= rt || lt >= r) {
            return;
        }
        if (l <= lt && rt <= r) {
            add_val(v, val);
            return;
        }
        int mt = (lt + rt) / 2;
        push(v);
        add_seg(l, r, val, lt, mt, 2 * v);
        add_seg(l, r, val, mt, rt, 2 * v + 1);
        relax(v);
    }
    int get(int l, int r, int lt = 0, int rt = n, int v = 1) {
         if (l >= rt || lt >= r) {
            return 0;
        }
        if (l <= lt && rt <= r) {
            return t[v];
        }
        int mt = (lt + rt) / 2;
        push(v);
        int res = get(l, r, lt, mt, 2 * v) + get(l, r, mt, rt, 2 * v + 1);
        relax(v);
        return res;
    }
};

void add(int &x, int y) {
    x += y;
    if (x >= INF) {
        x -= INF;
    }
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int q;
    cin >> n >> q;
    gr.resize(n);
    lt.resize(n);
    he.resize(n);
    rt.resize(n);
    binup.resize(LOGN, vector <int> (n, 0));
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        gr[v].push_back(u);
        gr[u].push_back(v);
    }
    Tree tt = Tree();
    dfs(0, -1, 0);
    for (int i = 0; i < q; i++) {
        int k, m, r;
        cin >> k >> m >> r;
        r--;
        vector <int> a(k);
        set <int> q;
        for (int j = 0; j < k; j++) {
            cin >> a[j];
            a[j]--;
            int v = a[j];
            q.insert(v);
            tt.add_seg(lt[v], rt[v] + 1, 1);
            //cout << lt[v] << " " << rt[v] << "\n";
        }
        int hr = tt.get(lt[r], lt[r] + 1);
        vector <int> h(k);
        vector <pair <int, int> > ha;
        for (int j = 0; j < k; j++) {
            int v = a[j];
            int t = lca(r, v);
            int hv = tt.get(lt[v], lt[v] + 1);
            int ht = tt.get(lt[t], lt[t] + 1);
            h[j] = hv + hr - 2 * ht + (int) (q.find(t) != q.end()) - 1;
            //cout << hv << " " << hr << " " << ht << "\n";
            //cout << h[j] << " ";
        }
        //cout << "\n";
        sort(h.begin(), h.end());
        vector <vector <int> > dp(k + 1, vector <int> (m + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = ((ll) dp[i - 1][j] * (ll) max(j - h[i - 1], 0) + (ll) dp[i - 1][j - 1]) % INF;
            }
        }
        int res = 0;
        for (int j = 1; j <= m; j++) {
            add(res, dp[k][j]);
        }
         for (int j = 0; j < k; j++) {
            int v = a[j];
            tt.add_seg(lt[v], rt[v] + 1, -1);
        }
        cout << res << "\n";
    }
}