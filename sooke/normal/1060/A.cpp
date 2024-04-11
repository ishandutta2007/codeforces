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

int n, cnt[11];
std::string s;

int main() {
    std::cin >> n >> s;
    for (int i = 0; i < n; i++) { cnt[s[i] & 15]++; }
    std::cout << std::min(cnt[8], n / 11) << std::endl;
    return 0;
}