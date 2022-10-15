#include <bits/stdc++.h>

int query() {
    int x;
    scanf("%d", &x);
    return x;
}
int chess(int x, int i, int j) {
    std::cout << x << " " << i << " " << j << std::endl;
}

int n;
std::vector<std::pair<int, int>> a, b;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if ((i + j) % 2 == 0) {
                a.push_back({i, j});
            } else {
                b.push_back({i, j});
            }
        }
    }
    for (; !a.empty() && !b.empty(); ) {
        int x = query();
        if (x == 1) {
            chess(2, a.back().first, a.back().second);
            a.pop_back();
        } else {
            chess(1, b.back().first, b.back().second);
            b.pop_back();
        }
    }
    if (b.empty()) {
        for (auto i : a) {
            int x = query();
            if (x == 2) {
                chess(3, i.first, i.second);
            } else {
                chess(2, i.first, i.second);
            }
        }
    } else {
        for (auto i : b) {
            int x = query();
            if (x == 1) {
                chess(3, i.first, i.second);
            } else {
                chess(1, i.first, i.second);
            }
        }
    }
    return 0;
}