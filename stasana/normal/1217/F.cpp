#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

inline void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

struct Edge {
    int v, u, id, need;

    Edge(int v, int u, int id, int need)
            : v(v), u(u), id(id), need(need) {}
};

struct Dsu {
    vector<int> dsu;
    vector<pair<int, int>> a;

    Dsu(int n = 0) {
        dsu.resize(n, -1);
    }

    int get(int x) {
        return dsu[x] < 0 ? x : get(dsu[x]);
    }

    int merge(int x, int y) {
        x = get(x);
        y = get(y);
        if (x == y) {
            return 0;
        }
        a.emplace_back(x, dsu[x]);
        a.emplace_back(y, dsu[y]);
        if (dsu[x] < dsu[y]) {
            dsu[x] += dsu[y];
            dsu[y] = x;
        } else {
            dsu[y] += dsu[x];
            dsu[x] = y;
        }
        return 1;
    }

    bool check(int x, int y) {
        x = get(x);
        y = get(y);
        return x == y;
    }

    void abort() {
        dsu[a.back().first] = a.back().second;
        a.pop_back();
        dsu[a.back().first] = a.back().second;
        a.pop_back();
    }
};

typedef struct Node* pNode;
struct Node {
    pNode child_left, child_right;
    int left, right;
    vector<pair<int, int>> a;

    Node(int left, int right)
            : child_left(nullptr), child_right(nullptr), left(left), right(right) {}
};

int n, m;
vector<Edge> edges;
vector<Edge> quest;
vector<int> ans;
set<pair<int, int>> exist_edges;
Dsu dsu;
int ptr = 0;

inline int get_ans(int x) {
    if (x == -1) {
        return 0;
    }
    return ans[x];
}

pNode build(int left, int right) {
    pNode root = new Node(left, right);
    if (right - left == 1) {
        return root;
    }
    root->child_left = build(left, left + right >> 1);
    root->child_right = build(left + right >> 1, right);
    return root;
}

void add(pNode root, int left, int right, pair<int, int> edge) {
    if (root->left >= right || root->right <= left) {
        return;
    }
    if (root->left >= left && root->right <= right) {
        root->a.emplace_back(edge);
        return;
    }
    add(root->child_left, left, right, edge);
    add(root->child_right, left, right, edge);
}

void go(pNode root) {
    int cnt = 0;
    for (auto i : root->a) {
        if (exist_edges.find(i) != exist_edges.end()) {
            cnt += dsu.merge(i.first, i.second);
        }
    }
    if (root->right - root->left == 1) {
        int id = get_ans(root->left - 1) + root->left * 2;
        ans[root->left] = dsu.check(quest[id].v, quest[id].u);
        while (ptr < edges.size() && edges[ptr].id <= root->left) {
            if (ans[root->left] == edges[ptr].need) {
                pair<int, int> p = make_pair(edges[ptr].v, edges[ptr].u);
                if (exist_edges.find(p) == exist_edges.end()) {
                    exist_edges.insert(p);
                } else {
                    exist_edges.erase(p);
                }
            }
            ++ptr;
        }
    } else {
        go(root->child_left);
        go(root->child_right);
    }
    while (cnt) {
        --cnt;
        dsu.abort();
    }
}

inline void solve() {
    cin >> n >> m;
    dsu = Dsu(n);
    for (int i = 0; i < m; ++i) {
        int type;
        cin >> type;
        int v, u;
        cin >> v >> u;
        int v0 = v - 1;
        int u0 = u - 1;
        if (v0 > u0) {
            swap(v0, u0);
        }
        int v1 = v % n;
        int u1 = u % n;
        if (v1 > u1) {
            swap(v1, u1);
        }
        if (type == 1) {
            edges.emplace_back(v0, u0, (int)ans.size() - 1, 0);
            edges.emplace_back(v1, u1, (int)ans.size() - 1, 1);
        } else {
            quest.emplace_back(v0, u0, (int)ans.size() - 1, 0);
            quest.emplace_back(v1, u1, (int)ans.size() - 1, 1);
            ans.emplace_back(-1);
        }
    }
    pNode root = build(0, ans.size());
    map<pair<int, int>, int> id;
    for (int i = 0; i < (int)(edges.size()); ++i) {
        pair<int, int> p = make_pair(edges[i].v, edges[i].u);
        if (id.find(p) != id.end()) {
            add(root, id[p] + 1, edges[i].id + 1, p);
        }
        id[p] = edges[i].id;
    }
    for (auto i : id) {
        add(root, i.second + 1, ans.size(), i.first);
    }
    while (ptr < edges.size() && edges[ptr].id <= -1) {
        if (0 == edges[ptr].need) {
            pair<int, int> p = make_pair(edges[ptr].v, edges[ptr].u);
            if (exist_edges.find(p) == exist_edges.end()) {
                exist_edges.insert(p);
            } else {
                exist_edges.erase(p);
            }
        }
        ++ptr;
    }
    go(root);
    for (int i : ans) {
        cout << i;
    }
    cout << endl;
}

int main() {
    start();
    solve();
    return 0;
}