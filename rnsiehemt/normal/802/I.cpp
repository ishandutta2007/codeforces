#include <bits/stdc++.h>

typedef long long ll;
const ll B = 137;
const int N = 100*1000+5;
ll P[N], H[N];
char s[N];
int n;
int lcp[N], sa[N];

void init() {
    P[0] = 1;
    for (int i = 1; i <= n; i++) {
        P[i] = P[i-1]*B;
    }
    for (int i = 0; i <= n; i++) {
        H[i] = s[i] * P[i];
        if (i) H[i] += H[i-1];
    }
}

ll hash(int i, int j) {
    return (H[j] - H[i-1]) * P[n - i - 1];
}

int calc_lcp(int i1, int i2) {
    int lo = 0, hi = n;
    while (hi - lo > 1) {
        int m = (lo+hi)>>1;
        if (hash(i1, i1+m) == hash(i2, i2+m)) {
            lo = m+1;
        } else {
            hi = m;
        }
    }
    return s[i1+lo] == s[i2+lo] ? hi : lo;
}

bool sufcmp(int i1, int i2) {
    int l = calc_lcp(i1, i2);
    return s[i1+l] < s[i2+l];
}

void suffix_sort() {
    for (int i = 0; i < n; i++) {
        sa[i] = i;
    }
    std::stable_sort(sa, sa+n, sufcmp);
    for (int i = 0; i < n; i++) {
        lcp[i] = calc_lcp(sa[i], sa[i-1]);
    }
}

long long sqr(int i) {
    return (long long)i * i;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        scanf(" %s", s);
        n = strlen(s);
        init();
        suffix_sort();
        /*for (int i = 0; i < n; i++) {
            printf("%d %d\n", sa[i], lcp[i]);
        }*/
        int sum = 0;
        long long ans = 0;
        std::vector<std::pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            while (sum && sum - v.back().first > lcp[i]) {
                assert(sum >= 0);
                assert(!v.empty());
                ans += (long long)sqr(i - v.back().second) * (v.back().first);
                sum -= v.back().first;
                v.pop_back();
            }
            if (sum && sum > lcp[i]) {
                auto p = v.back();
                v.pop_back();
                ans += (long long)sqr(i - p.second) * (sum - lcp[i]);
                v.emplace_back(lcp[i] - (sum - p.first), p.second);
                sum = lcp[i];
            }
            //assert(lcp[i] > sum);
            v.emplace_back(n - sa[i] - sum, i);
            sum = n - sa[i];
            //printf("%d:\t", i);
            //for (auto &p : v) {
            //    printf("(%d, %d), ", p.first, p.second);
            //}
            //printf("\n");
        }
        while (sum) {
            assert(sum >= 0);
            assert(!v.empty());
            ans += (long long)sqr(n - v.back().second) * (v.back().first);
            sum -= v.back().first;
            v.pop_back();
        }
        assert(sum == 0);
        printf("%lld\n", ans);
    }
}