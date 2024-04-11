#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e5 + 5;

int n, a[N];
std::vector<std::pair<int, int>> ans;
std::stack<int> s[5];

bool check() {
    for (int i = n, j; i >= 1; i--) {
        if (a[i] == 1) {
            ans.push_back({i, i});
        } else if (a[i] == 2) {
            if (s[1].empty()) { return false; }
            j = s[1].top(); s[1].pop();
            ans.push_back({j, i});
        } else if (a[i] == 3) {
            bool flag = false;
            for (int _ = 0; _ < 3; _++) {
                if (flag) { break; }
                int k;
                if (_ == 0) { k = 2; }
                if (_ == 1) { k = 3; }
                if (_ == 2) { k = 1; }
                if (s[k].empty()) { continue; }
                j = s[k].top(); s[k].pop();
                ans.push_back({i, i});
                ans.push_back({i, j});
                flag = true;
            }
            if (!flag) { return false; }
        }
        s[a[i]].push(i);
    }
    return true;
}

int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read();
    }
    if (!check()) { printf("-1\n"); return 0; }
    std::sort(ans.begin(), ans.end());
    ans.resize(std::unique(ans.begin(), ans.end()) - ans.begin());
    printf("%d\n", ans.size());
    for (auto i : ans) {
        printf("%d %d\n", i.first, i.second);
    }
    return 0;
}