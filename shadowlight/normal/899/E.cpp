#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

struct Seg {
    int l, r, sz, x;
};

bool operator<(Seg a, Seg b) {
    if (a.sz == b.sz) {
        return a.l < b.l;
    }
    return a.sz > b.sz;
}
struct DSU {
    vector <int> p, r;
    vector <int> left, right;
    void create(int v) {
        p[v] = v;
        r[v] = 1;
        left[v] = v;
        right[v] = v;
    }

    DSU(int n) {
        p.resize(n);
        r.resize(n);
        left.resize(n);
        right.resize(n);
        for (int i = 0; i < n; i++) {
            create(i);
        }
    }

    int get_root(int v) {
        if (p[v] == v) return v;
        return p[v] = get_root(p[v]);
    }

    void unite(int v, int u) {
        v = get_root(v);
        u = get_root(u);
        if (v == u) {
            return;
        }
        if (r[v] > r[u]) {
            swap(v, u);
        }
        p[v] = u;
        r[u] += r[v];
        left[u] = min(left[v], left[u]);
        right[u] = max(right[v], right[u]);
    }
};

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
    int n;
    cin >> n;
    DSU del(n);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    set <Seg> q;
    int pred = -1;
    int l = -1, r = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == pred) {
            del.unite(i, i - 1);
            r++;
        } else {
            if (pred != -1) {
                q.insert({l, r, r - l + 1, pred});
            }
            l = i, r = i;
            pred = a[i];
        }
    }
    q.insert({l, r, r - l + 1, pred});
    set <int> exist;
    for (int i = 0; i < n; i++) {
        exist.insert(i);
    }
    int cnt = 0;
    while (!q.empty()) {
        cnt++;
        auto p = *q.begin();
        q.erase(q.begin());
        auto it = exist.lower_bound(p.l);
        vector <int> erased;
        while (it != exist.end() && *it <= p.r) {
            erased.push_back(*it);
            it++;
        }
        //cout << p.l << " " << p.r << "\n";
        for (int x : erased) {
            exist.erase(x);
        }
//        for (int x : exist) {
//            cout << x << " ";
//        }
//        cout << "\n";
        auto it1 = exist.upper_bound(p.r), it2 = exist.lower_bound(p.l);
        if (it1 == exist.end() || it2 == exist.begin()) continue;
        it2--;
        int v = *it2, u = *it1;
        if (a[v] != a[u]) {
            continue;
        }
        v = del.get_root(v), u = del.get_root(u);
        q.erase({del.left[v], del.right[v], del.r[v], a[v]});
        q.erase({del.left[u], del.right[u], del.r[u], a[u]});
        del.unite(v, u);
        v = del.get_root(v);
        q.insert({del.left[v], del.right[v], del.r[v], a[v]});
    }
    cout << cnt;
}