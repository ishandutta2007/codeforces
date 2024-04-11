#include <bits/stdc++.h>

using namespace std;

vector<int> par;
void bryceorz(int v, int p, const vector<vector<int>> &graph) {
    par[v] = p;
    for (int nxt : graph[v]) {
        if (nxt == p) continue;
        bryceorz(nxt, v, graph);
    }
}

int main() {
    int n; scanf("%d", &n);
    vector<double> fail(n);
    for (int i = 0; i < n; ++i) scanf("%lf", &fail[i]);
    vector<vector<int>> tree(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    par.assign(n, -1);
    bryceorz(0, -1, tree);
    par.push_back(-1);
    fail.push_back(1.0);
    par[0] = n; 
    // answer is sum (1 - fail[i]) fail[par[i]] for all i 0 <= i < n
    // = sum fail[par[i]] - sum fail[i] fail[par[i]]
    // = sum fail[i] * childCount[i] - sum fail[i]*fail[par[i]] for all i 0 <= i < n
    // by changing a node by D, you change answer by D * cc - (sum of neighbors) * D
    vector<double> childrenSums(n + 1);
    vector<int> childCount(n + 1);
    for (int i = 0; i < n; ++i) childrenSums[par[i]] += fail[i];
    for (int i = 0; i <= n; ++i) if (par[i] != -1) ++childCount[par[i]];
    double allSum = 0; for (int i = 0; i < n; ++i) allSum += fail[i];

    auto getAns = [&] () {
        double ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += (1 - fail[i]) * fail[par[i]];
        }
        return ans;
    };

    double currentAns = getAns();

    int q; scanf("%d", &q);
    while (q--) {
        int v; double new_f; scanf("%d %lf", &v, &new_f);
        double d = new_f - fail[v];
        double answerChange = d * childCount[v] - (fail[par[v]] + childrenSums[v]) * d;
        currentAns += answerChange;
        fail[v] += d;
        childrenSums[par[v]] += d;
        printf("%.6lf\n", currentAns);
    }
}