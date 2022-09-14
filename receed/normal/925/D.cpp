#include <cstdio>
#include <vector>   
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <random>
#include <ctime>
#include <iomanip>
#include <deque>
#include <queue> 
#include <cmath>
#include <cstring>
#include <cassert>
#include <bitset>
#include <unordered_set>
typedef long long ll;
typedef long double ld;

using namespace std;

const int N = 300001, INF = 1e9;
vector<int> g[N];
vector<int> d(N, INF), ls;
int p[N], dd[N];

void dfs(int v) {
    ls.push_back(v);
    dd[v] = 1;
    for (int u : g[v])
        if (!dd[u])
            dfs(u);
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, a, b, v;
    scanf("%d%d", &n, &m);
    set<pair<int, int>> ee;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
        ee.insert({a, b});
        ee.insert({b, a});

    }
    queue<int> q;
    q.push(1);
    d[1] = 0;
    while (!q.empty()) {
        v = q.front();
        q.pop();
        for (int u : g[v])
            if (d[u] == INF) {
                d[u] = d[v] + 1;
                p[u] = v;
                q.push(u);
            }
    }
    if (d[n] <= 3) {
        printf("%d\n", d[n]);
        vector<int> ans;
        for (int i = n; i; i = p[i])
            ans.push_back(i);
        for (int i = ans.size() - 1; i >= 0; i--)
            printf("%d ", ans[i]);
        return 0;
    }
    for (int i = 2; i < n; i++) {
        if (d[i] == 2) {
            printf("4\n%d %d %d %d %d\n", 1, p[i], i, 1, n);
            return 0;
        }
    }
    for (int i = 1; i <= n; i++)
        dd[i] = 1;
    for (int u : g[1])
        dd[u]--;
    for (int u : g[n])
        dd[u] += 2;
    for (int i = 2; i < n; i++)
        if (!dd[i]) {
            ls.clear();
            dfs(i);
            int mv = ls[0];
            for (int x : ls)
                if (g[x].size() > g[mv].size())
                    mv = x;
            for (int u : g[mv])
                for (int j : g[mv])
                    if (u != n && j != n && u != j && !ee.count({u, j})) {
                        printf("5\n1 %d %d %d %d %d", u, mv, j, u, n);
                        return 0;
                    }
        }
    printf("-1");
}