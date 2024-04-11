#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;
const int INF = 1e9;

bool u[N];
vector <int> es[N];
int n, m, k;
int c[N], v1, v2;

int dfs(int v) {
    if (u[v]) return 0;
    u[v] = true;
    int res = 1;
    for (int w: es[v])
        res += dfs(w);
    return res;
}

int main() {
    init();

    int sz, tot = 0;
    vector <int> v;

    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
        cin >> c[i];
    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2;
        v1--;
        v2--;
        es[v1].push_back(v2);
        es[v2].push_back(v1);
    }

    for (int i = 0; i < k; i++) {
        sz = dfs(c[i] - 1);
        v.push_back(sz);
        tot += sz;
    }

    sort(v.begin(), v.end());
    v.back() += n - tot;
    int ans = 0;
    for (int w: v) ans += (w * (w - 1)) / 2;

    cout << ans - m;

    return 0;
}