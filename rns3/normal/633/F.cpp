#include <bits/stdc++.h>

using namespace std;

#define N 100005

typedef __int64 LL;

int a[N];
int head[N], to[N << 1], nxt[N << 1];

void AddEdge(int a, int b, int i) {
    to[i] = b;
    nxt[i] = head[a];
    head[a] = i;
}

LL one[N], two[N];

void DFS(int u, int pr = 0) {
    LL mx = 0, mx2 = 0;
    for (int i = head[u]; i; i = nxt[i]) {
        int v = to[i];
        if (v == pr) continue;
        DFS(v, u);
        if (two[u] < two[v]) two[u] = two[v];
        if (mx < one[v]) mx2 = mx, mx = one[v];
        else if (mx2 < one[v]) mx2 = one[v];
    }
    one[u] = mx + a[u];
    if (two[u] < mx + mx2 + a[u]) two[u] = mx + mx2 + a[u];
}

LL three[N];

void DFS3(int u, int pr = 0) {
    LL m11 = 0, p11 = 0;
    LL m12 = 0, p12 = 0;
    LL m21 = 0, p21 = 0;
    LL m22 = 0, p22 = 0;
    for (int i = head[u]; i; i = nxt[i]) {
        int v = to[i];
        if (v == pr) continue;
        DFS3(v, u);
        if (three[u] < three[v] + a[u]) three[u] = three[v] + a[u];
        if (m11 < one[v]) m12 = m11, p12 = p11, m11 = one[v], p11 = v;
        else if (m12 < one[v]) m12 = one[v], p12 = v;

        if (m21 < two[v]) m22 = m21, p22 = p21, m21 = two[v], p21 = v;
        else if (m22 < two[v]) m22 = two[v], p22 = v;
    }
    if (p11 != p21) three[u] = max(three[u], m11 + m21 + a[u]);
    else three[u] = max(three[u], max(m11 + m22, m12 + m21) + a[u]);
}

LL four[N];

void DFS4(int u, int pr = 0) {
    LL m11 = 0, p11 = 0, m12 = 0, p12 = 0, m13 = 0, p13 = 0;
    LL m21 = 0, p21 = 0, m22 = 0, p22 = 0, m23 = 0, p23 = 0;
    LL m31 = 0, p31 = 0, m32 = 0, p32 = 0;
    for (int i = head[u]; i; i = nxt[i]) {
        int v = to[i];
        if (v == pr) continue;
        DFS4(v, u);
        if (four[u] < four[v]) four[u] = four[v];

        if (m31 < three[v]) m32 = m31, p32 = p31, m31 = three[v], p31 = v;
        else if (m32 < three[v]) m32 = three[v], p32 = v;

        if (m21 < two[v]) m23 = m22, p23 = p22, m22 = m21, p22 = p21, m21 = two[v], p21 = v;
        else if (m22 < two[v]) m23 = m22, p23 = p22, m22 = two[v], p22 = v;
        else if (m23 < two[v]) m23 = two[v], p23 = v;

        if (m11 < one[v]) m13 = m12, p13 = p12, m12 = m11, p12 = p11, m11 = one[v], p11 = v;
        else if (m12 < one[v]) m13 = m12, p13 = p12, m12 = one[v], p12 = v;
        else if (m13 < one[v]) m13 = one[v], p13 = v;
    }

    if (four[u] < m21 + m22) four[u] = m21 + m22;

    LL tmp;
    if (p11 != p31) tmp = m11 + m31;
    else tmp = max(m11 + m32, m12 + m31);
    if (four[u] < tmp + a[u]) four[u] = tmp + a[u];

    tmp = 0;
    if (p21 != p11 && p21 != p12) tmp = max(tmp, m11 + m12 + m21);
    if (p22 != p11 && p22 != p12) tmp = max(tmp, m11 + m12 + m22);
    if (p23 != p11 && p23 != p12) tmp = max(tmp, m11 + m12 + m23);

    if (p21 != p11 && p21 != p13) tmp = max(tmp, m11 + m13 + m21);
    if (p22 != p11 && p22 != p13) tmp = max(tmp, m11 + m13 + m22);
    if (p23 != p11 && p23 != p13) tmp = max(tmp, m11 + m13 + m23);

    if (p21 != p12 && p21 != p13) tmp = max(tmp, m12 + m13 + m21);
    if (p22 != p12 && p22 != p13) tmp = max(tmp, m12 + m13 + m22);
    if (p23 != p12 && p23 != p13) tmp = max(tmp, m12 + m13 + m23);

    if (four[u] < tmp + a[u]) four[u] = tmp + a[u];
}

main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", a + i);
    for (int i = 1; i < n; i ++) {
        int a, b;
        scanf("%d %d", &a, &b);
        AddEdge(a, b, i);
        AddEdge(b, a, i + n - 1);
    }
    DFS(1);
    DFS3(1);
    DFS4(1);
    printf("%I64d\n", four[1]);
}