#include <bits/stdc++.h>
using namespace std;

#define N 100005
#define M 1000005

int n, a, b;
int c[N];
int cnt[M], now[M];
int acnt, aps[N];
bool vis[M];

int main() {
    scanf("%d %d", &n, &a);
    vis[a] = 1;
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &c[i]);
        cnt[c[i]] ++;
        if (c[i] == a) aps[acnt++] = i;
    }
    for (int i = 1; i <= n; i ++) {
        if (c[i] == a) continue;
        if (now[c[i]] < acnt && aps[now[c[i]]] < i) vis[c[i]] = 1;
        now[c[i]] ++;
    }
    for (int i = 1; i < M; i ++) {
        if (!vis[i] && cnt[i] >= acnt) {
            return printf("%d\n", i), 0;
        }
    }
    printf("-1\n");
    return 0;
}