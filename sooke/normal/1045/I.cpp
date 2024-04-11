#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>

const int maxN = 100005;

int n, val;
std::string s;
std::map<int, int> map;
long long ans;

inline int read() {
    char c = getchar(); int n = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
    return f ? -n : n;
}

int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        std::cin >> s; val = 0;
        for (int j = 0; j < s.size(); j++) { val ^= 1 << (s[j] - 'a'); }
        ans += map[val];
        for (int j = 0; j < 26; j++) { ans += map[val ^ (1 << j)]; }
        map[val]++;
    }
    printf("%I64d\n", ans);
    return 0;
}