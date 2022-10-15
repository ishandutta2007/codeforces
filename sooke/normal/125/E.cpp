#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e5 + 5, E = N << 1, M = 1e6 + 5;

int n, m, _m, m0, m1, k, s, q, cc, cnt, anc[N];
long long ans;
bool used[M];

struct Edge { int u, v, c, i; long long w; } edg[M], _edg[M], edg0[M], edg1[M];

bool operator <(const Edge &i, const Edge &j) {
    return i.w == j.w ? i.c < j.c : i.w < j.w;
}

int find(int u) {
    return anc[u] == u ? u : anc[u] = find(anc[u]);
}

bool check(long long mid, bool flag) {
    ans = cnt = cc = _m = 0;
    for (int i = 0; i < n; i++) { anc[i] = i; }
    for (int i = 0; i < m0; i++) { edg0[i].w += mid; }
    for (int i = 0, j = 0; i < m0 || j < m1; ) {
        used[_m] = false;
        if (i == m0) {
            edg[_m++] = edg1[j++];
        } else if (j == m1) {
            edg[_m++] = edg0[i++];
        } else if (edg0[i] < edg1[j]) {
            edg[_m++] = edg0[i++];
        } else {
            edg[_m++] = edg1[j++];
        }
    }
    for (int i = 0; i < m; i++) {
        int u = edg[i].u, v = edg[i].v, c = edg[i].c;
        long long w = edg[i].w;
        if (find(u) != find(v)) {
            if (c == 0 && cnt >= k && flag) { continue; }
            anc[find(u)] = find(v); used[edg[i].i] = true; ans += w;
            if (c == 0) { cnt++; } cc++;
        }
    }
    for (int i = 0; i < m0; i++) { edg0[i].w -= mid; }
    ans -= mid * k;
    return cnt >= k;
}

int main() {
    n = read(); m = read(); k = read(); s = 0;
    if (n > 1 && k == 0) { printf("-1\n"); return 0; }
    for (int i = 0; i < m; i++) {
        int u = read(), v = read(), w = read(); u--; v--;
        if (u == s || v == s) {
            edg0[m0++] = (Edge) {u, v, 0, i, w};
        } else {
            edg1[m1++] = (Edge) {u, v, 1, i, w};
        }
    }
    std::sort(edg0, edg0 + m0);
    std::sort(edg1, edg1 + m1);
    long long res = -1e10;
    for (long long l = -3e9, r = 3e9, mid; l <= r; ) {
        mid = l + r >> 1;
        if (check(mid, false)) {
            l = mid + 1; res = mid;
        } else {
            r = mid - 1;
        }
    }
    if (res == -1e10) { printf("-1\n"); return 0; }
    check(res, true);
    if (cc != n - 1) { printf("-1\n"); return 0; }
    printf("%d\n", n - 1);
    for (int i = 0; i < m; i++) {
        if (used[i]) { printf("%d ", i + 1); }
    }
    return 0;
} //