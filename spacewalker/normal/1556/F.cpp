#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;

ll modexp(ll b, ll e = MOD - 2) {
    if (e == 0) return 1;
    else return (e & 1 ? b : 1) * modexp(b * b % MOD, e / 2) % MOD;
}

int LSB(int x) {
    return (x & (-x));
}


// consider cuts of the graph!
int main() {
    int n; scanf("%d", &n);
    int ALL = (1 << n) - 1;
    vector<int> strength(n);
    for (int i = 0; i < n; ++i) scanf("%d", &strength[i]);
    vector<vector<ll>> beatProb(n, vector<ll>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) beatProb[i][j] = -1;
            else {
                beatProb[i][j] = strength[i] * modexp(strength[i] + strength[j]) % MOD;
//                printf("bp %d %d %lld\n", i, j, beatProb[i][j]);
            }
        }
    }
    ll ans = 0;
    vector<ll> cutFollowProb(1 << n);
    for (int wsidem = 1; wsidem < (1 << n); ++wsidem) {
        cutFollowProb[wsidem] = 1;
        for (int b1 = 0; b1 < n; ++b1) {
            for (int b2 = 0; b2 < n; ++b2) {
                // w -- b2 | b1
                if ((wsidem & (1 << b1)) == 0 && (wsidem & (1 << b2)) > 0) {
                    cutFollowProb[wsidem] = (cutFollowProb[wsidem] * beatProb[b1][b2]) % MOD;
                }
            }
        }
    }
    vector<vector<ll>> probBeatBy(n, vector<ll>(1 << n));
    for (int w = 0; w < n; ++w) {
        probBeatBy[w][0] = 1;
        for (int bm = 1; bm < (1 << n); ++bm) {
            if ((bm & (1 << w)) > 0) continue;
            probBeatBy[w][bm] = 1;
            for (int i = 0; i < n; ++i) {
                if (bm & (1 << i)) probBeatBy[w][bm] = (probBeatBy[w][bm] * beatProb[i][w]) % MOD;
            }
//            printf("pbb %d %d %lld\n", w, bm, probBeatBy[w][bm]);
        }
    }
    for (int w = 0; w < n; ++w) {
        // find probability w is winner
        vector<int> graphCutOn(1 << n);
        for (int wsidem = 1; wsidem < (1 << n); ++wsidem) {
            if ((wsidem & (1 << w)) == 0) continue;
            graphCutOn[wsidem] = cutFollowProb[wsidem];
        }
        vector<ll> followBothProb(1 << n);
        followBothProb[0] = 1;
        for (int wsidem = 0; wsidem < (1 << n); ++wsidem) {
            if ((wsidem & (1 << w)) == 0) continue;
            for (int s = wsidem; s; s = (s - 1) & wsidem) {
                if (s == wsidem) continue;
                int vToAddm = wsidem ^ s;
                int outside = ALL ^ wsidem;
                // ll probBothFollow = bothFollowProb[encode(wsidem, vToAddm)];
//                printf("build %d %d %lld %lld\n", __builtin_ctz(vToAddm), outside, probBeatBy[__builtin_ctz(vToAddm)][outside], followBothProb[vToAddm ^ LSB(vToAddm)]);
                followBothProb[vToAddm] = (probBeatBy[__builtin_ctz(vToAddm)][outside] * followBothProb[vToAddm ^ LSB(vToAddm)]) % MOD;
//                printf("wsm %d %d %lld\n", wsidem, vToAddm, followBothProb[vToAddm]);
//                ll probBothFollow = 23;
                graphCutOn[wsidem] = (graphCutOn[wsidem] - followBothProb[vToAddm] * graphCutOn[s] % MOD + MOD) % MOD;
            }
            for (int s = wsidem; s; s = (s - 1) & wsidem) {
                if (s == wsidem) continue;
                int vToAddm = wsidem ^ s;
                followBothProb[vToAddm] = 0;
            }
        }
        ans += graphCutOn[(1 << n) - 1];
    }
    printf("%lld\n", ans % MOD);
}