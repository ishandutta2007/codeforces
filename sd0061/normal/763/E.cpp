#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 500005;
const int INF = 1 << 30;

int n , m , Q;
struct edge {
    int x , y;
    bool operator < (const edge& R) const {
        return y < R.y;
    }
}e[N];
struct query {
    int x , y , id;
    bool operator < (const query& R) const {
        return y < R.y;
    }
}q[N];

struct Node {
    Node *ch[2] , *p , *fa;
    int size;
    int val;
    pair<int , int> mn;
    bool rev;
    Node () {
        mn = make_pair(INF , 0);
        size = val;
        rev = 0;
    }
    bool d() {
        return this == p->ch[1];
    }
    void setc(Node *c , int d) {
        ch[d] = c;
        c->p = this;
    }
    void reverse() {
        rev ^= 1;
        swap(ch[0] , ch[1]);
    }
    void pushdown();
    void pushup() {
        size = ch[0]->size + ch[1]->size + 1;
        mn = min(ch[0]->mn , ch[1]->mn);
        mn = min(mn , make_pair(e[val].x , val));
    }
}Tnull , *null = &Tnull;
Node mem[N] , *C = mem;
void Node::pushdown() {
    if (rev) {
        if (ch[0] != null)
            ch[0]->reverse();
        if (ch[1] != null)
            ch[1]->reverse();
        rev ^= 1;
    }
}
Node* newnode(int v) {
    Node *p = C ++;
    p->ch[0] = p->ch[1] = p->p = p->fa = null;
    p->size = 1;
    p->val = v;
    p->rev = 0;
    p->mn = make_pair(e[v].x , v);
    return p;
}
void rotate(Node *t) {
    Node *p = t->p;
    int d = t->d();
    p->p->setc(t , p->d());
    p->setc(t->ch[!d] , d);
    t->setc(p , !d);
    p->pushup();
    t->fa = p->fa;
}
void update(Node *t) {
    static Node* Stack[N];
    int top = 0;
    while (t != null) {
        Stack[top ++] = t;
        t = t->p;
    }
    for (int i = top - 1 ; i >= 0 ; -- i)
        Stack[i]->pushdown();
}
void splay(Node *t , Node *f = null) {
    update(t);
    while (t->p != f) {
        if (t->p->p == f)
            rotate(t);
        else {
            if (t->d() == t->p->d())
                rotate(t->p) , rotate(t);
            else
                rotate(t) , rotate(t);
        }
    }
    t->pushup();
}
Node* expose(Node *x) {
    Node *y = null;
    while (x != null) {
        splay(x);
        Node *z = x->ch[1];
        z->p = null;
        z->fa = x;
        x->setc(y , 1);
        y->fa = null;
        //x->pushup();
        y = x , x = x->fa;
    }
    return y;
}
Node* findroot(Node *x) {
    expose(x);
    splay(x);
    while (x->ch[0] != null)
        x = x->ch[0];
    splay(x);
    return x;
}
void setroot(Node *x) {
    expose(x);
    splay(x);
    x->reverse();
}
void link(Node *x , Node *y) {
    setroot(x);
    x->fa = y;
    expose(x);
}
void cut(Node *x , Node *y) {
    setroot(x);
    expose(y);
    splay(x);
    x->setc(null , 1);
    x->pushup();
    y->fa = y->p = null;
}
Node *V[N];
int c[N] , res[N];
void work() {
    int K;
    scanf("%d%d%d" , &n , &K , &m);
    C = mem;
    for (int i = 1 ; i <= m ; ++ i) {
        scanf("%d%d" , &e[i].x , &e[i].y);
        if (e[i].x > e[i].y)
            swap(e[i].x , e[i].y);
    }
    scanf("%d" , &Q);
    sort(e + 1 , e + 1 + m);
    for (int i = 1 ; i <= Q ; ++ i) {
        scanf("%d%d" ,&q[i].x , &q[i].y);
        q[i].id = i;
        res[i] -= q[i].x - 1 + n - q[i].y;
    }
    sort(q + 1 , q + Q + 1);
    e[0].x = INF;
    for (int i = 1 ; i <= n ; ++ i)
        V[i] = newnode(0);
    memset(c , 0 , n + 1 << 2);
    for (int i = 1 , j = 1 , l = 1; i <= n ; ++ i) {
        while (j <= m && e[j].y <= i) {
            int x = e[j].x , y = e[j].y;
            if (findroot(V[x]) != findroot(V[y])) {
                V[n + j] = newnode(j);
                link(V[x] , V[n + j]);
                link(V[y] , V[n + j]);
                for (int k = x ; k > 0 ; k -= k & -k)
                    ++ c[k];
            } else if (x != y) {
                setroot(V[x]);
                expose(V[y]);
                splay(V[y]);
                if (V[y]->mn.first < x) {
                    int p = V[y]->mn.second;
                    cut(V[e[p].x] , V[n + p]);
                    cut(V[e[p].y] , V[n + p]);
                    for (int k = e[p].x ; k > 0 ; k -= k & -k)
                        -- c[k];
                    V[n + j] = newnode(j);
                    link(V[x] , V[n + j]);
                    link(V[y] , V[n + j]);
                    for (int k = x ; k > 0 ; k -= k & -k)
                        ++ c[k];
                }
            }
            ++ j;
        }
        while (l <= Q && q[l].y <= i) {
            int ans = n;
            for (int k = q[l].x ; k <= n ; k += k & -k)
                ans -= c[k];
            res[q[l].id] += ans;
            ++ l;
        }
    }
    for (int i = 1 ; i <= Q ; ++ i)
        printf("%d\n" , res[i]);
}

int main() {
    work();
    return 0;
}