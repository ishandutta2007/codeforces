#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int L = 63;

int n;
long long a[L];
std::map<long long, int> f[L];
std::vector<std::pair<std::pair<long long, long long>, char>> ans;

void insert(long long x) {
    long long _x = x;
    for (int i = L - 1; i >= 0; i--) {
        if (_x >> i & 1) {
            if (a[i] == 0) {
                break;
            } else {
                _x ^= a[i];
            }
        }
    }
    if (_x == 0) { return; }
    std::map<long long, int> now;
    now[x] = 1;
    for (int i = L - 1; i >= 0; i--) {
        if (x >> i & 1) {
            if (a[i] == 0) {
                a[i] = x; f[i] = now;
                break;
            } else {
                x ^= a[i];
                for (auto t : f[i]) {
                    now[t.first] ^= t.second;
                }
            }
        }
    }
}

int main() {
    n = read();
    insert(n);
    for (int i = 2; i <= 50000; i++) {
        ans.push_back({{(i - 1ll) * n, 1ll * n}, '+'});
        insert(1ll * i * n);
    }
    long long lim = 49999ll * n;
    for (int i = 2; i <= 40000; i++) {
        ans.push_back({{(i - 1ll) * lim, 1ll * lim}, '+'});
        insert(1ll * i * lim);
    }
    long long lst = -1;
    for (auto i : f[0]) {
        if (i.second == 0) { continue; }
        if (lst == -1) { lst = i.first; continue; }
        ans.push_back({{lst, i.first}, '^'});
        lst ^= i.first;
    }
    printf("%d\n", ans.size());
    for (auto i : ans) {
        printf("%lld %c %lld\n", i.first.first, i.second, i.first.second);
    }
    return 0;
}