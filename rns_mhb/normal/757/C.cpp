#include <bits/stdc++.h>
using namespace std;

#define N 100005
#define M 1000005
#define MOD 1000000007

typedef unsigned long long ui;
int n, m, ans;
vector<int> v[M];
ui h1[M], h2[M];
ui e1[N], e2[N];
typedef pair<ui, ui> puu;
map<puu, int> vis;
map<puu, int> :: iterator it;
int fc[M];
int s1 = 1313131, s2 = 131313;

void init() {
    e1[0] = 1;
    for (int i = 1; i < N - 2; i ++) e1[i] = e1[i-1] * s1, e2[i] = e2[i-1] * s2;
    fc[0] = 1;
    for (int i = 1; i < M - 2; i ++) fc[i] = 1ll * fc[i-1] * i % MOD;
}

int main() {
    init();
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i ++) {
        int sz;
        scanf("%d", &sz);
        while (sz --) {
            int x;
            scanf("%d", &x);
            h1[x] += e1[i];
            h2[x] += e2[i];
        }
    }
    for (int i = 1; i <= m; i ++) vis[puu(h1[i], h2[i])] ++;
    ans = 1;
    for (it = vis.begin(); it != vis.end(); it ++) {
        ans = 1ll * ans * fc[it->second] % MOD;
    }
    printf("%d\n", ans);
}