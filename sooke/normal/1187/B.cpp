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

int n, m, cnt[100];
std::string s, t;
std::vector<int> f[100];

int main() {
    std::cin >> n >> s >> m;
    for (int i = 0; i < n; i++) {
        f[s[i] - 'a'].push_back(i);
    }
    for (int i = 0; i < m; i++) {
        std::cin >> t; int ans = 0;
        for (int j = 0; j < (int) t.size(); j++) {
            ans = std::max(ans, f[t[j] - 'a'][cnt[t[j] - 'a']++]);
        }
        for (int j = 0; j < (int) t.size(); j++) {
            cnt[t[j] - 'a']--;
        }
        std::cout << ans + 1 << std::endl;
    }
    return 0;
}