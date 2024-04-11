#include <bits/stdc++.h>

inline long long read() {
    char c; long long x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

int T, n;
long long k, sum;
std::vector<std::pair<int, int>> e;
std::vector<int> ans;

bool check() {
    for (int i = 0; i < e.size(); i++) {
        if ((k + 1) / 2 <= sum && sum <= k) {
            printf("%d\n", (int) e.size() - i);
            ans.clear();
            for (int j = i; j < e.size(); j++) {
                ans.push_back(e[j].second);
            }
            std::sort(ans.begin(), ans.end());
            for (auto x : ans) { printf("%d ", x); }
            printf("\n");
            return false;
        }
        sum -= e[i].first;
    }
    return true;
}

int main() {
    for (int T = read(); T; T--) {
        n = read(); k = read();
        e.clear();
        int res = -1; sum = 0;
        for (int i = 0; i < n; i++) {
            int x = read();
            if (x > k) { continue; }
            e.push_back({x, i + 1});
            if ((k + 1) / 2 <= x && x <= k) {
                res = i + 1;
            }
            sum += x;
        }
        if (res != -1) {
            printf("1\n%d\n", res); continue;
        }
        std::sort(e.begin(), e.end());
        if (check()) { printf("-1\n"); }
    }
    return 0;
}