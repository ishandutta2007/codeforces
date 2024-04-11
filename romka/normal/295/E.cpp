#include <cstdio>
#include <cassert>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <memory.h>
#include <cstdlib>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int R() {
    return rand() & 32767;
}

struct Node {
    int x, y;
    ll ans, sr, sl, xl, xr, sz;
    Node *l, *r;

    Node(int xx) {
        x = xx;
        y = (R() << 15) + R();
        ans = sr = sl = 0;
        xl = xr = x;
        sz = 1;
        l = r = 0;
    }
};


Node* merge(Node* t1, Node* t2) {
	if (t1 == NULL) return t2;
    if (t2 == NULL) return t1;

    // fprintf(stderr, "%lld %lld\n", t1->xr, t2->xl);
    assert(t1->xr < t2->xl);

    ll _ans = t1->ans + t2->ans + t1->sr * t2->sz + t2->sl * t1->sz + (t2->xl - t1->xr) * (t1->sz * t2->sz);
    ll _sr = t1->sr + t1->sz * (t2->xr - t1->xr) + t2->sr;
    ll _sl = t2->sl + t2->sz * (t2->xl - t1->xl) + t1->sl;
    ll _xl = t1->xl;
    ll _xr = t2->xr;
    ll _sz = t1->sz + t2->sz;

    if (t1->y > t2->y) {
        t1->r = merge(t1->r, t2);
        t1->ans = _ans;
        t1->sr = _sr;
        t1->sl = _sl;
        t1->xl = _xl;
        t1->xr = _xr;
        t1->sz = _sz;
        return t1;
    } else {
        t2->l = merge(t1, t2->l);
        t2->ans = _ans;
        t2->sr = _sr;
        t2->sl = _sl;
        t2->xl = _xl;
        t2->xr = _xr;
        t2->sz = _sz;
        return t2;
    }
}

void update(Node*& cur) {
    if (cur == NULL) return;

    Node* l = cur->l;
    Node* r = cur->r;
    cur->l = cur->r = 0;
    cur->ans = cur->sr = cur->sl = 0;
    cur->xl = cur->xr = cur->x;
    cur->sz = 1;

    cur = merge(l, cur);
    cur = merge(cur, r);    
}

void split(Node* cur, Node*& l, Node*& r, int X) {
	if (cur == NULL) {
        l = r = NULL;
        return;
    }

    if (cur->x < X) {
        l = cur;
        split(l->r, l->r, r, X);
        update(l);
    } else {
        r = cur;
        split(r->l, l, r->l, X);
        update(r);
    }
}

const int maxn = 100010;

int n, m, x[maxn], pos[maxn], t, a, b;

int main() {
    srand(0);
    scanf("%d", &n);
    forn(i, n) scanf("%d", &x[i]), pos[i] = x[i];
    sort(x, x+n);
    Node* root = 0;
    Node *t1, *t2, *t3, *tb;
    forn(i, n) root = merge(root, new Node(x[i]));
    scanf("%d", &m);
    forn(i, m) {
        scanf("%d %d %d", &t, &a, &b);
        if (t == 1) {
            a--;
            split(root, t1, t2, pos[a]);
            split(t2, t2, t3, pos[a] + 1);
            pos[a] += b;
            t2->x = pos[a];
            t2->xl = t2->xr = t2->x;
            if (b > 0) {
                split(t3, t3, tb, pos[a]);
                // fprintf(stderr, "a1\n");
                root = merge(t1, t3);
                // fprintf(stderr, "a2\n");
                root = merge(root, t2);
                // fprintf(stderr, "a3\n");
                root = merge(root, tb);
                // fprintf(stderr, "a4\n");
            } else {
                split(t1, tb, t1, pos[a]);
                // fprintf(stderr, "b1\n");
                root = merge(tb, t2);
                // fprintf(stderr, "b2\n");
                root = merge(root, t1);
                // fprintf(stderr, "b3\n");
                root = merge(root, t3);
                // fprintf(stderr, "b4\n");
            }
        } else {
            split(root, t1, t2, a);
            split(t2, t2, t3, b+1);
            if (t2)
	            printf("%I64d\n", t2->ans);
	       	else
	       		printf("0\n");
            root = merge(t1, t2);
            root = merge(root, t3);
        }
    } 
    return 0;
}