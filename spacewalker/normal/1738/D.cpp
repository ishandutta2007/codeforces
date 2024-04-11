#include <bits/stdc++.h>

using namespace std;

vector<int> makeB(vector<int> &p, int k) {
    int n = p.size();
    vector<int> b(n);
    int lastG = n + 1, lastLEQ = 0;
    for (int i = 0; i < n; ++i) {
        int x = p[i];
        if (x <= k) {
            b[x-1] = lastG;
            lastLEQ = x;
        } else {
            b[x-1] = lastLEQ;
            lastG = x;
        }
    }
    return b;
}

pair<vector<int>, int> solve(vector<int> b) {
    // first find the permutation
    int n = b.size();
    vector<vector<int>> kids(n + 2);
    for (int i = 0; i < n; ++i) {
        kids[b[i]].push_back(i+1);
    }
    vector<int> st;
    if (!kids[0].empty()) st = {0};
    else st = {n + 1};
    vector<int> ans, layer1, layer2;
    int cLayer = 0;
    while (!st.empty()) {
        // find the one guy in st that has kids
        int hasKids = -1;
        for (int v : st) if (!kids[v].empty()) hasKids = v;
        if (hasKids != -1) {
            iter_swap(find(begin(st), end(st), hasKids), end(st) - 1);
        }
        ans.insert(end(ans), begin(st), end(st));
        vector<int> &p = (cLayer == 0 ? layer1 : layer2);
        p.insert(end(p), begin(st), end(st));
        cLayer ^= 1;
        if (hasKids != -1) {
            st = kids[hasKids];
        } else {
            st = {};
        }
    }
    vector<int> fans(begin(ans) + 1, end(ans));
    int pk;
    // now, find k
    // if layer 1 contains 0, then it is max of layer 1
    // else it is max of layer 2
    if (find(begin(layer1), end(layer1), 0) != end(layer1)) pk = *max_element(begin(layer1), end(layer1));
    else pk = *min_element(begin(layer1), end(layer1)) - 1;
    return {fans, pk};
}

int main() {
    srand(time(NULL));
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        vector<int> b(n);
        for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
        /*
        vector<int> p(n);
        for (int i = 0; i < n; ++i) scanf("%d", &p[i]);
        int _k = scanf("%d", &_k);
        vector<int> b = makeB(p, _k);
        printf("! GENERATED B:\n");
        for (int v : b) printf("%d ", v);
        printf("\n");
        */
        auto [a, k] = solve(b);
        // assert(makeB(a, k) == b);
        printf("%d\n", k);
        for (int v : a) printf("%d ", v);
        printf("\n");
    }
}