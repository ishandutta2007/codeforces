#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;
const int Q = 31;

struct TNode {
    vector <TNode*> edges;
    bool term;
};

TNode *new_node() {
    vector <TNode*> edges(Q, nullptr);
    return new TNode({edges, false});
}

void add(TNode *root, string &s) {
    for (char c : s) {
        int k = c - 'a';
        if (!root->edges[k]) {
            root->edges[k] = new_node();
        }
        root = root->edges[k];
    }
    root->term = true;
}

multiset <int> dfs(TNode *v, int h) {
    multiset <int> now;
    for (auto u : v->edges) {
        if (!u) continue;
        auto d = dfs(u, h + 1);
        if (now.size() < d.size()) swap(now, d);
        for (int x : d) now.insert(x);
    }
    if (!v->term) {
        now.erase(now.find(*now.rbegin()));
    }
    now.insert(h);
    return now;
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int n;
    cin >> n;
    TNode *root = new_node();
    root->term = true;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        add(root, s);
    }
    auto res = dfs(root, 0);
    ll sum = 0;
    for (auto x : res) {
        sum += x;
    }
    cout << sum;
}