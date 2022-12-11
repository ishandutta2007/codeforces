#include <bits/stdc++.h>

using namespace std;

int cdiv(int n, int d) {
    return n/d + (n%d ? 1 : 0);
}

int main() {
    int n; scanf("%d", &n);
    if (n == 1) {
        printf("1\n1 1\n");
        return 0;
    }
    int minQ = cdiv(2 * n - 1, 3);
    int rem = n - minQ;
    set<pair<int, int>> ans;
    for (int i = 0; i < rem; ++i) ans.emplace(i, rem-1-i);
    for (int j = 0; j < rem-1; ++j) ans.emplace(rem + j, rem + (rem-2-j));
    for (int k = 2 * rem - 1; k < minQ; ++k) ans.emplace(k, k);
    printf("%d\n", minQ);
    for (auto [a, b] : ans) printf("%d %d\n", a + 1, b + 1);
}