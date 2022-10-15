#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e6 + 5;

int n, ans, a[N];
std::set<std::pair<int, int>> set;

int main() {
    for (int T = read(); T; T--) {
        n = read();
        for (int i = 0; i < n; i++) {
            a[i] = read();
        }
        if (n == 1) { printf("0\n"); continue; }
        set.clear();
        for (int i = 0; i < n - 1; i++) {
            set.insert({i, i + 1});
        }
        auto it = set.begin();
        while (true) {
            if (it == set.end()) { break; }
            auto jt = it; jt++;
            bool ok = false;
            if (jt != set.end()) {
                int mx = std::max(std::max(a[it->first], a[it->second]), std::max(a[jt->first], a[jt->second]));
                int mn = std::min(std::min(a[it->first], a[it->second]), std::min(a[jt->first], a[jt->second]));
                int l = it->first, r = jt->second; 
                if (mx == std::max(a[l], a[r]) && mn == std::min(a[l], a[r])) {
                    set.erase(it); set.erase(jt);
                    it = set.insert({l, r}).first; ok = true;
                    if (it != set.begin()) { it--; }
                    if (it != set.begin()) { it--; }
                } else { 
                    auto kt = jt; kt++;
                    if (kt != set.end()) {
                        mx = std::max(std::max(std::max(a[it->first], a[it->second]), std::max(a[jt->first], a[jt->second])), std::max(a[kt->first], a[kt->second]));
                        mn = std::min(std::min(std::min(a[it->first], a[it->second]), std::min(a[jt->first], a[jt->second])), std::min(a[kt->first], a[kt->second]));
                        l = it->first, r = kt->second;
                        if (mx == std::max(a[l], a[r]) && mn == std::min(a[l], a[r])) {
                            set.erase(it); set.erase(jt); set.erase(kt);
                            it = set.insert({l, r}).first; ok = true;
                            if (it != set.begin()) { it--; }
                            if (it != set.begin()) { it--; }
                        }
                    }
                }
            }
            if (!ok) { it++; }
        }
        printf("%d\n", set.size());
    }
    return 0;
}