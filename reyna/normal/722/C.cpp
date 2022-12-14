// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; ++i)
#define int long long
const int N = (int) 1e6 + 6, mod = (int) 0;
int mark[N], par[N], sum[N], p[N], mx = 0;
int find(int x) { return x == par[x]? x: par[x] = find(par[x]); }
void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    sum[v] += sum[u];
    mx = max(mx, sum[v]);
    par[u] = v;
}
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> sum[i], par[i] = i;
    vector<int> res;
    for (int i = 0; i < n; ++i)
        cin >> p[i], --p[i];
    reverse(p, p + n);
    for (int j = 0; j < n; ++j) {
        res.push_back(mx);
        int i = p[j];
        mark[i] = 1;
        mx = max(mx, sum[i]);
        if (i > 0 && mark[i - 1]) unite(i, i - 1);
        if (i < n - 1 && mark[i + 1]) unite(i, i + 1);
    }
    reverse(res.begin(), res.end());
    for (int x : res)
        cout << x << '\n';
}