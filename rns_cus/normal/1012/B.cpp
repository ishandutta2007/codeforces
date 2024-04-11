#include <bits/stdc++.h>
using namespace std;

#define N 400400

int n, m, q, cnt, rt[N];

int find_rt(int u) {
    return rt[u] == u ? u : rt[u] = find_rt(rt[u]);
}

void add_edge(int u, int v) {
    u = find_rt(u), v = find_rt(v);
    if (u == v) return;
    rt[u] = v, cnt --;
}

int main() {
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n + m; i ++) rt[i] = i, cnt = n + m - 1;
    while (q --) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v + n);
    }
    printf("%d\n", cnt);
}