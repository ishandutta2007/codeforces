#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

const int maxN = 1005;

int n, cnt[28][maxN];
std::string s;

int main() {
    std::cin >> n >> s; s = " " + s;
    for (int i = 2; i <= n; i++) {
        if (s[i - 1] != s[i]) { printf("YES\n%c%c\n", s[i - 1], s[i]); return 0; }
    }
    printf("NO\n");
    return 0;
} //