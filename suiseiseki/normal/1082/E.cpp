#include <bits/stdc++.h>
const int maxn = int(5e5) + 7;
std::map<int, std::vector<int>> map;
int n, c, sum[maxn], a[maxn], cnt[maxn];
int main() {
    scanf("%d%d", &n, &c);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        sum[i] = sum[i - 1] + (a[i] == c);
        map[a[i]].push_back(i);
    }
    int ans = sum[n];
    for (auto cur : map) {
        const std::vector<int> &vector = cur.second;
        int num = cur.first, max = 0;
        for (const auto &pos : vector) {
            max = std::max(max, sum[pos - 1] - cnt[num]++);
            ans = std::max(ans, cnt[num] - sum[pos] + max + sum[n]);
        }
    }
    printf("%d\n", ans);
    return 0;
}