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
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

struct Node {
    Node *l, *r, *par, *pp;
    bool rev;
    int a, c;
    pair<int, int> cur, mn;

    Node(int _a, int _c, int id) : l(NULL), r(NULL), par(NULL), pp(NULL), rev(false), a(_a), c(_c), cur(c, id), mn(cur) {}
};

pair<int, int> mn(Node *u) {
    return u ? u->mn : make_pair(INT_MAX, INT_MAX);
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
    u->mn = min({u->cur, mn(u->l), mn(u->r)});
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
            v->r->pp = v;
            v->r->par = NULL;
        }
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

Node *lct[300005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q, a0, c0;
    cin >> q >> a0 >> c0;
    lct[0] = new Node(a0, c0, 0);
    for (int i=1; i<=q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int p, a, c;
            cin >> p >> a >> c;
            lct[i] = new Node(a, c, i);
            link(lct[p], lct[i]);
        } else {
            int v, w;
            cin >> v >> w;
            long long amt = 0, money = 0;
            while (w > 0) {
                access(lct[v]);
                auto best = lct[v]->mn;
                if (best.second == INT_MAX || lct[best.second]->cur.first == INT_MAX)
                    break;
                access(lct[best.second]);
                int change = min(w, lct[best.second]->a);
                assert(change > 0);
                amt += change;
                money += (long long) change * lct[best.second]->c;
                w -= change;
                lct[best.second]->a -= change;
                if (lct[best.second]->a == 0)
                    lct[best.second]->cur = {INT_MAX, INT_MAX};
                pull(lct[best.second]);
            }
            cout << amt << " " << money << endl;
        }
    }

    return 0;
}