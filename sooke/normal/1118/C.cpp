#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

inline int read() {
    char c = getchar(); int x = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c & 15); c = getchar(); }
    return f ? -x : x;
}

const int maxN = 25, maxM = 100005;

int n, m, a[maxM], cnt[maxM], ans[maxN][maxN];
std::vector<int> e, f, g;
bool flag = true;

inline void put(int r, int c, int x) { ans[r][c] = ans[n + 1 - r][c] = ans[r][n + 1 - c] = ans[n + 1 - r][n + 1 - c] = x; }

int main() {
    n = read(); m = n * n;
    for (int i = 1; i <= m; i++) { a[i] = read(); cnt[a[i]]++; }
    if (n & 1) {
        for (int i = 1; i <= 1000; i++) {
            while (cnt[i] >= 4) { cnt[i] -= 4; e.push_back(i); }
            while (cnt[i] >= 2) { cnt[i] -= 2; f.push_back(i); }
            while (cnt[i] >= 1) { cnt[i] -= 1; g.push_back(i); }
        }
        for (int r = 1; r <= n; r++) {
            for (int c = 1; c <= n; c++) {
                if (ans[r][c]) { continue; }
                if (r == n / 2 + 1 && c == n / 2 + 1) {
                    if (g.empty()) { flag = false; break; }
                    put(r, c, g.back()); g.pop_back();
                } else if (r == n / 2 + 1 || c == n / 2 + 1) {
                    if (f.empty()) {
                        if (e.empty()) { flag = false; break; }
                        else { f.push_back(e.back()); f.push_back(e.back()); e.pop_back(); }
                    }
                    if (f.empty()) { flag = false; break; }
                    put(r, c, f.back()); f.pop_back();
                } else {
                    if (e.empty()) { flag = false; break; }
                    put(r, c, e.back()); e.pop_back();
                }
            }
        }
    } else {
        for (int i = 1; i <= 1000; i++) {
            if (cnt[i] % 4 != 0) { flag = false; }
        }
        if (flag) {
            for (int i = 1, r = 1, c = 1; i <= 1000; i++) {
                while (cnt[i]) {
                    while (ans[r][c]) {
                        c++;
                        if (c > n) { r++; c = 1; }
                    }
                    cnt[i] -= 4; put(r, c, i);
                }
            }
        }
    }
    if (flag) {
        printf("YES\n");
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) { printf("%d ", ans[i][j]); } printf("\n");
        }
    } else {
        printf("NO\n");
    }
    return 0;
}