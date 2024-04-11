#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
//const int M = 1e9 + 7;
const int M = 998244353;
const int N = 3e6 + 13;
const int LOGN = 30;
const int A = 26;

/*

*/

int a[N], p[N];
int l[N], r[N];
vector<int> g[N];

int dfs(int v) {
    int res = 0;
    li sum = 0;

    for(int u : g[v]) {
        res += dfs(u);
        sum += a[u];
    }

    if(sum > r[v])
        sum = r[v];

    if(sum < l[v]) {
        sum = r[v];
        res++;
    }

    a[v] = sum;
    return res;
}

void solve() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        a[i] = p[i] = l[i] = r[i] = 0;
        g[i].erase(g[i].begin(), g[i].end());
    }

    for(int i = 1; i < n; i++) {
        cin >> p[i];
        p[i]--;

        g[p[i]].push_back(i);
    }

    for(int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }

    cout << dfs(0) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}