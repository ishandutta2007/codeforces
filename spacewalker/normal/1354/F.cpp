#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, k; scanf("%d %d", &n, &k);
    vector<pair<ll, ll>> minions(n); // {b, a};
    for (int i = 0; i < n; ++i) scanf("%lld %lld", &minions[i].second, &minions[i].first);
    vector<int> placeInOrig(n);
    iota(begin(placeInOrig), end(placeInOrig), 0);
    sort(begin(placeInOrig), end(placeInOrig), [&minions] (int i, int j) {
            return minions[i] < minions[j];
    });
//    for (int i = 0; i < n; ++i) printf("%d PIO %d\n", i, placeInOrig[i]);
    sort(begin(minions), end(minions));
    // NON-FINALS: contribute (k-1) * b
    // FINALS: contribute a + b * (number summoned so far - 1)
    // we summon in order of increasing b for finals
    // bestWay[i][k]: among minions[0:i], what is the best way to summon k final minions?
    vector<vector<ll>> bestWay(n + 1, vector<ll>(k + 1, -1000000000000000000));
    bestWay[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        auto [curB, curA] = minions[i-1];
//        printf("CHECK MINION {%d %d}\n", curB, curA);
        for (int j = 0; j <= k; ++j) {
            bestWay[i][j] = max((j == 0 ? 0 : bestWay[i-1][j-1] + curA + curB * (j - 1)), bestWay[i-1][j] + curB * (k - 1));
//            printf("BW %d %d = %lld\n", i, j, bestWay[i][j]);
//            printf("choices: %lld %lld\n", (j == 0 ? 0 : bestWay[i-1][j-1] + curA + curB * (j - 1)), bestWay[i-1][j] + curB * (k - 1));
        }
    }
    int curK = k;
    vector<int> nonFinal, finalm;
    for (int i = n; i > 0; --i) {
        auto [curB, curA] = minions[i-1];
//        printf("%d k %d\n", i, curK);
//        printf("f %lld nf %lld\n", (curK == 0 ? 0 : bestWay[i-1][curK-1] + curA + curB * (curK - 1)), bestWay[i-1][curK] + curB * (k - 1));
        if (curK == 0 || bestWay[i][curK] == bestWay[i-1][curK] + curB * (k-1)) { // this can do a nf transition
//            printf("%d in sort NF\n", i);
            nonFinal.push_back(placeInOrig[i-1]);
        } else {
            --curK;
//            printf("%d in sort F\n", i);
            finalm.push_back(placeInOrig[i-1]);
        }
    }
    vector<int> ans;
//    for (int v : finalm) printf("FM %d\n", v);
//    for (int v : nonFinal) printf("NFM %d\n", v);
    reverse(begin(finalm), end(finalm));
    for (int i = 0; i + 1 < finalm.size(); ++i) ans.push_back(finalm[i] + 1);
    for (int v : nonFinal) {
        ans.push_back(v + 1);
        ans.push_back(- v - 1);
    }
    ans.push_back(finalm.back() + 1);
    printf("%lu\n", ans.size());
    for (int v : ans) printf("%d ", v);
    printf("\n");
}

int main() {
    int t; scanf("%d", &t);
    while (t--) solve();
}