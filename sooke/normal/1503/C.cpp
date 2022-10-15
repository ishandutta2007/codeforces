#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, a[N], b[N];
long long ans, f[N];
std::pair<int, int> ab[N];
std::vector<long long> toset[N], byset[N], adset[N];
std::multiset<long long> setf, setg;

int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        int x = read(), y = read();
        ab[i] = {x, y};
    }
    std::sort(ab + 1, ab + n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = ab[i].first; b[i] = ab[i].second; ans += b[i];
    }
    int far = 0;
    for (int i = 1, j = 1; i <= n; i++) {
        far = std::max(far, a[i] + b[i]);
        for (; j <= n && a[j] <= far; j++);
        for (auto x : toset[i]) { setf.insert(x); }
        for (auto x : byset[i]) { setf.erase(setf.find(x)); }
        for (auto x : adset[i]) { setg.insert(x); }
        if (i == 1) {
            f[i] = 0;
        } else {
            f[i] = 4e18;
            if (!setf.empty()) { f[i] = std::min(f[i], *setf.begin()); }
            if (!setg.empty()) { f[i] = std::min(f[i], *setg.begin() + a[i]); }
        }
        // printf("%d: %lld\n", i, f[i]);
        toset[i + 1].push_back(f[i]);
        byset[j].push_back(f[i]);
        adset[j].push_back(f[i] - far);
    }
    ans += f[n];
    printf("%lld\n", ans);
    return 0;
}