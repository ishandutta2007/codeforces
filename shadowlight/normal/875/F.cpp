#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

vector <int> p, r;

int get(int v) {
    if (p[v] == v || p[v] == -1) return p[v];
    return p[v] = get(p[v]);
}

vector <bool> bad;

void un(int v, int u) {
    v = get(v);
    u = get(u);
    r[v] += r[u];
    p[u] = v;
}

struct Query {
    int a, b, w;
};

bool operator<(Query a, Query b) {
    return a.w < b.w;
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
    int n, m;
    cin >> n >> m;
    int sum = 0;
    vector <Query> data(m);
    p.resize(n, -1);
    r.resize(n, 0);
    for (int i = 0; i < n; i++) {
        p[i] = i;
        r[i] = 1;
    }
    bad.resize(n, false);
    for (int i = 0; i < m; i++) {
        cin >> data[i].a >> data[i].b >> data[i].w;
    }
    sort(data.rbegin(), data.rend());
    for (auto t : data) {
        int a = t.a, b = t.b, w = t.w;
        a--, b--;
        if (get(a) == get(b)) {
            if (r[get(a)] > 0) {
                sum += w;
                r[get(a)]--;
            }
        } else if (r[get(a)] > 0 || r[get(b)] > 0) {
            sum += w;
            un(a, b);
            r[get(a)]--;
        }
    }
    cout << sum;
}