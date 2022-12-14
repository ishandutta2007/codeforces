#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
const int MD = 1000000007;

#define ll long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(x) (int)((x).size())
#define FOR(i, a, b) for (int _tmp = (b), i = (a); i <= _tmp; ++i)

typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector < vi > vvi;
typedef pair < long double, long double > pdd;

int n, m, k, s, t;
int w[N], is[N];
int dep[N], z[N];
vi g[N];

bool chk(int q) {
    queue < int > Q;
    Q.push(s);
    memset(z, 0, sizeof z);
    z[s] = 1;
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (auto to : g[v]) {
            if (!z[to] && dep[to] != -1 && dep[v] != -1 && dep[v] + dep[to] + 1 <= q) {
                Q.push(to);
                z[to] = 1;
            }
        }
    }
    FOR(i, 1, n) {
        if (z[i] && is[i]) {
            Q.push(i);
            z[i] = 0;
        } else {
            z[i] = MD;
        }
    }
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (auto to : g[v]) {
            if (z[to] > z[v] + 1) {
                z[to] = z[v] + 1;
                Q.push(to);
            }
        }
    }
    return z[t] <= q;
}

int main()
{
//    freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    FOR(i, 1, k) {
        cin >> w[i];
        is[w[i]] = 1;
    }
    FOR(i, 1, m) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    cin >> s >> t;
    queue < int > q;
    memset(dep, -1, sizeof dep);
    FOR(i, 1, k) {
        q.push(w[i]);
        dep[w[i]] = 0;
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto to : g[v]) {
            if (dep[to] == -1) {
                dep[to] = dep[v] + 1;
                q.push(to);
            }
        }
    }
    int l = 1, r = n, res = -1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (chk(m)) {
            r = m - 1;
            res = m;
        } else {
            l = m + 1;
        }
    }
    cout << res << endl;
    return 0;
}