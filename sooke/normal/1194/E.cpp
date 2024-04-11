#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

int n, res;
long long ans;

struct Line { int sx, sy, tx, ty; }; std::vector<Line> ho, ve, used;

bool compare1(Line u, Line v) { return u.sy < v.sy; }
bool compare2(Line u, Line v) { return u.ty < v.ty; }

struct FenwickTree {
    int f[10005];

    inline void modify(int u, int x) {
        for (u += 5002; u <= 10004; u += u & -u) { f[u] += x; }
    }
    inline int query(int u) {
        int res = 0;
        for (u += 5002; u; u ^= u & -u) { res += f[u]; }
        return res;
    }
    inline int query(int l, int r) { return query(r) - query(l - 1); }
} bit;

int main() {
    n = read();
    for (int i = 0; i < n; i++) {
        Line u; u.sx = read(); u.sy = read(); u.tx = read(); u.ty = read();
        if (u.sx > u.tx) { std::swap(u.sx, u.tx); }
        if (u.sy > u.ty) { std::swap(u.sy, u.ty); }
        if (u.sy == u.ty) { ho.push_back(u); } else { ve.push_back(u); }
    }
    std::sort(ho.begin(), ho.end(), compare1);
    for (int i = 0, p; i < (int) ho.size(); i++) {
        Line u = ho[i]; used.clear();
        for (auto v : ve) {
            if (v.sx >= u.sx && v.sx <= u.tx && v.sy <= u.sy && v.ty >= u.sy) {
                used.push_back(v); bit.modify(v.sx, 1);
            }
        }
        std::sort(used.begin(), used.end(), compare2); p = 0;
        for (int j = i + 1; j < (int) ho.size(); j++) {
            Line v = ho[j];
            for (; p < (int) used.size() && used[p].ty < v.sy; p++) { bit.modify(used[p].sx, -1); }
            res = bit.query(v.sx, v.tx); ans += 1ll * res * (res - 1) / 2;
            if (p == (int) used.size()) { break; }
        }
        for (; p < (int) used.size(); p++) { bit.modify(used[p].sx, -1); }
    }
    printf("%I64d\n", ans);
    return 0;
}