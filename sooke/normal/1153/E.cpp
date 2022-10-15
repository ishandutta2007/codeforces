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

const int N = 1005;

int n, ans;
bool f[N], g[N];
std::vector<int> a, b;

inline bool query(int x, int y, int u, int v) {
    std::cout << "? " << x << " " << y << " " << u << " " << v << std::endl;
    int res; std::cin >> res; return res & 1;
}
inline void answer(int x, int y, int u, int v) {
    std::cout << "! " << x << " " << y << " " << u << " " << v << std::endl;
}

int main() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        f[i] = query(1, i, n, i);
        if (f[i]) {
            b.push_back(i);
            if ((int) b.size() >= 2) { break; }
        }
    }
    for (int i = 1; i <= n; i++) {
        g[i] = query(i, 1, i, n);
        if (g[i]) {
            a.push_back(i);
            if ((int) a.size() >= 2) { break; }
        }
    }
    if ((int) a.size() == 2 && (int) b.size() == 2) {
        if (query(a[0], b[0], a[0], b[0])) {
            answer(a[0], b[0], a[1], b[1]);
        } else {
            answer(a[0], b[1], a[1], b[0]);
        }
    }
    if (b.empty()) {
        for (int l = 1, r = n, mid; l <= r; ) {
            mid = l + r >> 1;
            if (query(a[0], 1, a[0], mid)) {
                ans = mid; r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        answer(a[0], ans, a[1], ans);
    } else {
        for (int l = 1, r = n, mid; l <= r; ) {
            mid = l + r >> 1;
            if (query(1, b[0], mid, b[0])) {
                ans = mid; r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        answer(ans, b[0], ans, b[1]);
    }
    return 0;
}