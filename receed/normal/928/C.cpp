#include <cstdio>
#include <vector>   
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <iomanip>
#include <deque>
#include <queue>
#include <cmath>
#include <cstring>
#include <cassert>
typedef long double ld;
using namespace std;

const int N = 1007;
int used[N], mind[N], maxv[N], d[N];
vector<int> g[N];
vector<string> names;
vector<int> p, v;
map<string, int> num;
map<pair<int, int>, int> pnum;

int scan() {
    string s;
    int k, t;
    cin >> s >> k;
    if (!num.count(s)) {
        num[s] = names.size();
        names.push_back(s);
    }
    t = num[s];
    if (!pnum.count({t, k})) {
        pnum[{t, k}] = p.size();
        p.push_back(t);
        v.push_back(k);
    }
    return pnum[{t, k}];
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, c, t, k, f, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        c = scan();
        if (i == 0)
            f = c;
        cin >> k;
        for (int j = 0; j < k; j++)
            g[c].push_back(scan());
    }
    memset(mind, 1, N * sizeof(int));
    memset(d, 1, N * sizeof(int));
    queue<int> q;
    q.push(p[f]);
    d[f] = 0; mind[p[f]] = 0; maxv[p[f]] = v[f];
    while (!q.empty()) {
        c = q.front();
        q.pop();
        used[c] = 1;
        int cv = pnum[{c, maxv[c]}];
        ans++;
        for (int u : g[cv]) {
            if (d[u] < N)
                continue;
            d[u] = d[cv] + 1;
            if (mind[p[u]] == d[u])
                maxv[p[u]] = max(maxv[p[u]], v[u]);
            else if (mind[p[u]] > N) {
                mind[p[u]] = d[u];
                maxv[p[u]] = v[u];
                q.push(p[u]);
            }
        }
    }
    cout << ans - 1 << '\n';
    for (auto &pp : num) {
        if (used[pp.second] && pp.second != p[f])
            cout << pp.first << ' ' << maxv[pp.second] << '\n';
    }
}