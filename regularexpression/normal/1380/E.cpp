#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define pw(x) (1LL<<x)
#define epr(...) fprintf(stderr, __VA_ARGS__); fflush(stderr)

#define db(x) cerr << #x << " = " << x << '\n'
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " < y << ")\n"
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << '\n'

typedef long long ll;
typedef double dbl;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    vector<int> t(n);
    for (auto& id: t) {
        scanf("%d", &id);
        --id;
    }

    int dif = 0;
    for (int i = 0; i + 1 < n; ++i) {
        if (t[i] != t[i + 1]) {
            ++dif;
        }
    }
    auto upd = [&](int id, int val) {
        if (id > 0 && t[id] != t[id - 1]) {
            --dif;
        }
        if (id + 1 < n && t[id] != t[id + 1]) {
            --dif;
        }
        t[id] = val;
        if (id > 0 && t[id] != t[id - 1]) {
            ++dif;
        }
        if (id + 1 < n && t[id] != t[id + 1]) {
            ++dif;
        }
    };

    vector<int> p(m);
    vector<vector<int>> ids(m);
    for (int i = 0; i < m; ++i) {
        p[i] = i;
    }
    for (int i = 0; i < n; ++i) {
        ids[t[i]].pb(i);
    }

    function<int(int)> getId = [&](int v)->int {
        if (p[v] == v) {
            return v;
        }
        p[v] = getId(p[v]);
        return p[v];
    };
    auto mergeIds = [&](int v, int u) {
        v = getId(v);
        u = getId(u);
        if (v != u) {
            if (sz(ids[v]) > sz(ids[u])) {
                swap(v, u);
            }
            p[v] = u;
            for (auto id: ids[v]) {
                upd(id, u);
                ids[u].pb(id);
            }
            return true;
        }
        return false;
    };

    printf("%d\n", dif);
    for (int it = 0; it + 1 < m; ++it) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a;
        --b;

        assert(mergeIds(a, b));
        //dbv(t);
        printf("%d\n", dif);
    }
    return 0;
}