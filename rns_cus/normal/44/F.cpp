#include <bits/stdc++.h>
using namespace std;

#define N 111
#define M 10010

const double ep = 1e-8;
struct pnt{
    double x, y;
    pnt(double x = 0, double y = 0) : x(x), y(y) {}
    pnt operator + (const pnt &p) {
        return pnt(x + p.x, y + p.y);
    }
    pnt operator - (const pnt &p) {
        return pnt(x - p.x, y - p.y);
    }
    pnt operator * (double d) {
        return pnt(x * d, y * d);
    }
    double operator ^ (const pnt &p) {
        return x * p.y - y * p.x;
    }
    bool operator < (const pnt &p) const {
        return abs(x - p.x) < ep ? y < p.y - ep : x < p.x;
    }
    bool operator == (const pnt &p) const {
        return abs(x - p.x) < ep && abs(y - p.y) < ep;
    }
    double operator & (const pnt &p) {
        return x * p.x + y * p.y;
    }
    double dist() {
        return sqrt(x * x + y * y);
    }
    void in() {scanf("%lf %lf", &x, &y);}
};

struct line{
    pnt x, y;
    line(pnt x = pnt(), pnt y = pnt()) : x(x), y(y) {}
    void in() {x.in(), y.in();}
} l[N];

struct node{
    string col;
    vector <int> adj;
    double area;
    int id;
    node(string s, double a, int i) : col(s), area(a), id(i) {}
    void add(int x) {
        adj.push_back(x);
    }
};

vector <pnt> vp;
vector <int> v[N];
vector <node> vnode;

int inter_line(line a, line b, pnt &rlt) {
    double s = a.x - a.y ^ b.x - b.y;
    if (abs(s) < ep) return 0;
    double x = (a.x - b.y ^ b.x - b.y) / s;
    rlt = a.x * (1 - x) + a.y * x;
    return 1;
}

bool inside(pnt p, line l) {
    return abs(p - l.x ^ p - l.y) < ep && (p - l.x & p - l.y) <= 0;
}
typedef pair <int, double> pid;
vector <pid> adj[M];
vector <bool> chk[M];
int m;

inline void add(pnt p) {
    vp.push_back(p);
}

inline double calc(pnt p) {
    return atan2(p.y, p.x);
}

typedef vector <pnt> poly;

vector <poly> vpl;

int bl[M];

double get_area(poly &p) {
    double rlt = 0;
    int n = p.size();
    for (int i = 0, j = 1; i < n; i ++, j ++) {
        if (j == n) j = 0;
        rlt += p[j] ^ p[i];
    }
    return rlt / 2;
}

bool inside_poly(pnt q, poly &p) {
    int crs = 0, n = p.size();
    for (int i = 0, j = 1; i < n; i ++, j ++) {
        if (j == n) j = 0;
        if (inside(q, line(p[i], p[j]))) return 0;
        if (p[i].y <= q.y && q.y < p[j].y || p[j].y <= q.y && q.y < p[i].y) {
            double x = (p[i] - q ^ p[j] - q) * (p[j].y - p[i].y);
            if (x > ep) crs ++;
        }
    }
    return crs & 1;
}

int id[M];

void bfs(int x, string str) {
    queue <int> Q;
    string c = vnode[x].col;
    if (c == str) return;
    Q.push(x); vnode[x].col = str;
    while (!Q.empty()) {
        x = Q.front(); Q.pop();
        for (auto y : vnode[x].adj) if (vnode[y].col == c) {
            vnode[y].col = str; Q.push(y);
        }
    }
}

bool used[M];

int main() {
    int w, h;
    scanf("%d %d", &w, &h); vnode.push_back(node("white", w * h, 0));
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) l[i].in();
    for (int i = 0; i < n; i ++) {
        add(l[i].x), add(l[i].y);
        for (int j = 0; j < i; j ++) {
            pnt tmp;
            if (inter_line(l[i], l[j], tmp) && inside(tmp, l[i]) && inside(tmp, l[j])) add(tmp);
        }
    }
    sort(vp.begin(), vp.end()); m = unique(vp.begin(), vp.end()) - vp.begin(); vp.resize(m);
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) if (inside(vp[j], l[i])) v[i].push_back(j);
    }
    for (int i = 0; i < n; i ++) {
        sort(v[i].begin(), v[i].end());
        v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());
        int sz = v[i].size();
        for (int j = 1; j < sz; j ++) {
            int x = v[i][j-1], y = v[i][j];
            adj[x].push_back(pid(y, calc(vp[y] - vp[x])));
            adj[y].push_back(pid(x, calc(vp[x] - vp[y])));
        }
    }
    for (int i = 0; i < m; i ++) {
        sort(adj[i].begin(), adj[i].end());
        adj[i].erase(unique(adj[i].begin(), adj[i].end(), [&](pid a, pid b) {return a.first == b.first;}), adj[i].end());
        sort(adj[i].begin(), adj[i].end(), [&](pid a, pid b) {return a.second < b.second;});
        chk[i].resize(adj[i].size(), 0);
    }
    int pct = 0;
    memset(bl, -1, sizeof bl);
    for (int i = 0; i < m; i ++) if (bl[i] == -1) {
        bl[i] = ++pct; vnode.push_back(node("black", 0, pct));
        queue <int> q; q.push(i);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto py : adj[u]) {
                int vv = py.first;
                if (bl[vv] < 0) {
                    bl[vv] = pct;
                    q.push(vv);
                }
            }
        }
    }
//    cout << "here " << endl;
//    for (int i = 0; i < m; i ++) {
//        cout << i << " - th point is " << vp[i].x << ' ' << vp[i].y << endl;
//        for (auto j : adj[i]) cout << j.first << ' ' << j.second << "DFDF "; cout << endl;
//    }



    for (int i = 0; i < m; i ++) {
        int sz = adj[i].size();
        for (int j = 0; j < sz; j ++) if (!chk[i][j]) {
            int ii = i, jj = j;
            poly pl;
            while (1) {
                if (chk[ii][jj]) break;
                chk[ii][jj] = 1;
                pl.push_back(vp[ii]);
                int u = adj[ii][jj].first;
                int k, sz = adj[u].size();
                for (k = 0; k < sz; k ++) if (adj[u][k].first == ii) break;
                k = (k + 1) % sz;
                ii = u, jj = k;
            }
            double a = get_area(pl);

            if (a < ep) continue;
            pct ++;
            id[vpl.size()] = pct; vpl.push_back(pl);
            vnode.push_back(node("white", a, pct));
            vnode.back().add(bl[i]);
            vnode[bl[i]].add(pct), vnode[bl[i]].area += a;
        }
    }

    for (int i = 0; i < m; i ++) {
        if (used[bl[i]]) continue;
        used[bl[i]] = 1;
        pnt pt = vp[i];
        int j;
        for (j = vpl.size() - 1; ~j; j --) if (inside_poly(pt, vpl[j])) break;
        node &f = vnode[bl[i]];
        node &g = (j < 0) ? vnode[0] : vnode[id[j]];
        g.area -= f.area, f.area = 0;
        g.add(bl[i]), f.add(g.id);
    }
//    for (auto vv : vnode) cout << vv.area << ' ' << vv.col << endl;
    int runs;
    scanf("%d", &runs);
    while (runs --) {
        pnt pt;
        char s[20];
        pt.in(); scanf("%s", s);
        string str = s;
        bool fg = 0;
        for (int i = 0; i < n; i ++) if (inside(pt, l[i])) {
            fg = 1; bfs(bl[v[i][0]], str); break;
        }
        if (fg) continue;
        for (int i = vpl.size() - 1; ~i; i --) if (inside_poly(pt, vpl[i])) {
            fg = 1; bfs(id[i], str); break;
        }
        if (!fg) bfs(0, str);
    }
    map <string, double> mp;
    for (auto &vv : vnode) mp[vv.col] += vv.area;
    for (auto it : mp) {
        printf("%s %.8lf\n", it.first.c_str(), it.second);
//        cout << it.second << endl;
    }

    return 0;
}