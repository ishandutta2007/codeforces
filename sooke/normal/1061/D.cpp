#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <set>

typedef long long lol;

const int maxN = 100005, p = 1e9 + 7;

int n;
lol ans, x, y, len[maxN];
std::pair<lol, lol> t[maxN];
std::set<std::pair<lol, int> > s;

bool cmp(std::pair<lol, lol> a, std::pair<lol, lol> b) { return a.second == b.second ? a.first > b.first : a.second > b.second; }

int main() {
    std::cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) { std::cin >> t[i].first >> t[i].second; s.insert(std::make_pair(t[i].first, i)); len[i] = 5e18; ans = (ans + (t[i].second - t[i].first) * y + x) % p; }
    std::sort(t + 1, t + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        std::set<std::pair<lol, int> > ::iterator it = s.lower_bound(std::make_pair(t[i].second + 1, 0));
        if (it != s.end()) { len[it->second] = (it->first - t[i].second) * y; s.erase(it); }
    }
    std::sort(len + 1, len + n + 1);
    for (int i = 1; i <= n; i++) {
        if (len[i] < x) { ans = (ans + p - x + len[i]) % p; } else { break; }
    }
    std::cout << ans << std::endl;
    return 0;
} //