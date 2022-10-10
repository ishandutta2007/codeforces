#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

mt19937 rnd;

struct node {
    int k, pr, sz;
    node *left, *right;
    node(int k) : left(nullptr), right(nullptr), k(k), pr(rnd()), sz(1) {}
};

int sz(node *n) { return n ? n->sz : 0; }
void upd(node *n) { n->sz = sz(n->left) + sz(n->right) + 1; }

pair<node*, node*> split(node* hd, int k) {
    if(!hd) return {nullptr, nullptr};
    if(hd->k <= k) {
        auto p = split(hd->right, k);
        hd->right = p.first;
        upd(hd);
        return {hd, p.second};
    }
    else {
        auto p = split(hd->left, k);
        hd->left = p.second;
        upd(hd);
        return {p.first, hd};
    }
}

node* merge(node *t1, node *t2) {
    if(!t1 || !t2) return t1 ?: t2;
    if(t1->pr > t2->pr) {
        t1->right = merge(t1->right, t2);
        upd(t1);
        return t1;
    }
    t2->left = merge(t1, t2->left);
    upd(t2);
    return t2;
}

node* insert(node *t, node *n) {
    if(!t) return n;
    if(t->pr < n->pr) {
        auto p = split(t, n->k);
        n->left = p.first;
        n->right = p.second;
        upd(n);
        return n;
    }
    if(n->k <= t->k)
        t->left = insert(t->left, n);
    else
        t->right = insert(t->right, n);
    upd(t);
    return t;
}

int cnt(node *t, int bnd) {
    if(!t) return 0;
    if(t->k <= bnd)
        return sz(t->left) + 1 + cnt(t->right, bnd);
    return cnt(t->left, bnd);
}

node* trps[10100];

struct ev {
    int x, r, f;
};
vector<ev> all;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int x, r, f;
        cin >> x >> r >> f;
        all.push_back({x, r, f});
    }
    sort(all.begin(), all.end(), [](ev a, ev b){ return a.r > b.r; });
    ll ans = 0;
    for(auto e : all) {
        for(int f = max(e.f - k, 1); f <= e.f + k; f++)
            ans += cnt(trps[f], e.x + e.r) - cnt(trps[f], e.x - e.r - 1);
        trps[e.f] = insert(trps[e.f], new node(e.x));
    }
    cout << ans << '\n';
}