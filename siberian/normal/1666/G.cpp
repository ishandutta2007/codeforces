#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

struct Func{
    ld s = 0, ds = 0, d2s = 0;
    int last_z = -1;

    Func() = default;
    Func(ld _s, ld _ds, ld _d2s, int _last_z) : s(_s), ds(_ds), d2s(_d2s), last_z(_last_z) {}

    void relax(int new_z) {
        assert(new_z <= last_z);
        int dz = last_z - new_z;
        s += dz * ds / 2.0;
        ds += -dz * d2s;
        s += dz * ds / 2.0;
        last_z = new_z;
    }

    ld get(int new_z) {
        relax(new_z);
        return s;
    }
};

Func merge(Func lhs, Func rhs) {
    if (lhs.last_z == -1) {
        return rhs;
    }
    if (rhs.last_z == -1) {
        return lhs;
    }
    int new_z = min(lhs.last_z, rhs.last_z);
    lhs.relax(new_z);
    rhs.relax(new_z);
    return {lhs.s + rhs.s, lhs.ds + rhs.ds, lhs.d2s + rhs.d2s, new_z};
}

struct Event{
    int point_id;
    Func f;
    Event() = default;
    Event(int _point_id, const Func& _f) : point_id(_point_id), f(_f) {}
    bool operator<(const Event& other) const {
        return f.last_z > other.f.last_z;
    }
};

struct Query{
    int query_id;
    int point_id;
    int z;
    Query() = default;
    Query(int _query_id, int _point_id, int _z) : query_id(_query_id), point_id(_point_id), z(_z) {}
    bool operator<(const Query& other) const {
        return z > other.z;
    }
};

ld sq(ld x) {
    return x * x;
}

struct Point{
    ld x, y;
    int z;
    int point_id = -1;
    Point() = default;
    Point(ld _x, ld _y, int _z) : x(_x), y(_y), z(_z), point_id(-1) {}
    Point operator-(const Point& other) const {
        return Point(x - other.x, y - other.y, z - other.z);
    }
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y, z + other.z);
    }
    ld len2() const {
        return sq(x) + sq(y) + sq(z);
    }
    void print() const {
        cerr << "x = " << x << " y = " << y << " z = " << z << endl;
    }
};

#define Vec Point

ld dot2x2(ld a11, ld a12, ld a21, ld a22) {
    return a11 * a22 - a12 * a21;
}

ld area(const Vec& lhs, const Vec& rhs) {
    return sqrt(
        sq(dot2x2(lhs.y, lhs.z, rhs.y, rhs.z)) +
        sq(dot2x2(lhs.x, lhs.z, rhs.x, rhs.z)) +
        sq(dot2x2(lhs.x, lhs.y, rhs.x, rhs.y))
        ) / 2;
}

ld area(const Point& a, const Point& b, const Point& c) {
    return area(b - a, c - a);
}

Point getPoint(const Point& p1, const Point& p2, const Point& p3) {
    assert(p1.z > p2.z && p2.z > p3.z);
    Vec v = p3 - p1;
    int dz;
    dz = p1.z - p3.z;
    v.x /= dz;
    v.y /= dz;
    v.z /= dz;
    dz = p1.z - p2.z;
    v.x *= dz;
    v.y *= dz;
    v.z *= dz;
    assert(p1.z + v.z == p2.z);
    return p1 + v;
}

struct Dsu{
    vector<int> par;
    vector<Func> func;
    vector<int> sz;
    Dsu() = default;
    Dsu(int n) : par(n), func(n), sz(n, 1) {
        iota(all(par), 0);
    }
    int getPar(int v) {
        if (v == par[v]) {
            return v;
        }
        return par[v] = getPar(par[v]);
    }
    void uni(int a, int b) {
        a = getPar(a);
        b = getPar(b);
        if (a == b) {
            return;
        }
        if (sz[a] < sz[b]) swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
        func[a] = merge(func[a], func[b]);
    }
    void upd(int point_id, const Func& f) {
        point_id = getPar(point_id);
        func[point_id] = merge(func[point_id], f);
    }
    ld get(int point_id, int z) {
        point_id = getPar(point_id);
        return func[point_id].get(z);
    }
};

int n, m, q;
vector<Point> points;
vector<vector<int>> faces;
vector<vector<int>> edges;
vector<Query> queries;
vector<Event> events;
vector<ld> ans;
vector<bool> ok_ans;
Dsu dsu;
vector<bool> used;

void read() {
    cin >> n;
    points.resize(n);
    used.resize(n);
    dsu = Dsu(n);
    for (int i = 0; i < n; ++i) {
        points[i].point_id = i;
    }
    for (auto& [x, y, z, point_id] : points) {
        cin >> x >> y >> z;
    }
    cin >> m;
    faces.resize(m, vector<int>(3));
    edges.resize(n);
    for (auto& face : faces) {
        for (auto& point_id : face) {
            cin >> point_id;
            --point_id;
        }
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < i; ++j) {
                int u = face[i];
                int v = face[j];
                edges[u].push_back(v);
                edges[v].push_back(u);
            }
        }
        sort(all(face), [&] (int i, int j) {
            return points[i].z > points[j].z;
        });
    }
    cin >> q;
    ans.resize(q);
    ok_ans.resize(q, false);
    queries.resize(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].z >> queries[i].point_id;
        --queries[i].point_id;
        queries[i].query_id = i;
    }
    sort(all(queries));
}

void buildEvents(const Point& p1, const Point& p2, const Point& p3, int it = 0) {
    assert(it <= 1);
    if (p1.z == p2.z && p2.z == p3.z) {
        events.emplace_back(
            p1.point_id, 
            Func(area(p1, p2, p3), 0, 0, p1.z)
            );
    } else if (p1.z > p2.z && p2.z == p3.z) {
        ld s = area(p1, p2, p3);
        int dz = p1.z - p2.z;
        events.emplace_back(
            p1.point_id,
            Func(0, 0, -2 * s / dz / dz, p1.z)
            );
        events.emplace_back(
            p3.point_id,
            Func(0, -2 * s / dz, 2 * s / dz/ dz, p3.z)
            );
    } else if (p1.z == p2.z && p2.z > p3.z) {
        ld s = area(p1, p2, p3);
        int dz = p1.z - p3.z;
        events.emplace_back(
            p1.point_id,
            Func(0, 2 * s / dz, 2 * s / dz / dz, p1.z)
            );
        events.emplace_back(
            p3.point_id,
            Func(0, 0, -2 * s / dz / dz, p3.z)
            );
    } else {
        Point p4 = getPoint(p1, p2, p3);
        buildEvents(p1, p4, p2, it + 1);
        buildEvents(p2, p4, p3, it + 1);
    }
}

void buildEvents() {
    for (auto face : faces) {
        buildEvents(points[face[0]], points[face[1]], points[face[2]]);
    }
    sort(all(events));
}

void process() {
    int pos_events = 0;
    for (const auto& [query_id, point_id, z] : queries) {
        while (pos_events < events.size() && events[pos_events].f.last_z > z) {
            int point_id = events[pos_events].point_id;
            dsu.upd(point_id, events[pos_events].f);
            if (!used[point_id]) {
                used[point_id] = true;
                for (auto neighbour : edges[point_id]) {
                    if (points[neighbour].z >= points[point_id].z) {
                        dsu.uni(point_id, neighbour);
                    }
                }
            }
            ++pos_events;
        }
        if (points[point_id].z > z) {
            ans[query_id] = dsu.get(point_id, z);
            ok_ans[query_id] = true;
        }
    }
}

void outAns() {
    for (int i = 0; i < q; ++i) {
        if (ok_ans[i]) {
            cout << ans[i] << '\n';
        } else {
            cout << "-1\n";
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    read();
    buildEvents();
    process();
    outAns();
    return 0;
}