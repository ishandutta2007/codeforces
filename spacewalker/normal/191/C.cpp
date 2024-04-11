#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> tree;
vector<int> parent, eToPar, enterTime;
vector<int> heightInETour, eTour;
vector<int> pamanaSaBata;

void makeTreeStats(int v, int p, int cLevel, int etp) {
//    printf("MTS %d %d %d %d\n", v, p, cLevel, etp);
    parent[v] = p;
    eToPar[v] = etp;
    enterTime[v] = eTour.size();
    heightInETour.push_back(cLevel);
    eTour.push_back(v);
    for (auto [nxt, eid] : tree[v]) {
        if (nxt == p) continue;
        makeTreeStats(nxt, v, cLevel + 1, eid);
        heightInETour.push_back(cLevel);
        eTour.push_back(v);
    }
}

struct advSparseTable {
    int n;
    vector<int> orig;
    vector<vector<int>> table;
    int minIndex(int i, int j) {
        return (orig[i] != orig[j] ? (orig[i] < orig[j] ? i : j) : min(i, j));
    }
    advSparseTable() {}
    advSparseTable(vector<int> &arr) : n(arr.size()), orig(arr), table(20, vector<int>(arr.size(), -1)) {
        iota(begin(table[0]), end(table[0]), 0);
//        for (int x : arr) printf("ETH %d\n", x);
        for (int layer = 1; layer < 20; ++layer) {
            for (int i = 0; i + (1 << layer) <= n; ++i) {
                table[layer][i] = minIndex(table[layer-1][i], table[layer-1][i + (1 << (layer-1))]);
            }
        }
    }
    int getMin(int i, int j) {
        int ltf = log2(j - i + 1);
        return minIndex(table[ltf][i], table[ltf][j + 1 - (1 << ltf)]);
    }
};

advSparseTable yeeter;

void ibigayAngPamana(int v, int p) {
//    printf("%d FINAL PAMANA %d\n", v, pamanaSaBata[v]);
    for (auto [nxt, eid] : tree[v]) {
        if (nxt == p) continue;
        ibigayAngPamana(nxt, v);
        pamanaSaBata[v] += pamanaSaBata[nxt];
    }
}

int LCA(int i, int j) {
    int u = enterTime[i], v = enterTime[j];
    if (u > v) swap(u, v);
//    printf("checking from %d %d\n", u, v);
    return eTour[yeeter.getMin(u, v)];
}

int main() {
    int n; scanf("%d", &n);
    vector<pair<int, int>> eList;
    for (int i = 0; i < n - 1; ++i) {
        int u, v; scanf("%d %d", &u, &v); --u; --v;
        eList.emplace_back(u, v);
    }
    tree.assign(n, vector<pair<int, int>>());
    parent.assign(n, -1);
    eToPar.assign(n, 0);
    enterTime.assign(n, 0);
    for (int i = 0; i < n - 1; ++i) {
        auto [u, v] = eList[i];
//        printf("EDGE %d %d\n", u, v);
        tree[u].emplace_back(v, i);
        tree[v].emplace_back(u, i);
    } 
    makeTreeStats(0, -1, 0, -1);
//    for (int x : eTour) printf("et %d\n", x);
    yeeter = advSparseTable(heightInETour);
    pamanaSaBata.assign(n, 0);
    int k; scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        --a; --b;
//        printf("%d %d LCA %d\n", a, b, LCA(a, b));
        int r = LCA(a, b);
        if (a != r) {++pamanaSaBata[a]; --pamanaSaBata[r];}
        if (b != r) {++pamanaSaBata[b]; --pamanaSaBata[r];}
    }
//    for (int i = 0; i < n; ++i) printf("%d has %d pamana\n", i, pamanaSaBata[i]);
    ibigayAngPamana(0, -1);
    vector<int> ans(n - 1);
    for (int i = 1; i < n; ++i) ans[eToPar[i]] = pamanaSaBata[i];
    for (int x : ans) printf("%d ", x);
    printf("\n");

    return 0;
}