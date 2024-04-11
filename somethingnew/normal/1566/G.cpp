#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define all(x) (x).begin(), (x).end()
using namespace std;
#define int long long
struct node{
    int x, y;
    set<pair<int, int>> crd;
    node * left = nullptr;
    node * right = nullptr;
    int sz = 1;
    int szsum = 1;
    node(int val, pair<int, int> crdd = {0, 0}) {
        x = val;
        crd = {crdd};
        y = (rand() << 15) ^ rand();
    }
};
inline int getsz(node * root) {
    return root ? root->szsum : 0;
}
inline void upd(node * root) {
    root->szsum = root->sz + getsz(root->left) + getsz(root->right);
}
pair<node *, node *> split(node * root, int k) {
    if (root == nullptr)
        return {nullptr, nullptr};
    if (root->x >= k) {
        auto [r1, r2] = split(root->left, k);
        root->left = r2;
        upd(root);
        return {r1, root};
    } else {
        auto [r1, r2] = split(root->right, k);
        root->right = r1;
        upd(root);
        return {root, r2};
    }
}
node * merge(node * root1, node * root2) {
    if (root1 == nullptr)
        return root2;
    if (root2 == nullptr)
        return root1;
    if (root1->y < root2->y) {
        root1->right = merge(root1->right, root2);
        upd(root1);
        return root1;
    } else {
        root2->left = merge(root1, root2->left);
        upd(root2);
        return root2;
    }
}
void add(node *& root, int x, pair<int, int> crd = {0, 0}) {
    auto [r1, r23] = split(root, x);
    auto [r2, r3] = split(r23, x + 1);
    if (r2 == nullptr)
        r2 = new node(x, crd);
    else {
        r2->sz++;
        if (crd != make_pair(0ll, 0ll))
            r2->crd.insert(crd);
        r2->szsum++;
    }
    root = merge(r1, merge(r2, r3));
}
void erase(node *& root, int x, pair<int, int> crd = {0, 0}) {
    auto [r1, r23] = split(root, x);
    auto [r2, r3] = split(r23, x + 1);
    if (r2 != nullptr) {
        r2->crd.erase(crd);
        r2->sz--;
        r2->szsum--;
    }
    if (r2 == nullptr or r2->sz == 0)
        root = merge(r1, r3);
    else
        root = merge(r1, merge(r2, r3));
}
int getless(node *& root, int x) {
    auto [r1, r2] = split(root, x + 1);
    int val = getsz(r1);
    root = merge(r1, r2);
    return val;
}
int getmore(node *& root, int x) {
    auto [r1, r2] = split(root, x);
    int val = getsz(r2);
    root = merge(r1, r2);
    return val;
}
pair<pair<int, int>, int> getmn(node * a) {
    while (a->left)
        a = a->left;
    return {*a->crd.begin(), a->x};
}
map<pair<int, int>, int> edgeval;
vector<node *> ela;
vector<set<pair<int, int>>> st;
node * all = nullptr;
int get3(int v) {
    int res = 0;
    if (st[v].size() >= 3) {
        auto ii = st[v].begin();
        for (int i = 0; i < 3; ++i) {
            res += ii->first;
            ii++;
        }
        return res;
    } else {
        return 1e18;
    }
}
int get23(int v, int u) {
    if (st[v].size() >= 2 and st[u].size() >= 3) {
        auto itv = st[v].begin();
        itv++;
        auto itu = st[u].begin();
        itu++;
        itu++;
        return itv->first + itu->first;
    }
    return 1e18;
}
int get22(int v, int u) {
    if (st[v].size() >= 2 and st[u].size() >= 2) {
        auto itv = st[v].begin();
        itv++;
        auto itu = st[u].begin();
        itu++;
        if (itv->second != itu->second)
            return itv->first + itu->first;
    }
    return 1e18;
}
int slv() {
    auto [a, valik] = getmn(all);
    int res = min(get22(a.first, a.second), get23(a.first, a.second));
    res = min(res, min(min(get23(a.second,a.first), get3(a.first)), get3(a.second)));
    int l = valik - 1;
    int r = 2e18;
    while (l + 1 < r) {
        int m = l + r >> 1;
        if (getless(ela[a.first], m) + getless(ela[a.second], m) - 1 < getless(all, m)) {
            r = m;
        } else {
            l = m;
        }
    }
    res = min(res, valik + r);
    return res;
}
signed main() {
    cin.tie(0);cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    ela.assign(n, nullptr);
    st.assign(n, {});
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        a--;b--;
        if (a > b)
            swap(a, b);
        edgeval[{a, b}] = w;
        add(ela[a], w);
        add(ela[b], w);
        add(all, w, {a, b});
        st[a].insert({w, b});
        st[b].insert({w, a});
    }
    cout << slv() << '\n';
    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int a, b, w;
            cin >> a >> b >> w;
            a--;b--;
            if (a > b)
                swap(a, b);
            edgeval[{a, b}] = w;
            add(ela[a], w);
            add(ela[b], w);
            add(all, w, {a, b});
            st[a].insert({w, b});
            st[b].insert({w, a});
        } else {
            int a, b, w;
            cin >> a >> b;
            a--;b--;
            if (a > b)
                swap(a, b);
            w = edgeval[{a, b}];
            erase(ela[a], w);
            erase(ela[b], w);
            erase(all, w, {a, b});
            st[a].erase({w, b});
            st[b].erase({w, a});
        }
        cout << slv() << '\n';
    }
}