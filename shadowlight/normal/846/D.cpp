#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;
const int SQ = 507;

struct Query {
    int x, y, t;
};

bool operator<(Query a, Query b) {
    return a.t < b.t;
}

struct Dsu {
    vector <int> p, r;
    vector <int> rt;
    int n;
    Dsu() {}
    Dsu(int n) : n(n), p(n, -1), r(n, 0), rt(n, 0) {}
    int get(int v) {
        return (p[v] == v ? v : get(p[v]));
    }
    void un(int v, int u) {
        if (p[v] == -1 || p[u] == -1) return;
        v = get(v);
        u = get(u);
        if (v == u) return;
        if (r[v] == r[u]) r[u]++;
        if (r[v] > r[u]) swap(v, u);
        p[v] = u;
        rt[u] = max(rt[v], rt[u]);
    }
    void create(int v) {
        if (p[v] == -1) {
            p[v] = v;
            rt[v] = v;
            if (v) {
                un(v, v - 1);
            }
            if (v < n - 1) {
                un(v, v + 1);
            }
        }
    }
};

int n, m, k, q;

bool check(vector <vector <int> > &d) {
    vector <vector <int> > pref(n + 1, vector <int> (m + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pref[i][j + 1] = pref[i][j] + d[i][j];
        }
    }
    for (int j = 0; j <= m - k; j++) {
        int st = 0;
        for (int i = 0; i < n; i++) {
            int val = pref[i][j + k] - pref[i][j];
            if (val == k) {
                st++;
            } else {
                st = 0;
            }
            if (st == k) {
                return true;
            }
        }
    }
    return false;
}

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
    cin >> n >> m >> k >> q;
    vector <Query> a(q);
    for (int i = 0; i < q; i++) {
        cin >> a[i].x >> a[i].y >> a[i].t;
        a[i].x--, a[i].y--;
    }
    sort(a.begin(), a.end());
    vector <vector <int> > pred(n, vector <int> (m, 0));
    auto now = pred;
    int st = 0;
    int cnt = 0;
    for (int i = 0; i < q; i++) {
        cnt++;
        int x = a[i].x, y = a[i].y, t = a[i].t;
        now[x][y] = 1;
        if (cnt == SQ) {
            cnt = 0;
            if (!check(now)) {
                pred = now;
                st = i + 1;
                continue;
            }
            now = pred;
            for (int j = st; j < st + SQ; j++) {
                int x = a[j].x, y = a[j].y, t = a[j].t;
                now[x][y] = 1;
                if (check(now)) {
                    cout << t;
                    return 0;
                }
            }
            assert(false);
        }
    }
    if (check(now)) {
        now = pred;
        for (int i = st; i < st + SQ; i++) {
            int x = a[i].x, y = a[i].y, t = a[i].t;
            now[x][y] = 1;
            //cout << x << " " << y << "\n";
            if (check(now)) {
                cout << t;
                return 0;
            }
        }
        assert(false);
    } else {
        cout << -1;
    }
}