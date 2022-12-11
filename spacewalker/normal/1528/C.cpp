#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> skids, kkids;

vector<int> kentry, kexit;

void computeKTimes(int v, int p, int &ct) {
    kentry[v] = ct++;
    kexit[v] = ct;
    for (int c : kkids[v]) {
        computeKTimes(c, v, ct);
        kexit[v] = ct++;
    }
}

set<pair<int, int>> cLeafSet; // PAIRS ARE STORED IN [R, L]
vector<pair<int, int>> blockedLeaf;

void addToLS(int v) {
    auto pwedeBalot = cLeafSet.lower_bound(make_pair(kentry[v], kexit[v]));
    bool leafBlocked = true;
    if (pwedeBalot == cLeafSet.end()) leafBlocked = false;
    else {
        auto [balotR, balotL] = *pwedeBalot;
        if (!(balotL <= kentry[v] && kexit[v] && balotR)) leafBlocked = false;
    }
    if (leafBlocked) {
        blockedLeaf[v] = *pwedeBalot;
        cLeafSet.erase(pwedeBalot);
    }
    cLeafSet.insert(make_pair(kexit[v], kentry[v]));
}

void removeFromLS(int v) {
    cLeafSet.erase(make_pair(kexit[v], kentry[v]));
    if (blockedLeaf[v] != make_pair(-1, -1)) {
        cLeafSet.insert(blockedLeaf[v]);
        blockedLeaf[v] = make_pair(-1, -1);
    }
}

int getClique(int v, int p) {
    addToLS(v);
    int ans = cLeafSet.size();
    for (int c : skids[v]) {
       ans = max(ans, getClique(c, v)); 
    }
    removeFromLS(v);
    return ans;
}

int solve() {
    int n; scanf("%d", &n);
    skids = kkids = vector<vector<int>>(n);
    for (int i = 1; i < n; ++i) {
        int x; scanf("%d", &x); skids[x-1].push_back(i);
    }
    for (int i = 1; i < n; ++i) {
        int x; scanf("%d", &x); kkids[x-1].push_back(i);
    }
    kentry.assign(n, 0); kexit.assign(n, 0);
    cLeafSet.clear(); blockedLeaf.assign(n, make_pair(-1, -1));
    int t = 0;
    computeKTimes(0, -1, t);
    return getClique(0, -1);
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        printf("%d\n", solve());
    }
}