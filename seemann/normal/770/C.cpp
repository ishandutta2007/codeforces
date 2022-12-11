#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <bitset>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb push_back
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)
#ifdef LOCAL
#define debug(a) cerr << #a << ": " << a << '\n';
#else
#define debug(a)
#endif

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ld EPS = 1e-8;
const ld PI = acos(-1.0L);
const int MAXN = 1e5 + 100;

vector<int> e[MAXN];
int used[MAXN];
vector<int> order;
void dfs(int v) {
    used[v] = 1;
    for (auto u : e[v]) {
        if (used[u] == 1) {
            cout << -1 << '\n';
            exit(0);
        }
        if (!used[u]) {
            dfs(u);
        }
    }
    order.pb(v);
    used[v] = 2;
}

int main() {
#ifdef LOCAL
    freopen("c.in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    cin.sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> st;
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        st.pb(x - 1);
    }
    for (int v = 0; v < n; ++v) {
        int k;
        cin >> k;
        e[v].resize(k);
        for (int i = 0; i < k; ++i) {
            int u;
            cin >> u;
            u--;
            e[v][i] = u;
        }
    }
    for (auto v : st) {
        if (!used[v])
            dfs(v);
    }
    cout << order.size() << '\n';
    for (auto v : order) {
        cout << v + 1 << ' ';
    }
    cout << '\n';
    return 0;
}