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

const int INF = 1e9 + 13;
const int N = 1e5 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;
const int K = 400;

mt19937 rnd(0);

vector<int> g[N];
bool used[N];

int dfs(int v) {
    used[v] = true;
    int res = 1;
    for(auto u : g[v])
        if(!used[u])
            res += dfs(u);

    return res;
}

int main() {
    int n, m, k;
    cin >>n >> m >> k;

    vector<int> a(k);
    for(int i = 0; i < k; i++) {
        cin >> a[i];
        a[i]--;
    }

    for(int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        g[v].push_back(u);
        g[u].push_back(v);
    }

    int cnt = 0;
    int mx = 0;
    li ans = 0;

    for(auto root : a) {
        int x = dfs(root);
        mx = max(x, mx);
        cnt += x;
        ans += x * 1ll * (x - 1) / 2;
    }

    int x = n - cnt;
    ans += mx * 1ll * x + x * 1ll * (x - 1) / 2;

    cout << ans - m << endl;

}