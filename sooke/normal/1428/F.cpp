#include <bits/stdc++.h>

const int inf = 1e8;
const int N = 1e6 + 5;

int n, m, a[N], bl[N], br[N], sl[N], sr[N];
long long ans;
std::string s;
std::set<int> set;
std::vector<std::pair<int, int>> vec;
std::vector<int> vl[N], vr[N];

int main() {
    std::cin >> n >> s; s = "0" + s + "0";
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '0' && s[i] == '1') {
            int j = i;
            for (; j <= n && s[j] == '1'; j++); j--;
            bl[++m] = i; br[m] = j; a[m] = j - i + 1;
            vec.push_back({a[m], m});
        }
    }
    if (m == 0) { std::cout << 0; return 0; }
    std::sort(vec.begin(), vec.end());
    bl[0] = -inf; br[0] = 0; a[0] = inf;
    bl[m + 1] = n + 1; br[m + 1] = inf; a[m + 1] = inf;
    set.insert(0); set.insert(m + 1);
    for (int i = m - 1; i >= 0; i--) {
        sr[vec[i].second] = *set.upper_bound(vec[i].second);
        sl[vec[i].second] = *--set.lower_bound(vec[i].second);
        set.insert(vec[i].second);
    }
    vec.clear();
    for (int i = 1; i <= m; i++) {
        int l = std::max(1, br[sl[i]] - a[i] + 1);
        int r = std::min(n, bl[sr[i]] + a[i] - 2);
        ans += 1ll * a[i] * (bl[i] - l + 1) * (r - br[i] + 1);
        for (int x = 1; x < a[i] - 1; x++) {
            ans += 1ll * x * (a[i] - x - 1);
        }
        vl[i].resize(a[i] + 1); vr[i].resize(a[i] + 1);
        for (int x = 1; x <= a[i]; x++) {
            vec.push_back({x, i});
        }
    }
    std::sort(vec.begin(), vec.end());
    set.clear();
    set.insert(0); set.insert(m + 1);
    for (int i = vec.size() - 1; i >= 0; i--) {
        vr[vec[i].second][vec[i].first] = *set.upper_bound(vec[i].second);
        vl[vec[i].second][vec[i].first] = *--set.lower_bound(vec[i].second);
        set.insert(vec[i].second);
    }
    for (int i = 1; i <= m; i++) {
        for (int x = 1; x < a[i]; x++) {
            int l = std::max(1, br[vl[i][x]] - x + 1);
            ans += 1ll * x * (bl[i] - l + 1);
            int r = std::min(n, bl[vr[i][x]] + x - 2);
            ans += 1ll * x * (r - br[i] + 1);
        }
    }
    std::cout << ans << std::endl;
    return 0;
}