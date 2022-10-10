#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

struct Node {
    Node *l, *r, *par, *pp;
    bool rev;
    int sz, vir;
    long long sq, virSq;

    Node() : l(NULL), r(NULL), par(NULL), pp(NULL), rev(false), sz(1), vir(0), sq(0), virSq(0) {}
};

int sz(Node *u) {
    return u ? u->sz : 0;
}

long long sq(Node *u) {
    return u ? u->sq : 0;
}

void add(Node *u, Node *v) {
    if (!u || !v) return;
    u->vir += v->sz;
    u->virSq += (long long) v->sz * v->sz;
}

void rem(Node *u, Node *v) {
    if (!u || !v) return;
    u->vir -= v->sz;
    u->virSq -= (long long) v->sz * v->sz;
}

void push(Node *u) {
    if (!u || !u->rev) return;
    swap(u->l, u->r);
    if (u->l) u->l->rev ^= true;
    if (u->r) u->r->rev ^= true;
    u->rev = false;
}

void pull(Node *u) {
    if (!u) return;
    push(u->l);
    push(u->r);
    u->sz = 1 + u->vir + sz(u->l) + sz(u->r);
    u->sq = u->virSq + (long long) sz(u->l) * sz(u->l) + (long long) sz(u->r) * sz(u->r);
}

void leftRotate(Node *u) {
    Node *v = u->r;
    if (v) {
        u->r = v->l;
        if (v->l) v->l->par = u;
        v->par = u->par;
    }
    if (!u->par) {
        if (v) {
            v->pp = u->pp;
            u->pp = NULL;
        }
    }
    else if (u == u->par->l) u->par->l = v;
    else u->par->r = v;
    if (v) v->l = u;
    u->par = v;
    pull(u);
    pull(v);
}

void rightRotate(Node *u) {
    Node *v = u->l;
    if (v) {
        u->l = v->r;
        if (v->r) v->r->par = u;
        v->par = u->par;
    }
    if (!u->par) {
        if (v) {
            v->pp = u->pp;
            u->pp = NULL;
        }
    }
    else if (u == u->par->l) u->par->l = v;
    else u->par->r = v;
    if (v) v->r = u;
    u->par = v;
    pull(u);
    pull(v);
}

void splay(Node *u) {
    push(u);
    while (u->par) {
        push(u->par->par);
        push(u->par);
        push(u);
        if (!u->par->par) {
            if (u->par->l == u) rightRotate(u->par);
            else leftRotate(u->par);
        } else if (u->par->l == u && u->par->par->l == u->par) {
            rightRotate(u->par->par);
            rightRotate(u->par);
        } else if (u->par->r == u && u->par->par->r == u->par) {
            leftRotate(u->par->par);
            leftRotate(u->par);
        } else if (u->par->l == u && u->par->par->r == u->par) {
            rightRotate(u->par);
            leftRotate(u->par);
        } else {
            leftRotate(u->par);
            rightRotate(u->par);
        }
    }
}

Node* access(Node *u) {
    splay(u);
    if (u->r) {
        add(u, u->r);
        u->r->pp = u;
        u->r->par = NULL;
        u->r = NULL;
        pull(u);
    }
    Node *v = u;
    while (u->pp) {
        v = u->pp;
        splay(v);
        if (v->r) {
            add(v, v->r);
            v->r->pp = v;
            v->r->par = NULL;
        }
        rem(v, u);
        v->r = u;
        u->par = v;
        u->pp = NULL;
        pull(v);
        splay(u);
    }
    return v;
}

void makeRoot(Node *u) {
    access(u);
    if (u->l) u->l->rev ^= true;
    swap(u->l, u->r);
}

Node* findRoot(Node *u) {
    access(u);
    while (u->l) u = u->l;
    access(u);
    return u;
}

void link(Node *u, Node *v) {
    access(u);
    makeRoot(v);
    u->r = v;
    v->par = u;
    pull(u);
}

void cut(Node *u) {
    access(u);
    if (u->l) {
        u->l->par = NULL;
        u->l = NULL;
        pull(u);
    }
}

Node* lca(Node *u, Node *v) {
    access(u);
    return access(v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> c(n);
    vector<vector<pair<int, int>>> events(n);
    for (int i=0; i<n; i++) {
        cin >> c[i];
        c[i]--;
        events[c[i]].emplace_back(i, 0);
    }
    vector<vector<int>> adj(n);
    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1; i<=m; i++) {
        int u, x;
        cin >> u >> x;
        u--, x--;
        events[c[u]].emplace_back(u, i);
        events[x].emplace_back(u, i);
        c[u] = x;
    }

    vector<int> par(n);
    par[0] = n;

    auto dfs = [&] (auto &self, int u) -> void {
        for (int v : adj[u])
            if (v != par[u]) {
                par[v] = u;
                self(self, v);
            }
    };

    dfs(dfs, 0);
    vector<Node*> lct(n + 1);
    for (int i=0; i<=n; i++)
        lct[i] = new Node();
    for (int i=0; i<n; i++)
        link(lct[par[i]], lct[i]);

    vector<long long> delta(m + 1);
    vector<bool> active(n, true);
    for (int x=0; x<n; x++) {
        for (auto [u, i] : events[x]) {
            if (active[u]) {
                Node *r = findRoot(lct[u]);
                delta[i] -= sq(r);
                cut(lct[u]);
                access(r);
                delta[i] += sq(lct[u]) + sq(r);
            } else {
                access(lct[u]);
                Node *r = findRoot(lct[par[u]]);
                delta[i] -= sq(lct[u]) + sq(r);
                link(lct[par[u]], lct[u]);
                access(r);
                delta[i] += sq(r);
            }
            active[u] = !active[u];
        }
        for (auto [u, i] : events[x])
            if (!active[u]) {
                link(lct[par[u]], lct[u]);
                active[u] = true;
            }
    }

    long long ret = 0;
    for (long long x : delta)
        cout << (ret -= x) << "\n";

    return 0;
}