#include <bits/stdc++.h>

struct Edge {
    int u, v, w;
};

int L, R, o;
std::vector<Edge> e;

int main() {
    scanf("%d%d", &L, &R);
    if (L == 1) { L = 2; o = 1; }
    for (int i = 31; i >= 11; i--) {
        for (int j = i + 1; j <= 32; j++) {
            e.push_back((Edge) {i, j, j == 32 ? 1 : 1 << (31 - j)});
        }
    }
    for (int i = 11; i <= 31; i++) {
        if ((R - L + 1) & (1 << (31 - i))) {
            e.push_back((Edge) {1, i, R - (1 << (31 - i))});
            R -= 1 << (31 - i);
        }
    }
    if (o) { e.push_back((Edge) {1, 32, 1}); }
    printf("YES\n32 %d\n", e.size());
    for (auto i : e) { printf("%d %d %d\n", i.u, i.v, i.w); }
    return 0;
}