//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
#define x first
#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
//using matr

const li INF = 1e18 + 13;
const int N = 1000 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;
const int K = 8;

mt19937 rnd(0);

struct DSU {
    vector<int> p, sz;

    DSU(int n) {
        p.resize(n);
        sz.resize(n);
        for(int i = 0; i < n; i++) {
            p[i] = i;
            sz[i] = 1;
        }
    };

    int getp(int x) {
        return (x == p[x] ? x : p[x] = getp(p[x]));
    }

    void unite(int x, int y) {
        x = getp(x);
        y = getp(y);

        if(x == y)
            return;

        if(sz[x] < sz[y])
            swap(x, y);

        p[y] = x;
        sz[x] += sz[y];
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m1, m2;
    cin >> n >> m1 >> m2;

    DSU dsu1(n), dsu2(n);

    for(int i = 0; i < m1; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        dsu1.unite(v, u);
    }

    for(int i = 0; i < m2; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        dsu2.unite(v, u);
    }

    vector<pii> ans;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(dsu1.getp(i) != dsu1.getp(j) && dsu2.getp(i) != dsu2.getp(j)) {
                ans.emplace_back(i, j);
                dsu1.unite(i, j);
                dsu2.unite(i, j);
            }
        }
    }

    cout << ans.size() << endl;

    for(auto p : ans)
        cout << p.f + 1 << ' ' << p.s + 1 << endl;
}