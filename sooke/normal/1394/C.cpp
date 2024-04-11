#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, lx, rx, ly, ry, lz, rz, z, xx[N], yy[N];
char str[N];

int print(int x, int y) {
    for (int i = 0; i < x; i++) { putchar('B'); }
    for (int i = 0; i < y; i++) { putchar('N'); }
    exit(0);
}

bool ok(int x, int y) {
    return lz <= x - y && x - y <= rz && x >= lx && x <= rx && y >= ly && y <= ry;
}

bool check(int mid, int typ) {
    if (typ == 0) {
        lx = 1; ly = 0; rx = 1e6; ry = 1e6; lz = -1e6; rz = 1e6;
    } else {
        lx = 0; ly = 1; rx = 1e6; ry = 1e6; lz = -1e6; rz = 1e6;
    }
    for (int i = 0; i < n; i++) {
        lx = std::max(lx, xx[i] - mid);
        rx = std::min(rx, xx[i] + mid);
        ly = std::max(ly, yy[i] - mid);
        ry = std::min(ry, yy[i] + mid);
        lz = std::max(lz, xx[i] - yy[i] - mid);
        rz = std::min(rz, xx[i] - yy[i] + mid);
    }
    z = (lz + rz) / 2;
    if (ok(lx, ly)) { return true; }
    if (ok(lx, ry)) { return true; }
    if (ok(rx, ly)) { return true; }
    if (ok(rx, ry)) { return true; }
    if (ok(lx, lx - z)) { return true; }
    if (ok(lx, lx + z)) { return true; }
    if (ok(rx, rx - z)) { return true; }
    if (ok(rx, rx + z)) { return true; }
    if (ok(ly - z, ly)) { return true; }
    if (ok(ly + z, ly)) { return true; }
    if (ok(ry - z, ry)) { return true; }
    if (ok(ry + z, ry)) { return true; }
    return false;
}

void solve(int mid, int typ) {
    if (typ == 0) {
        lx = 1; ly = 0; rx = 1e6; ry = 1e6; lz = -1e6; rz = 1e6;
    } else {
        lx = 0; ly = 1; rx = 1e6; ry = 1e6; lz = -1e6; rz = 1e6;
    }
    for (int i = 0; i < n; i++) {
        lx = std::max(lx, xx[i] - mid);
        rx = std::min(rx, xx[i] + mid);
        ly = std::max(ly, yy[i] - mid);
        ry = std::min(ry, yy[i] + mid);
        lz = std::max(lz, xx[i] - yy[i] - mid);
        rz = std::min(rz, xx[i] - yy[i] + mid);
    }
    z = (lz + rz) / 2;
    if (ok(lx, ly)) { print(lx, ly); }
    if (ok(lx, ry)) { print(lx, ry); }
    if (ok(rx, ly)) { print(rx, ly); }
    if (ok(rx, ry)) { print(rx, ry); }
    if (ok(lx, lx - z)) { print(lx, lx - z); }
    if (ok(lx, lx + z)) { print(lx, lx + z); }
    if (ok(rx, rx - z)) { print(rx, rx - z); }
    if (ok(rx, rx + z)) { print(rx, rx + z); }
    if (ok(ly - z, ly)) { print(ly - z, ly); }
    if (ok(ly + z, ly)) { print(ly + z, ly); }
    if (ok(ry - z, ry)) { print(ry - z, ry); }
    if (ok(ry + z, ry)) { print(ry + z, ry); }
}

int main() {
    n = read();
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        int len = strlen(str);
        for (int j = 0; j < len; j++) {
            if (str[j] == 'B') {
                xx[i]++;
            } else {
                yy[i]++;
            }
        }
    }
    int ans1 = 1e6;
    for (int l = 0, r = 1e6, mid; l <= r; ) {
        mid = (l + r) / 2;
        if (check(mid, 0)) {
            r = mid - 1;
            ans1 = mid;
        } else {
            l = mid + 1;
        }
    }
    int ans2 = 1e6;
    for (int l = 0, r = 1e6, mid; l <= r; ) {
        mid = (l + r) / 2;
        if (check(mid, 1)) {
            r = mid - 1;
            ans2 = mid;
        } else {
            l = mid + 1;
        }
    }
    if (ans1 < ans2) {
        printf("%d\n", ans1);
        solve(ans1, 0);
    } else {
        printf("%d\n", ans2);
        solve(ans1, 1);
    }
    return 0;
}