#include <bits/stdc++.h>
using namespace std;

#define N 100010

int n, a[N], p[N], s[N];

vector <int> adj[N];

int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i ++) scanf("%d", &p[i]), adj[p[i]].push_back(i);
    long long sum = 0;
    int i;
    for (i = 1; i <= n; i ++) scanf("%d", &s[i]);
    for (i = 1; i <= n; i ++) {
        if (s[i] < 0) {
            int sz = adj[i].size(), mini = 1e9 + 5;
            for (int j = 0; j < sz; j ++) {
                int u = adj[i][j];
                assert(s[u] >= 0);
                mini = min(mini, s[u]);
            }
            if (mini > 1e9) s[i] = s[p[i]];
            else s[i] = mini;
        }
        a[i] = s[i] - s[p[i]];
        if (a[i] < 0) break;
        sum += a[i];
    }
    printf("%I64d\n", i < n ? -1 : sum);
}