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
#define prev pre
const double eps = 1e-7;
const int N = (int) 1e5 + 5, mod = (int) 0;
double cost[N], d[N];
int q[N], mark[N], cnt, to[N], from[N], cap[N], head[N], prev[N], en, par[N];
void add_edge(int u, int v, int uv, double cs) {
    to[en] = v, from[en] = u, cap[en] = uv, cost[en] = cs, prev[en] = head[u], head[u] = en++;
    to[en] = u, from[en] = v, cap[en] = 0, cost[en] = -cs, prev[en] = head[v], head[v] = en++;
}

double spfa(int src, int snk) {
    for (int i = 0; i < cnt; ++i)
        par[i] = -1, d[i] = N + 1e6, mark[i] = 0;
   d[src] = 0;
   int h = 0, t = 0;
   q[t++] = src;
   mark[src] = 1;
   while (h != t) {
        int v = q[h++];
        mark[v] = 0;
        for (int e = head[v]; e != -1; e = prev[e]) {
            int u = to[e];
            if (cap[e] > 0 && d[v] + cost[e] + eps < d[u]) {
                d[u] = d[v] + cost[e];
                par[u] = e;
                if (!mark[u]++)
                    q[t++] = u;
            }
        }
   }
    int v = snk;
    while (par[v] != -1) {
        int u = to[par[v] ^ 1];
        cap[par[v]]--;
        cap[par[v] ^ 1]++;
        v = u;
    }
   return d[snk];
}

double mcmf(int src, int snk) {
    double res = 0;
    while (true) {
        double x = spfa(src, snk);
        if (x > N) break;
        res += x;
    }
    return res;
}
double ap[N], bp[N];
int32_t main() {
    memset(head, -1, sizeof head);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    int src = cnt++;
    int snk = cnt++;
    int al = cnt++;
    int bl = cnt++;
    add_edge(src, al, a, 0);
    add_edge(src, bl, b, 0);
    for (int i = 0; i < n; ++i) {
        cin >> ap[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> bp[i];
    }
    for (int i = 0; i < n; ++i) {
        int x = cnt++;
        int y = cnt++;
        int am = cnt++;
        int bm = cnt++;
        add_edge(al, am, 1, 0);
        add_edge(bl, bm, 1, 0);
        add_edge(am, x, 1, -(ap[i]));
        add_edge(am, y, 1, -(ap[i] - ap[i] * bp[i]));
        add_edge(bm, x, 1, -(bp[i]));
        add_edge(bm, y, 1, -(bp[i] - ap[i] * bp[i]));
        add_edge(x, snk, 1, 0);
        add_edge(y, snk, 1, 0);
    }
   
    cout << setprecision(8) << fixed << -mcmf(src, snk) << endl;
}