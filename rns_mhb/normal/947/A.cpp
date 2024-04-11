#include <bits/stdc++.h>
using namespace std;

#define N 1000005

int n;
int cnt;
int p[N];
bool vis[N];
int mx[N];

void init() {
    for (int i = 2; i < N; i ++) {
        if (!vis[i]) p[cnt++] = i;
        for (int j = 2; j * i < N; j ++) vis[i*j] = 1;
    }
    for (int i = 0; i < cnt; i ++) {
        for (int j = 1; p[i] * j < N; j ++) mx[p[i]*j] = p[i];
    }
}

int main() {
//    freopen("sample.in", "r", stdin);
    init();
    scanf("%d", &n);
    int ans = N;
    int m = n - mx[n] + 1;
    for (int i = m; i <= n; i ++) {
        if (i - mx[i] + 1 >= 3) ans = min(ans, i - mx[i] + 1);
    }
    printf("%d\n", ans);
}