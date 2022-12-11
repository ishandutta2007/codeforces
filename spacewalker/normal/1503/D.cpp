#include <bits/stdc++.h>

using namespace std;
constexpr int INF = 1000000000;

int main() {
    int n; scanf("%d", &n);
    vector<pair<int, int>> cards;
    for (int i = 0; i < n; ++i) {
        int a, b; scanf("%d %d", &a, &b); --a; --b;
        cards.emplace_back(a, b);
    }
    vector<int> partner2(n, -1);
    vector<bool> origLeft(n); // is this picked?
    for (int i = 0; i < n; ++i) {
//        printf("ANDITO\n");
        auto [a, b] = cards[i];
        if ((a < n) == (b < n)) {
            partner2[0] = -1;
            break;
        }
        if (a > b) swap(a, b);
        partner2[a] = b - n;
//        printf("assigning %d to %d\n", partner2[a], a);
        if (a == cards[i].first) origLeft[a] = true;
    }
    if (*min_element(begin(partner2), end(partner2)) == -1) {
        printf("-1\n");
        return 0;
    }
    vector<vector<int>> cComps; vector<int> curBack;
    int amin = n;
    for (int i = 0; i < n; ++i) {
        curBack.push_back(i);
        amin = min(partner2[i], amin);
        if (n-1-i == amin) { // break this off
            cComps.push_back(curBack);
            curBack.clear();
        }
    }
    vector<bool> inLower(n), inUpper(n);
    int sweepMin = n, sweepMax = -1;
    for (int i = 0; i < n; ++i) {
        if (sweepMin > partner2[i]) inLower[i] = true;
        sweepMin = min(sweepMin, partner2[i]);
    }
    for (int i = n - 1; i >= 0; --i) {
        if (sweepMax < partner2[i]) inUpper[i] = true;
        sweepMax = max(sweepMax, partner2[i]);
    }
    for (int i = 0; i < n; ++i) if (!inLower[i] && !inUpper[i]) {
        printf("-1\n");
        return 0;
    }
    int ans = 0;
    for (auto &cc : cComps) {
        if (cc.size() == 1) continue;
        int asIs = 0, change = 0;
        for (int v : cc) (inLower[v] == origLeft[v] ? change : asIs)++;
        ans += min(asIs, change);
    }
    printf("%d\n", ans);
}