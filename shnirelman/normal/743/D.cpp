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
const int N = 2e5 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;
const int K = 16 * 16;

mt19937 rnd(0);

vector<int> g[N];
int a[N];
li s[N];
li ans = -INF;

li dfs(int v, int par) {
    s[v] = a[v];

    li mx1 = -INF, mx2 = -INF;

    for(auto u : g[v]) if(u != par) {
        li res = dfs(u, v);
        s[v] += s[u];

        if(res > mx1) {
            mx2 = mx1;
            mx1 = res;
        } else if(res > mx2)
            mx2 = res;
    }

    if(mx2 > -INF)
        ans = max(ans, mx1 + mx2);

    return max(mx1, s[v]);
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        g[v].push_back(u);
        g[u].push_back(v);
    }

    dfs(0, -1);

    if(ans == -INF)
        cout << "Impossible" << endl;
    else
        cout << ans << endl;
}