#include <bits/stdc++.h>

using namespace std;

int main(){
#ifdef FLOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k, m, t;
    scanf("%d%d%d", &n, &k, &m);
    deque<pair<int, long long>> a, la, ra, ca;
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        if (!a.empty() && t == a.back().first)
            a[a.size() - 1].second++;
        else
            a.push_back({t, 1});
        if (a.back().second == k)
            a.pop_back();
    }
    long long ans = 0;
    if (m == 1) {
        for (auto p : a)
            ans += p.second;
        printf("%lld\n", ans);
        return 0;
    }
    la = a;
    ra = a;
    while (a.size() > 1 && a.back().first == a[0].first && a.back().second + a[0].second >= k) {
        a[0].second -= k - a.back().second;
        ra[0].second -= k - a.back().second;
        a.pop_back();
        la.pop_back();
        if (a[0].second == 0) {
            a.pop_front();
            ra.pop_front();
        }
    }
    if (a.size() > 1) {
        for (auto p : a)
            ans += p.second;
        ans *= m - 2;
        for (auto p : la)
            ans += p.second;
        for (auto p : ra)
            ans += p.second;
        printf("%lld\n", ans);
        return 0;
    }
    if (!a.empty()) {
        long long d = (long long) (m - 2) * a[0].second % k;
        la.push_back({a[0].first, d});
    }
    for (auto p : ra)
        la.push_back(p);
    for (auto p : la) {
        if (!ca.empty() && ca.back().first == p.first) {
            ca[ca.size() - 1].second += p.second;
            if (ca.back().second > k)
                ca[ca.size() - 1].second -= k;
            else if (ca.back().second == k)
                ca.pop_back();
        }
        else
            ca.push_back(p);
    }
    for (auto p : ca)
        ans += p.second;
    printf("%lld", ans);
}