#include <bits/stdc++.h>

const int N = 1e6 + 5;

int T, n;
char s[N], t[N];

std::vector<int> solve(char str[]) {
    std::vector<int> res;
    int x = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (str[i] == x + '0') {
            res.push_back(i + 1);
            x ^= 1;
        }
    }
    return res;
}

int main() {
    for (scanf("%d", &T); T; T--) {
        scanf("%d%s%s", &n, s, t);
        std::vector<int> a = solve(s);
        std::vector<int> b = solve(t);
        printf("%d", a.size() + b.size());
        std::reverse(a.begin(), a.end());
        for (auto i : a) { printf(" %d", i); }
        for (auto i : b) { printf(" %d", i); }
        printf("\n");
    }
    return 0;
}