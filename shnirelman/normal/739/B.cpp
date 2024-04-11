//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vint = vector<int>;
using matr = vector<vint>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 2e5 + 13;
const int M = 1e9 + 9;
const ld eps = 1e-6;
const int K = 103;
const int LOGN = 20;

/*
3 1
1 0 0
*/



int p[N][LOGN], w[N];
vector<pii> g[N];
int a[N];
li d[N];
int add[N];

//int tin[N], tout[N];
//int T = 1;

int ans[N];

int dfs(int v, li depth) {
//    tin[v] = T++;

    d[v] = depth;
//    a[v] += depth;

    for(int i = 1; i < LOGN; i++)
        p[v][i] = p[p[v][i - 1]][i - 1];


    int anc = v;
    for(int i = LOGN - 1; i >= 0; i--) {
        if(d[v] - d[p[anc][i]] <= a[v])
            anc = p[anc][i];
    }
    add[anc]--;

//    cout << v << ' ' << anc << endl;

    int res = 0;

    for(pii pr : g[v]) {
        int u = pr.f;

        res += dfs(u, depth + pr.s);
    }

    ans[v] = res;
    res += add[v];

//    tout[v] = T++;
    return res + 1;
}

signed main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i < n; i++) {
        cin >> p[i][0] >> w[i];

        p[i][0]--;

        g[p[i][0]].emplace_back(i, w[i]);
    }

    dfs(0, 0);

    for(int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    cout << endl;
}