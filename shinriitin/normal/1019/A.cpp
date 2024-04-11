#include <bits/stdc++.h>

#define ALL(x) (x).begin(), (x).end()

const int max_N = 3000 + 21;

using ll = long long;

int n, m, p[max_N], c[max_N], cnt[max_N];

std::vector<int> vec[max_N];

bool check() {
    for (int i = 2; i <= m; ++i)
        if (cnt[1] <= cnt[i]) return false;
    return true;
}

ll greed(int x) {
    std::vector<int> remain;
    ll ret = 0;
    int k = x - cnt[1];
    for (int i = 2; i <= m; ++i) {
        if (cnt[i] < x) {
            for (auto a : vec[i]) remain.push_back(a);
            continue;
        }
        int tmp = cnt[i] - x + 1;
        for (int j = 0; j < tmp; ++j) ret += vec[i][j];
        for (int j = tmp; j < cnt[i]; ++j) remain.push_back(vec[i][j]);
        k -= tmp;
    }
    if (k <= 0) return ret;
    std::nth_element(remain.begin(), remain.begin() + k - 1, remain.end());
    for (int i = 0; i < k; ++i) ret += remain[i];
    return ret;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", p + i, c + i);
        ++cnt[p[i]];
        vec[p[i]].push_back(c[i]);
    }
    if (check()) return puts("0"), 0;
    for (int i = 1; i <= m; ++i) std::sort(ALL(vec[i]));
    ll res = LLONG_MAX;
    for (int i = 1; i <= n; ++i) res = std::min(res, greed(i));
    printf("%lld\n", res);
    return 0;
}