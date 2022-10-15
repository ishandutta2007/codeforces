#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

struct node {
    node *l, *r, *p;
    int key;
    int cnt;
    int lazy;
} *tree;

void Update(node *x) {
    x->cnt = 1;
    if(x->l) x->cnt += x->l->cnt;
    if(x->r) x->cnt += x->r->cnt;
}

void Lazy(node *x) {
    x->key += x->lazy;
    if(x->l) x->l->lazy += x->lazy;
    if(x->r) x->r->lazy += x->lazy;
    x->lazy = 0;
}

void Rotate(node *x) {
    node *p = x->p;
    node *b;
    if(x == p->l) {
        p->l = b = x->r;
        x->r = p;
    }
    else {
        p->r = b = x->l;
        x->l = p;
    }
    x->p = p->p;
    p->p = x;
    if(b) b->p = p;
    (x->p? p == x->p->l? x->p->l : x->p->r : tree) = x;
    Update(p);
    Update(x);
}

void Splay(node *x) {
    while(x->p) {
        node *p = x->p;
        node *g = p->p;
        if(g) Rotate((x == p->l) == (p == g->l)? p : x);
        Rotate(x);
    }
}

void Insert(int key) {
    node *p = tree, **pp;
    if(!p) {
        node *x = new node;
        tree = x;
        x->l = x->r = x->p = NULL;
        x->key = key;
        x->cnt = 1;
        x->lazy = 0;
        return;
    }
    Lazy(p);
    while(1) {
        if(key == p->key) return;
        if(key < p->key) {
            if(!p->l) {
                pp = &p->l;
                break;
            }
            p = p->l;
            Lazy(p);
        }
        else {
            if(!p->r) {
                pp = &p->r;
                break;
            }
            p = p->r;
            Lazy(p);
        }
    }
    node *x = new node;
    *pp = x;
    x->l = x->r = NULL;
    x->p = p;
    x->key = key;
    x->cnt = 1;
    x->lazy = 0;
    Splay(x);
}

bool Find(int key) {
    node *p = tree;
    node *ret;
    if(!p) return false;
    Lazy(p);
    while(p) {
        if(key < p->key) {
            if(!p->l) break;
            p = p->l;
            Lazy(p);
        }
        else {
            ret = p;
            if(!p->r) break;
            p = p->r;
            Lazy(p);
        }
    }
    Splay(ret);
    return key == ret->key;
}

void Delete(int key) {
    if(!Find(key)) return;
    node *p = tree;
    if(p->l) {
        if(p->r) {
            tree = p->l;
            tree->p = NULL;
            node *x = tree;
            Lazy(x);
            while(x->r) {
                x = x->r;
                Lazy(x);
            }
            x->r = p->r;
            p->r->p = x;
            Splay(x);
            delete p;
            return;
        }
        tree = p->l;
        tree->p = NULL;
        delete p;
        return;
    }
    if(p->r) {
        tree = p->r;
        tree->p = NULL;
        delete p;
        return;
    }
    tree = NULL;
}

void Find_Kth(int k) {
    node *x = tree;
    Lazy(x);
    while(1) {
        while(x->l && x->l->cnt > k) {
            x = x->l;
            Lazy(x);
        }
        if(x->l) k -= x->l->cnt;
        if(!k--) break;
        x = x->r;
        Lazy(x);
    }
    Splay(x);
}

void Interval(int l, int r) {
    Find_Kth(l - 1);
    node *x = tree;
    tree = x->r;
    tree->p = NULL;
    Find_Kth(r - l + 1);
    x->r = tree;
    tree->p = x;
    tree = x;
}

void Add(int l, int r, int z) {
    Interval(l, r);
    node *x = tree->r->l;
    x->lazy += z;
}

int N;
vector<pii> seg;

int main() {
    scanf("%d", &N);
    seg.resize(N);
    for(int i = 0; i < N; i++) {
        scanf("%d %d", &seg[i].first, &seg[i].second);
    }

    for(int i = 0; i <= N + 1; i++) {
        Insert(i? 2e9 + i : 0);
    }

    for(int i = 0; i < N; i++) {
        Find(seg[i].first - 1);
        int lp = tree->l? tree->l->cnt : 0;
        Find(seg[i].second - 1);
        int rp = tree->l? tree->l->cnt : 0;

        if(lp + 1 <= rp) Add(lp + 1, rp, 1);
        Find_Kth(rp + 1);
        Delete(tree->key);
        Insert(seg[i].first);
    }

    int ans = 0;
    for(int i = 1; i <= N; i++) {
        Find_Kth(i);
        if(tree->key < 2e9) {
            ans = i;
        }
    }
    printf("%d", ans);
}