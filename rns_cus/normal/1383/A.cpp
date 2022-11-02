#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n;
char a[N], b[N];
int rt[30];
bool vis[30];

int find_rt(int u) {
    return rt[u] == u ? u : rt[u] = find_rt(rt[u]);
}

int solve() {
    for (int i = 1; i <= n; i ++) if (a[i] > b[i]) return -1;
    for (int i = 0; i < 30; i ++) rt[i] = i, vis[i] = 0;
    for (int i = 1; i <= n; i ++) {
        int u = a[i] - 'a', v = b[i] - 'a';
        u = find_rt(u), v = find_rt(v);
        rt[u] = v;
    }
    for (int i = 0; i < 30; i ++) vis[find_rt(i)] = 1;
    int rlt = 30;
    for (int i = 0; i < 30; i ++) if (vis[i]) rlt --;
    return rlt;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d %s %s", &n, a + 1, b + 1);
        printf("%d\n", solve());
    }

    return 0;
}