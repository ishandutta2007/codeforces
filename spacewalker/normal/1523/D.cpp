#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solveSmallVersion(const vector<int> &likes, int p) {
    int n = likes.size();
    int LIKER_COUNT = n / 2 + n % 2;
    vector<int> friendLiked(1 << p);
    for (int v : likes) ++friendLiked[v];
    vector<int> lfc = friendLiked;
    for (int i = 0; i < p; ++i) {
        for (int msk = (1 << p) - 1; msk >= 0; --msk) 
            if (~msk & (1 << i)) lfc[msk] += lfc[msk ^ (1 << i)];
    }
    int ans = 0;
    for (int i = 0; i < (1 << p); ++i) {
        if (lfc[i] >= LIKER_COUNT && __builtin_popcount(ans) < __builtin_popcount(i)) ans = i;
    }
    return ans;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

pair<int, int> getPair(int a, int b) {
    int i = -1, j = -1;
    while (i == j) {
        i = uniform_int_distribution<int>(a, b)(rng);
        j = uniform_int_distribution<int>(a, b)(rng);
    }
    return {i, j};
}

int main() {
    int n, m, p; scanf("%d %d %d", &n, &m, &p);
    static char likes[100];
    vector<ll> likesbm(n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", likes);
        for (int b = 0; b < m; ++b) if (likes[b] == '1') likesbm[i] |= (1LL << b); 
    }
    if (n == 1) {
        printf("%s\n", likes);
        return 0;
    }
    constexpr int MITER = 200;
    ll ans = 0;
    for (int iterct = 0; iterct < MITER; ++iterct) {
        auto [x, y] = getPair(0, n - 1);
        ll enhance = likesbm[x] & likesbm[y];
        vector<int> bitsSet;
        for (int b = 0; b < m; ++b) if ((1LL << b) & enhance) bitsSet.push_back(b);
        vector<int> smallCase(n);
        for (int i = 0; i < n; ++i) {
            for (int b = 0; b < bitsSet.size(); ++b) {
                if ((1LL << bitsSet[b]) & likesbm[i]) smallCase[i] |= (1 << b);
            }
        }
        int cans = solveSmallVersion(smallCase, p);
        if (__builtin_popcount(cans) > __builtin_popcountll(ans)) {
            ans = 0;
            for (int b = 0; b < bitsSet.size(); ++b) if (cans & (1 << b)) ans |= (1LL << bitsSet[b]);
        }
    }
    for (int i = 0; i < m; ++i) {
        printf("%d", ((ans & (1LL << i)) ? 1 : 0));
    }
    printf("\n");
}