#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 1e6 + 113;
const int K = 1e5 + 113;
const int M = 1e9 + 7;
const int A = 26;

/*

*/

mt19937 rnd(3666);

struct Node {
    int x, y, val, sz;

    Node* lf;
    Node* rg;

    Node() : y(rnd()), sz(1), lf(nullptr), rg(nullptr) {};

    Node(int x1, int val1) : x(x1), y(rnd()), val(val1), sz(1), lf(nullptr), rg(nullptr) {};
};

inline int get_sz(Node* a) {
    return (a ? a->sz : 0);
}

inline Node* upd(Node* a) {
    if(!a)
        return a;

    a->sz = get_sz(a->lf) + get_sz(a->rg) + 1;
    return a;
}

Node* merge(Node* a, Node* b) {
    if(!a)
        return b;

    if(!b)
        return a;

    if(a->y > b->y) {
        a->rg = merge(a->rg, b);
        return upd(a);
    } else {
        b->lf = merge(a, b->lf);
        return upd(b);
    }
}

pair<Node*, Node*> split(Node* a, int x, int val) {
    if(!a)
        return {a, a};

    if(x < a->x || x == a->x && val < a->val) {
        auto p = split(a->lf, x, val);
        a->lf = p.s;
        return {p.f, upd(a)};
    } else {
        auto p = split(a->rg, x, val);
        a->rg = p.f;
        return {upd(a), p.s};
    }
}

int get_low(Node* a, int x) {
    if(!a)
        return 0;

    if(a->x < x)
        return get_sz(a->lf) + 1 + get_low(a->rg, x);
    else
        return get_low(a->lf, x);
}

int getk(Node* a, int k) {
    if(!a)
        return -2;

    if(get_sz(a->lf) == k)
        return a->val;
    else if(get_sz(a->lf) < k)
        return getk(a->rg, k - get_sz(a->lf) - 1);
    else
        return getk(a->lf, k);
}

Node* erase(Node* a, Node* b) {
    if(!b)
        return a;

    if(a == b)
        return merge(a->lf, a->rg);

    if(b->x < a->x || b->x == a->x && b->val < a->val) {
        a->lf = erase(a->lf, b);
        return upd(a);
    } else {
        a->rg = erase(a->rg, b);
        return upd(a);
    }
}

Node* insert(Node* root, Node* b) {
    if(!root)
        return b;

    if(root->y < b->y) {
        auto p = split(root, b->x, b->val);
        b->lf = p.f;
        b->rg = p.s;
        return upd(b);
    } else if(b->x < root->x || b->x == root->x && b->val < root->val) {
        root->lf = insert(root->lf, b);
        return upd(root);
    } else {
        root->rg = insert(root->rg, b);
        return upd(root);
    }
}

Node* ptr[N];

Node* insert(Node* root, int val, int d) {
    if(ptr[val]->x > 0)
        root = erase(root, ptr[val]);

    ptr[val]->x += d;
    ptr[val]->lf = ptr[val]->rg = nullptr;
    ptr[val]->sz = 1;

    return (ptr[val]->x != 0 ? insert(root, ptr[val]) : root);
}

//int get(Node* root, int l, int k) {
////    auto p = split(root, l, -1);
//
//    int res = getk(p.s, k + get_low(root, l));
//
//    root = merge(p.f, p.s);
//
//    return res;
//}

vector<int> g[N];
int a[N];
bool used[N];

int qv[N], ql[N], qk[N], res[N];
vector<int> qr[N];

void dfs(int v, Node* root) {
    root = insert(root, a[v], 1);

    for(auto i : qr[v]) {
        res[i] = getk(root, qk[i] + get_low(root, ql[i]));//get(root, ql[i], qk[i]);
    }

    for(auto u : g[v]) {
        dfs(u, root);
    }

    root = insert(root, a[v], -1);
}

/*
1
5 5
1 2 1 1 2
1 1 2 2
3 1 1
2 1 2
4 1 1
4 2 1
4 2 2

1
5 1
1 2 1 1 2
1 1 2 2
2 1 2
*/

void solve() {
    int n, q;
    cin >> n >> q;

    for(int i = 0; i < n; i++) {
        g[i].erase(g[i].begin(), g[i].end());
        qr[i].erase(qr[i].begin(), qr[i].end());
    }


    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        used[a[i]] = true;
    }


    for(int i = 1; i < n; i++) {
        int p;
        cin >> p;

        p--;

        g[p].push_back(i);
    }

    for(int i = 0; i < q; i++) {
        cin >> qv[i] >> ql[i] >> qk[i];

        qv[i]--;
        qk[i]--;

        qr[qv[i]].push_back(i);
    }

    Node* root = nullptr;

    for(int i = 0; i < n; i++) if(used[i]) {
        ptr[i] = new Node(0, i);
//        root = merge(root, ptr[i]);
    }

    dfs(0, root);

    for(int i = 0; i < q; i++)
        cout << res[i] + 1 << ' ';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}