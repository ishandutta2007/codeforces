#include<bits/stdc++.h>
using namespace std;

#define N 2010
int x[N], y[N];
map<pair<int, int>,  int> ve;

int main() {
    int n, i, j;
    long long ans = 0;
    for(scanf("%d", &n), i = 1; i <= n; i ++) scanf("%d%d", x + i, y + i);
    for(i = 1; i <= n; i ++) for(j = 1; j <= n; j ++) {
        if(i == j) continue;
        ans += 1ll * ve[make_pair(x[i] - x[j], y[i] - y[j])] ++;
    }
    printf("%d\n", ans / 4);
}