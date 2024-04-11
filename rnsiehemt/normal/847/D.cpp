#include <bits/stdc++.h>

const int maxn = 200*1000+5;

int n;
long long T, t[maxn];
std::vector<std::pair<long long, int>> v;
std::priority_queue<int> q;

int main() {
    scanf("%d%lld", &n, &T);
    for (int i = 0; i < n; i++) {
        scanf("%lld", t+i);
        long long wait = std::max(0ll, t[i] - (i+1));
        v.emplace_back(wait, i+1);
    }
    std::sort(v.begin(), v.end());
    std::reverse(v.begin(), v.end());
    int ans = (int)q.size();
    while (!v.empty()) {
        long long wait = v.back().first;
        long long maxdist = T - 1 - wait;
        q.push(v.back().second);
        while (!q.empty() && q.top() > maxdist) q.pop();
        ans = std::max(ans, (int)q.size());
        v.pop_back();
    }
    printf("%d\n", ans);
}