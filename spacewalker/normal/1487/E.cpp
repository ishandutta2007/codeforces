#include <bits/stdc++.h>

using namespace std;
constexpr int INF = 1000000000;

vector<int> getCheapest(vector<int> &costs, vector<int> &backCosts, const vector<vector<int>> &bawalBack) {
    int n = costs.size(), m = backCosts.size();
    multiset<int> bc(begin(backCosts), end(backCosts));
    bc.insert(INF);
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        for (int j : bawalBack[i]) {
//            printf("removing %d from %d\n", j, i);
            bc.erase(bc.find(backCosts[j]));
        }
        ans[i] = costs[i] + *bc.begin();
        for (int j : bawalBack[i]) bc.insert(backCosts[j]);
    }
//    printf("GC CALL %d %d\n", n, m);
//    for (int i = 0; i < n; ++i) printf("%d %d\n", i, ans[i]);
    return ans;
}

int main() {
    constexpr int TYPES = 4;
    vector<int> dishlen(TYPES);
    for (int i = 0; i < TYPES; ++i) scanf("%d", &dishlen[i]);
    vector<vector<int>> costs(TYPES);
    for (int i = 0; i < TYPES; ++i) {
        costs[i].assign(dishlen[i], 0);
        for (int j = 0; j < dishlen[i]; ++j) scanf("%d", &costs[i][j]);
    }
    static vector<vector<int>> bawal[TYPES];
    for (int i = 0; i < TYPES; ++i) bawal[i].resize(dishlen[i]);
    for (int i = 1; i < TYPES; ++i) {
        int m; scanf("%d", &m);
        for (int j = 0; j < m; ++j) {
            int x, y; scanf("%d %d", &x, &y); --x; --y;
            bawal[i][y].push_back(x);
        }
    }
    vector<int> ans{0};
    for (int i = 0; i < TYPES; ++i) {
        ans = getCheapest(costs[i], ans, bawal[i]);
    }
    int minCost = *min_element(begin(ans), end(ans));
    printf("%d\n", minCost >= INF ? -1 : minCost);
}