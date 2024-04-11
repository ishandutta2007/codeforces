#include <bits/stdc++.h>

using namespace std;
constexpr int KMAX = 10;
constexpr int KFACMAX = 100;
constexpr int NMAX = 200010;


bool cannotCoexist[KFACMAX][KFACMAX];

int flatten(int k, int v) {
    return k * (k - 1) / 2 + v;
};

int ans = 0, k;
int currentAns[KMAX];
bool cannotSet[KMAX][KMAX];

void computeAnswer(int i) {
    if (i > k) {
        bool valid = true;
        for (int x = 1; x <= k; ++x) {
            for (int y = 1; y < x; ++y) {
                if (cannotCoexist[flatten(x, currentAns[x])][flatten(y, currentAns[y])]) valid = false;
            }
        }
        if (!valid) return;
        if (valid) ++ans;
//        if (valid) printf("CAND\n");
//        for (int x = 1; x <= k; ++x) printf("%d ", currentAns[x]);
//        printf("\n");
    } else {
        for (int cv = 0; cv < i; ++cv) {
            if (cannotSet[i][cv]) continue;
            currentAns[i] = cv;
            computeAnswer(i + 1);
        }
    }
}

int main() {
    int n, m; scanf("%d %d %d", &n, &m, &k);
    vector<vector<pair<int, int>>> graph(n); // {w, v}
    vector<set<pair<int, int>>> satisfiers(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        --u; --v;
        graph[u].emplace_back(w, v);
    }
    for (int i = 0; i < n; ++i) {
        sort(begin(graph[i]), end(graph[i]));
    }
    for (int i = 0; i < n; ++i) {
        int od = graph[i].size();
        for (int idx = 0; idx < od; ++idx) {
            int nxt = graph[i][idx].second;
            if (satisfiers[nxt].count(make_pair(od, idx)) > 0) cannotSet[od][idx] = true;
            satisfiers[nxt].emplace(od, idx);
//            printf("if c_%d = %d, %d goes to %d\n", od, idx, i, nxt);
        }
    }
    // c_k = v compresses to k(k-1)/2; 
    for (int i = 0; i < n; ++i) {
        for (auto [pk, pv] : satisfiers[i]) {
            for (auto [qk, qv] : satisfiers[i]) {
//                printf("%d %d %d %d cannot exist together\n", pk, pv, qk,qv);
                cannotCoexist[flatten(pk, pv)][flatten(qk, qv)] = true;
            }
        }
    }
    computeAnswer(1);
    printf("%d\n", ans);
    return 0;
}