#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(a) (a).begin(), (a).end()
#define mp make_pair

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

int sign(ll x) {
    if (x < 0) return -1;
    if (x > 0) return 1;
    return 0; 
}

struct Dsu{
    vector<int> par;
    Dsu() {}
    Dsu(int n) {
        par.resize(n);
        iota(all(par), 0);
    }
    int getPar(int v) {
        if (v == par[v]) return v;
        return par[v] = getPar(par[v]);
    }
    bool connect(int a, int b) {
        return getPar(a) == getPar(b);
    }
    void uni(int a, int b) {
        a = getPar(a);
        b = getPar(b);
        par[b] = a;
    }
};

struct Point{
    int x, y;
};

ll operator^(const Point& a, const Point& b) {
    return (ll)a.x * b.y - (ll)a.y * b.x;
}

Point operator-(const Point& a, const Point& b) {
    return {a.x - b.x, a.y - b.y};
}

const int N = 2e3 + 10;
int n;
Point a[N];
int p[N];
int order[N];
bool used[N];
Dsu dsu;

int compressed[N];
int topCompressed = 0;

void compress() {
    for (int i = 0; i < n; ++i) {
        if (p[i] == i) continue;
        compressed[topCompressed++] = i;
    }
    int ptr = 0;
    for (int i = 0; i < n; ++i) {
        if (p[i] == i) continue;
        p[i] = lower_bound(compressed, compressed + topCompressed, p[i]) - compressed;
        swap(a[i], a[ptr]);
        swap(p[i], p[ptr]);
        ++ptr;
    }
    n = ptr;
}

void dfs(int v) {
    used[v] = true;
    dsu.uni(v, p[v]);
    if (used[p[v]]) return;
    dfs(p[v]);
}

int topAns = 0;
int ans[N * N][2];

void addAns(int a, int b) {
    ans[topAns][0] = a;
    ans[topAns][1] = b;
    swap(p[a], p[b]);
    dsu.uni(a, b);
    ++topAns;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y >> p[i];
        --p[i];
    }
    compress();
    dsu = Dsu(n);
    for (int i = 0; i < n; ++i) {
        if (used[i]) continue;
        dfs(i);
    }
    int pos = min_element(a, a + n, [] (const Point& x, const Point& y) {
        return tie(x.x, x.y) < tie(y.x, y.y);
    }) - a;
    iota(order, order + n, 0);
    sort(order, order + n, [&] (int x, int y) {
        Point va = a[x] - a[pos];
        Point vb = a[y] - a[pos];
        if (sign(va ^ vb) == 0) {
            return x == pos;
        }
        return sign(va ^ vb) == 1;
    });
    assert(order[0] == pos);
    for (int i = 1; i + 1 < n; ++i) {
        if (!dsu.connect(order[i], order[i + 1])) {
            addAns(order[i], order[i + 1]);
        }
    }

    for (int i = 1; i < n; ++i) {
        addAns(order[0], p[order[0]]);
    }

    cout << topAns << '\n';
    for (int i = 0; i < topAns; ++i) {
        cout << compressed[ans[i][0]] + 1 << " " << compressed[ans[i][1]] + 1 << '\n';
    }
    return 0;
}