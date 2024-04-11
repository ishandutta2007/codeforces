#include <bits/stdc++.h>

int a[5], b[5];
std::vector<int> ans;

void check(int u) {
    b[0] = a[0]; b[1] = a[1]; b[2] = a[2]; b[3] = a[3]; ans.clear();
    for (int i = 0; i < a[0] + a[1] + a[2] + a[3]; i++) {
        if (b[u] == 0) { return; }
        b[u]--; ans.push_back(u);
        if (u == 0) {
            u = 1;
        } else if (u == 1) {
            if (b[0] == 0) {
                u = 2;
            } else {
                u = 0;
            }
        } else if (u == 2) {
            if (b[3] == 0) {
                u = 1;
            } else {
                u = 3;
            }
        } else {
            u = 2;
        }
    }
    std::cout << "YES\n";
    for (auto x : ans) { std::cout << x << " "; }
    exit(0);
}

int main() {
    std::cin >> a[0] >> a[1] >> a[2] >> a[3];
    check(0); check(1); check(2); check(3);
    std::cout << "NO\n";
    return 0;
}