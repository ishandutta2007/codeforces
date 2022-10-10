#include <bits/stdc++.h>
using namespace std;

#define double long double

const int MAX = 2e5 + 5;
const double EPS = 1e-9;

struct Point {
    double x, y, z;
    
    Point(double _x = 0, double _y = 0, double _z = 0) : x(_x), y(_y), z(_z) {}
    
    Point operator - (const Point &p) const {
        return Point(x - p.x, y - p.y, z - p.z);
    }
    
    Point cross(const Point &p) const {
        return Point(y * p.z - z * p.y, z * p.x - x * p.z, x * p.y - y * p.x);
    }
    
    // change back to sqrt if using double
    double mag() const {
        return sqrtl(x * x + y * y + z * z);
    }
};

double area(const Point &a, const Point &b, const Point &c) {
    return (c - a).cross(b - a).mag() / 2;
}

struct Quadratic {
    double a, b, c;
    
    Quadratic(double _a = 0, double _b = 0, double _c = 0) : a(_a), b(_b), c(_c) {}
    
    double eval(int x) {
        return a * x * x + b * x + c;
    }
    
    Quadratic operator + (const Quadratic &other) const {
        return Quadratic(a + other.a, b + other.b, c + other.c);
    }
    
    Quadratic operator - (const Quadratic &other) const {
        return Quadratic(a - other.a, b - other.b, c - other.c);
    }
};

int par[MAX], sz[MAX];
double full[MAX];
Quadratic quad[MAX];

int find(int u) {
    return par[u] == u ? u : par[u] = find(par[u]);
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
        return;
    if (sz[u] < sz[v])
        swap(u, v);
    par[v] = u;
    sz[u] += sz[v];
    full[u] += full[v];
    quad[u] = quad[u] + quad[v];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<Point> pt(n);
    for (int i=0; i<n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        pt[i] = Point(x, y, z);
    }
    int m;
    cin >> m;
    vector<int> a(m), b(m), c(m);
    vector<vector<int>> faces(n);
    vector<double> partA(m), partB(m);
    for (int i=0; i<m; i++) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--, b[i]--, c[i]--;
        if (pt[a[i]].z < pt[b[i]].z)
            swap(a[i], b[i]);
        if (pt[b[i]].z < pt[c[i]].z)
            swap(b[i], c[i]);
        if (pt[a[i]].z < pt[b[i]].z)
            swap(a[i], b[i]);
        faces[a[i]].push_back(i);
        faces[b[i]].push_back(i);
        faces[c[i]].push_back(i);
        if (abs(pt[a[i]].z - pt[c[i]].z) < EPS) {
            partA[i] = area(pt[a[i]], pt[b[i]], pt[c[i]]);
        } else {
            double nx = pt[a[i]].x + (pt[c[i]].x - pt[a[i]].x) * (pt[a[i]].z - pt[b[i]].z) / (pt[a[i]].z - pt[c[i]].z);
            double ny = pt[a[i]].y + (pt[c[i]].y - pt[a[i]].y) * (pt[a[i]].z - pt[b[i]].z) / (pt[a[i]].z - pt[c[i]].z);
            Point other(nx, ny, pt[b[i]].z);
            partA[i] = area(pt[a[i]], pt[b[i]], other);
            partB[i] = area(pt[b[i]], pt[c[i]], other);
        }
    }
    int q;
    cin >> q;
    vector<array<int, 3>> queries;
    for (int i=0; i<q; i++) {
        int h, p;
        cin >> h >> p;
        p--;
        queries.push_back({h, p, i});
    }
    
    vector<pair<double, int>> pts(n);
    for (int i=0; i<n; i++)
        pts[i] = {pt[i].z, i};
    sort(queries.rbegin(), queries.rend());
    sort(pts.rbegin(), pts.rend());
    
    for (int i=0; i<n+m; i++) {
        par[i] = i;
        sz[i] = 1;
    }
    
    int j = 0;
    vector<Quadratic> last(m);
    vector<int> cnt(m);
    vector<double> ret(q);
    for (auto [h, p, i] : queries) {
        while (j < n && pts[j].first > h) {
            auto [z, idx] = pts[j++];
            for (int k : faces[idx]) {
                unite(idx, n + k);
                int u = find(n + k);
                cnt[k]++;
                if (cnt[k] == 1) {
                    double factor = abs(pt[a[k]].z - pt[b[k]].z) < EPS ? 0 : partA[k] / ((pt[a[k]].z - pt[b[k]].z) * (pt[a[k]].z - pt[b[k]].z));
                    last[k] = Quadratic(factor, -factor * 2 * pt[a[k]].z, factor * pt[a[k]].z * pt[a[k]].z);
                    quad[u] = quad[u] + last[k];
                } else if (cnt[k] == 2) {
                    quad[u] = quad[u] - last[k];
                    double factor = abs(pt[b[k]].z - pt[c[k]].z) < EPS ? 0 : partB[k] / ((pt[b[k]].z - pt[c[k]].z) * (pt[b[k]].z - pt[c[k]].z));
                    last[k] = Quadratic(-factor, factor * 2 * pt[c[k]].z, partB[k] - factor * pt[c[k]].z * pt[c[k]].z);
                    quad[u] = quad[u] + last[k];
                    full[u] += partA[k];
                } else {
                    quad[u] = quad[u] - last[k];
                    full[u] += partB[k];
                }
            }
        }
        if (pt[p].z - h < EPS) {
            ret[i] = -1;
        } else {
            int u = find(p);
            ret[i] = quad[u].eval(h) + full[u];
        }
    }
    
    cout << fixed << setprecision(10);
    for (double x : ret)
        cout << x << "\n";
    
    return 0;
}