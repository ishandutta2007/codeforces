#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e6 + 5;

int n, m, ord[N];
long long sum[N];
std::vector<std::pair<std::pair<int, int>, long long>> ans;

bool compare(int i, int j) {
    return sum[i] < sum[j];
}

int main() {
    n = read(); m = read();
    for (int i = 0; i < m; i++) {
        int u = read(), v = read(), w = read(); u--; v--;
        sum[u] -= w; sum[v] += w;
    }
    for (int i = 0; i < n; i++) { ord[i] = i; }
    std::sort(ord, ord + n, compare);
    for (int i = 0, j = n - 1; i <= j; ) {
        for (; i < n && sum[ord[i]] == 0; i++);
        for (; j >= 0 && sum[ord[j]] == 0; j--);
        if (i >= j) { break; }
        if (-sum[ord[i]] == sum[ord[j]]) {
            ans.push_back({{ord[i], ord[j]}, sum[ord[j]]}); i++; j--;
        } else if (-sum[ord[i]] > sum[ord[j]]) {
            ans.push_back({{ord[i], ord[j]}, sum[ord[j]]}); sum[ord[i]] += sum[ord[j]]; j--;
        } else {
            ans.push_back({{ord[i], ord[j]}, -sum[ord[i]]}); sum[ord[j]] += sum[ord[i]]; i++;
        }
    }
    printf("%d\n", ans.size());
    for (auto i : ans) {
        printf("%d %d %I64d\n", i.first.first + 1, i.first.second + 1, i.second);
    }
    return 0;
}