#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const double EPS = 1e-8;
const int MAXN = 1e6 + 7;
const int LOGN = 30;
vector <vector <int> > gr, binup;
vector <int> height;
vector <int> tin, tout;
int timer = 0;
int n;

void dfs(int v, int p, int h) {
    tin[v] = ++timer;
    binup[0][v] = p;
    height[v] = h;
    for (int i = 1; i < LOGN; i++) {
        if (binup[i - 1][v] == -1) break;
        binup[i][v] = binup[i - 1][binup[i - 1][v]];
    }
    for (int u : gr[v]) {
        if (u == p) continue;
        dfs(u, v, h + 1);
    }
    tout[v] = ++timer;
}

void init() {
    gr.resize(n);
    height.resize(n, 0);
    binup.resize(LOGN, vector <int> (n, -1));
    tin.resize(n, 0);
    tout.resize(n, 0);
}

bool isPred(int v, int p) {
    return tin[v] >= tin[p] && tout[v] <= tout[p];
}

int up(int v, int d) {
    for (int i = LOGN - 1; i >= 0; i--) {
        if (d < (1 << i)) continue;
        d -= (1 << i);
        v = binup[i][v];
    }
    return v;
}

int lca(int v, int u) {
    if (height[v] > height[u]) {
        swap(v, u);
    }
    u = up(u, height[u] - height[v]);
    if (v == u) {
        return v;
    }
    for (int i = LOGN - 1; i >= 0; i--) {
        if (binup[i][v] == binup[i][u]) {
            continue;
        }
        v = binup[i][v];
        u = binup[i][u];
    }
    return binup[0][v];
}

int intersect(int l1, int r1, int l2, int r2) {
    if (height[l2] < height[r1] || height[r2] > height[l1]) {
        return 0;
    }
    int x = lca(l1, l2);
    if (!isPred(l2, r1)) {
        return 0;
    }
    if (!isPred(l1, r2)) {
        return 0;
    }
    return height[lca(l1, l2)] - max(height[r1], height[r2]) + 1;
}

int try_ans(int s, int t, int f) {
    int x = lca(s, f);
    int y = lca(t, f);
    int x1 = up(s, height[s] - height[x] - 1);
    int y1 = up(t, height[t] - height[y] - 1);
    int a1 = 0, a2 = 0, a3 = 0, a4 = 0;
    //cout << s << " " << t << " " << f << endl;
    if (s != x && t != y) {
        //cout << s << " " << x1 << " " << t << " " << y1 << endl;
        a1 = intersect(s, x1, t, y1);
    }
    if (s != x) {
        //cout << s << " " << x1 << " " << f << " " << y << endl;
        a2 = intersect(s, x1, f, y);
    }
    if (t != y) {
        //cout << f << " " << x << " " << t << " " << y1 << endl;
        a3 = intersect(f, x, t, y1);
    }
    //cout << f << " " << x << " " << f << " " << y << endl;
    //cout << endl;
    a4 = intersect(f, x, f, y);
    //cout << a1 << " " << a2 << " " << a3 << " " << a4 << endl;
    return a1 + a2 + a3 + a4;
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //  freopen("output.txt", "w", stdout);
    #endif
    int q;
    cin >> n >> q;
    init();
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;
        gr[p].push_back(i);
        gr[i].push_back(p);
    }
    dfs(0, -1, 0);
    for (int i = 0; i < q; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--, c--;
        int ans1 = try_ans(a, b, c);
        int ans2 = try_ans(a, c, b);
        int ans3 = try_ans(b, c, a);
        cout << max({ans1, ans2, ans3}) << endl;
    }
}