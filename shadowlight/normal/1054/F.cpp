#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

set <pair <int, int> > points;
vector <vector <int> > gr;
vector <bool> used;
vector <int> pr;

bool dfs(int v) {
    if (used[v]) return false;
    used[v] = true;
    for (int u : gr[v]) {
        if (pr[u] == -1 || dfs(pr[u])) {
            pr[u] = v;
            return true;
        }
    }
    return false;
}

int kuhn(int n, int m) {
    pr.resize(m, -1);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        used.assign(n, false);
        cnt += dfs(i);
    }
    return cnt;
}

struct Seg {
    int x, l, r, id;
};

bool operator<(Seg a, Seg b) {
    if (a.x != b.x) {
        return a.x < b.x;
    }
    return a.l < b.l;
}

vector <vector <int> > g;
vector <Seg> sx, sy;

vector <bool> ch;

void dfs1(int v) {
    if (used[v] || !ch[v]) return;
    used[v] = true;
    assert(ch[v]);
    for (int u : g[v]) {
        if (ch[u]) {
            assert(pr[u - sx.size()] != -1);
            ch[u] = false;
            ch[pr[u - sx.size()]] = true;
            used[pr[u - sx.size()]] = false;
            dfs1(pr[u - sx.size()]);
        }
    }
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopens(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int n;
    cin >> n;
    map <int, vector <int> > dx, dy;
    vector <pair <int, int> > solox, soloy;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.insert({x, y});
        dx[x].push_back(y);
        dy[y].push_back(x);
    }
    int last = 0;
    for (auto &p : dx) {
        int x = p.first;
        vector <int> a = p.second;
        sort(a.begin(), a.end());
        if (a.size() == 1) {
            solox.push_back({x, a[0]});
        }
        for (int i = 1; i < (int) a.size(); i++) {
            sx.push_back({x, a[i - 1], a[i]});
        }
    }
    for (auto &p : dy) {
        int x = p.first;
        vector <int> a = p.second;
        sort(a.begin(), a.end());
        if (a.size() == 1) {
            soloy.push_back({x, a[0]});
        }
        for (int i = 1; i < (int) a.size(); i++) {
            sy.push_back({x, a[i - 1], a[i]});
        }
    }
    sort(sx.begin(), sx.end());
    sort(sy.begin(), sy.end());
    for (auto &p : sx) {
        p.id = last++;
    }
    last = 0;
    for (auto &p : sy) {
        p.id = last++;
    }
    gr.resize(sx.size());
    g.resize(sx.size() + sy.size());
    for (auto a : sx) {
        for (auto b : sy) {
            if (a.l > b.x || a.r < b.x) continue;
            if (b.l > a.x || b.r < a.x) continue;
            if (points.find({a.x, b.x}) != points.end()) continue;
            gr[a.id].push_back(b.id);
            g[a.id].push_back(b.id + sx.size());
            g[b.id + sx.size()].push_back(a.id);
            //cout << a.id << " " << b.id << "\n";
            //cout << a.x << " " << a.l << " " << a.r << " " << b.x << " " << b.l << " " << b.r << "\n";
        }
    }
    int cnt = kuhn(sx.size(), sy.size());
    int all = sx.size() + sy.size();
    ch.resize(all, true);
    used.clear();
    used.assign(all, false);
    for (int i = 0; i < (int) sy.size(); i++) {
        if (pr[i] != -1) {
            ch[pr[i]] = false;
        }
    }
    for (int i = 0; i < (int) sx.size(); i++) {
        dfs1(i);
    }
    for (int v = 0; v < all; v++) {
        for (int u : g[v]) {
            assert(!ch[v] || !ch[u]);
        }
    }
    vector <Seg> res;
    int nx = -1;
    int l = -1, r = -1;
    for (auto a : sy) {
        if (a.x != nx) {
            if (l != -1) {
                res.push_back({nx, l, r});
            }
            nx = a.x;
            l = a.l;
            r = a.l;
        }
        if (ch[a.id + sx.size()]) {
            r = a.r;
        } else {
            res.push_back({nx, l, r});
            l = a.r, r = a.r;
        }
    }
    if (l != -1) {
        res.push_back({nx, l, r});
    }
    for (auto p : soloy) {
        res.push_back({p.first, p.second, p.second});
    }
    cout << res.size() << "\n";
    for (auto a : res) {
        cout << a.l << " " << a.x << " " << a.r << " " << a.x << "\n";
    }
    res.clear();
    nx = -1, l = -1, r = -1;
    for (auto a : sx) {
        if (a.x != nx) {
            if (l != -1) {
                res.push_back({nx, l, r});
            }
            nx = a.x;
            l = a.l;
            r = a.l;
        }
        if (ch[a.id]) {
            r = a.r;
        } else {
            res.push_back({nx, l, r});
            l = a.r, r = a.r;
        }
    }
    if (l != -1) {
        res.push_back({nx, l, r});
    }
    for (auto p : solox) {
        res.push_back({p.first, p.second, p.second});
    }
    cout << res.size() << "\n";
    for (auto a : res) {
        cout << a.x << " " << a.l << " " << a.x << " " <<  a.r << "\n";
    }
    res.clear();
}