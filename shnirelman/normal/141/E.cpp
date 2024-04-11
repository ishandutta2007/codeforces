#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li
#define err if(debug_out)cout

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pld = pair<ld, ld>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 2e5 + 13;
const int LOGN = 20;
const int K = 22;
const int M = 998244353;//1e9 + 7;
//const int A = 26;
const ld eps = 1e-8;

mt19937 rnd(45768);

/*
*/

int p[N], sz[N];

int get(int x) {
    return (x == p[x] ? x : p[x] = get(p[x]));
}

bool unite(int x, int y) {
    x = get(x);
    y = get(y);

    if(x == y)
        return false;

    if(sz[x] < sz[y])
        swap(x, y);

    p[y] = x;
    sz[x] += sz[y];

    return true;
}

void build(int n) {
    for(int i = 0; i < n; i++) {
        p[i] = i;
        sz[i] = 1;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pair<pii, int>> a, b;
    for(int i = 0; i < m; i++) {
        char c;
        int v, u;
        cin >> v >> u >> c;

        v--;
        u--;

        if(v == u)
            continue;

        if(c == 'S') {
            a.emplace_back(pii(v, u), i);
        } else {
            b.emplace_back(pii(v, u), i);
        }
    }

    if(n % 2 == 0 || a.size() < n / 2 || b.size() < n / 2) {
        cout << -1 << endl;
        return 0;
    }

    build(n);

    for(auto p : a) {
        unite(p.f.f, p.f.s);
    }

    int ca = 0, cb = 0;
    vector<bool> isa(a.size(), false), isb(b.size(), false);


    for(int i = 0; i < b.size(); i++) {
        if(unite(b[i].f.f, b[i].f.s)) {
            cb++;
            isb[i] = true;
        }
    }

    if(cb > n / 2 || sz[get(0)] != n) {
        cout << -1 << endl;
        return 0;
    }

    build(n);
    for(int i = 0; i < b.size(); i++) {
        if(isb[i]) {
            unite(b[i].f.f, b[i].f.s);
        }
    }

    for(int i = 0; i < b.size() && cb < n / 2; i++) {
        if(!isb[i] && unite(b[i].f.f, b[i].f.s)) {
            cb++;
            isb[i] = true;
        }
    }

    if(cb < n / 2) {
        cout << -1 << endl;
        return 0;
    }

    for(int i = 0; i < a.size() && ca < n / 2; i++) {
        if(unite(a[i].f.f, a[i].f.s)) {
            ca++;
            isa[i] = true;
        }
    }

    if(ca < n / 2) {
        cout << -1 << endl;
        return 0;
    }

    cout << n - 1 << endl;
    for(int i = 0; i < a.size(); i++) {
        if(isa[i])
            cout << a[i].s + 1 << ' ';
    }

    for(int i = 0; i < b.size(); i++) {
        if(isb[i])
            cout << b[i].s + 1 << ' ';
    }
    cout << endl;
}