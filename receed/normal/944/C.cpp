#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <cmath>
#include <numeric>
#include <deque>
#include <queue>
typedef long long l;
typedef long double ld;
using namespace std;

const int N = 100007;
int h[N];
vector<int> g[N];

void dfs(int v, int ch) {
    h[ch]++;
    for (int u : g[v])
        dfs(u, ch + 1);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
	int n, t;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &t);
        g[t].push_back(i);
    }
    int ans = 0;
    dfs(1, 0);
    for (int i = 0; i <= n; i++)
        ans += h[i] % 2;
    printf("%d", ans);
}