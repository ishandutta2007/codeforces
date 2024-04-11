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

const int INF = 1e6;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k, s, t, u, v;
    scanf("%d%d%d%d", &n, &m, &k, &s);
    vector<vector<int>> a(k), g(n + 1), d(n + 1, vector<int>(k, INF));
    vector<int> ans(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t);
        d[i][t - 1] = 0;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < k; i++) {
        queue<int> q;
        for (int j = 1; j <= n; j++)
            if (d[j][i] == 0)
                q.push(j);
        while (!q.empty()) {
            v = q.front();
            q.pop();
            for (int j : g[v]) {
                if (d[j][i] == INF) {
                    d[j][i] = d[v][i] + 1;
                    q.push(j);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        sort(d[i].begin(), d[i].end());
        int cs = 0;
        for (int j = 0; j < s; j++)
            cs += d[i][j];
        printf("%d ", cs);
    }
}