#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e6 + 5;

int n;
long long ans;
std::set<int> set, tmp;
std::pair<int, int> a[N];

bool compare(std::pair<int, int> u, std::pair<int, int> v) {
    return u.second > v.second;
}

int main() {
    n = read();
    for (int i = 0; i < n; i++) {
        a[i].first = read();
    }
    for (int i = 0; i < n; i++) {
        a[i].second = read();
    }
    std::sort(a, a + n, compare);
    for (int i = 0, x; i < n; i++) {
        if (set.count(a[i].first) == 0) {
            x = a[i].first;
        } else {
            x = *tmp.lower_bound(a[i].first);
        }
        set.insert(x);
        tmp.erase(x);
        if (set.count(x + 1) == 0) {
            tmp.insert(x + 1);
        }
        ans += 1ll * (x - a[i].first) * a[i].second;
    }
    printf("%lld\n", ans);
    return 0;
}