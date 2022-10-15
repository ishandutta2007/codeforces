#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

#define MOD 998244353
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)

int fpow(int base, int exponent)
{
    int ans = 1;
    int cur = base;
    while (exponent) {
        if (exponent & 1) ans = mul(ans, cur);
        cur = mul(cur, cur);
        exponent >>= 1;
    }
    return ans;
}

vector<int> primes[200005];
int pcnt[200005];
int pmax[200005];
int xval[200005];
vector<pair<int, pair<int, int> > > graph[200005];

int GCD(int x, int y)
{
    if (y == 0) return x;
    return GCD(y, x%y);
}

void dfs(int node, int parent, int x, int y)
{
    xval[node] = mul(xval[parent], mul(x, fpow(y, MOD - 2)));
    for (int i = 0; i < primes[x].size(); i++) {
        pcnt[primes[x][i]]--;
    }
    for (int i = 0; i < primes[y].size(); i++) {
        pcnt[primes[y][i]]++;
        pmax[primes[y][i]] = max(pmax[primes[y][i]], pcnt[primes[y][i]]);
    }
    for (int i = 0; i < graph[node].size(); i++) {
        int nxt = graph[node][i].first;
        if (nxt != parent) dfs(nxt, node,
            graph[node][i].second.first,
            graph[node][i].second.second);
    }
    for (int i = 0; i < primes[x].size(); i++) {
        pcnt[primes[x][i]]++;
    }
    for (int i = 0; i < primes[y].size(); i++) {
        pcnt[primes[y][i]]--;
    }
}

void work()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        pcnt[i] = pmax[i] = 0; graph[i].clear();
    }
    for (int i = 1; i < n; i++) {
        int u, v, x, y; scanf("%d%d%d%d", &u, &v, &x, &y);
        int gval = GCD(x, y);
        x /= gval; y /= gval;
        pair<int, pair<int, int> > edge = make_pair(u, make_pair(x, y));
        graph[v].push_back(edge);
        edge.first = v; swap(edge.second.first, edge.second.second);
        graph[u].push_back(edge);
    }
    xval[0] = 1;
    dfs(1, 0, 1, 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += xval[i];
        //p/rintf("%d ", xval[i]);
        if (ans >= MOD) ans -= MOD;
    }
    int mulval = 1;
    for (int i = 1; i <= n; i++) {
        mulval = mul(mulval, fpow(i, pmax[i]));
    }
    //printf("%d ", mulval);
    printf("%d\n", (int)mul(ans, mulval));
}

int main()
{
    for (int i = 1; i <= 200000; i++) {
        int cur = i;
        for (int j = 2; j <= cur && j * j <= i; j++) {
            while (cur % j == 0) {
                cur /= j; primes[i].push_back(j);
            }
        }
        if (cur > 1) primes[i].push_back(cur);
    }
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}