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
const int N = 3e5 + 13;
const int LOGN = 20;
const int K = 22;
const int M = 998244353;//1e9 + 7;
//const int A = 26;
const ld eps = 1e-8;

mt19937 rnd(45768);

/*
*/

struct Edge {
    int to, c, f;

    Edge(int to, int c, int f) : to(to), c(c), f(f) {};
};

int S, T;
int cur[N];
vector<Edge> e;
vector<int> g[N];
int used[N];
int t;

void add_edge(int v, int u, int c) {
    g[v].push_back(e.size());
    e.emplace_back(u, c, 0);

    g[u].push_back(e.size());
    e.emplace_back(v, 0, 0);
}

int rem(int id) {
    return e[id].c - e[id].f;
}

int dfs(int v, int f, int mn) {
    if(v == T)
        return f;

    used[v] = t;

//    for(int ed : g[v])
    for(int i = 0; i < g[v].size(); i++, cur[v] = (cur[v] + 1 < g[v].size() ? cur[v] + 1 : 0)) {

//        int ed = g[v][i];
        int ed = g[v][cur[v]];
        int u = e[ed].to;
        int f1 = min(f, rem(ed));

        if(used[u] == t || f1 < mn)
            continue;

        f1 = dfs(u, f1, mn);

        if(f1 > 0) {
            e[ed].f += f1;
            e[ed ^ 1].f -= f1;

            return f1;
        }
    }

    return 0;
}

vector<int> a[N];
vector<int> ind[N];
int cnt[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> b;
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;

        a[i].resize(k);
        for(int j = 0; j < k; j++) {
            cin >> a[i][j];
            b.push_back(a[i][j]);
        }
    }

    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());



    for(int i = 0; i < n; i++) {
        for(int j = 0; j < a[i].size(); j++) {
            a[i][j] = lower_bound(b.begin(), b.end(), a[i][j]) - b.begin();
            cnt[a[i][j]]++;
        }
    }

    S = n + b.size();
    T = S + 1;

    int sum = 0;
    for(int i = 0; i < n; i++) {
        add_edge(S, i, a[i].size() / 2);
        sum += a[i].size() / 2;
    }

    for(int i = 0; i < b.size(); i++) {
        add_edge(n + i, T, cnt[i] / 2);
    }

    for(int i = 0; i < n; i++) {
        ind[i].resize(a[i].size());
        for(int j = 0; j < a[i].size(); j++) {
            ind[i][j] = e.size();
            add_edge(i, n + a[i][j], 1);
        }
//            mp[a[i][j]]++;
//
//        for(auto p : mp) {
//            add_edge(i, n + p.f, p.s);
//        }
    }

    for(int i = 0; i < sum; i++) {
        t++;
        int f = dfs(S, 1, 1);
        if(f == 0) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < a[i].size(); j++) {
            cout << (e[ind[i][j]].f == 1 ? 'L' : 'R');
        }
        cout << '\n';
    }
}