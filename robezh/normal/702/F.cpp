#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define sz(x) (int)((x).size())
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (int i = (a); i < (b); i++)
const int INF = (int)1e9 + 50;
const int N = (int)3e5 + 50;

mt19937 rng(23333);

struct Node {
    Node *l = 0, *r = 0;
    int y, c = 1; // y: random key
    pii v;
    int r0, a0;
    int add;

    Node(int v, int idx) : y(rng()), v({v, idx}), add(0), r0(0), a0(0) {
    }
    void recalc();
    void push_down();
};

int cnt(Node* n) { return n ? n->c : 0; }


void Node::recalc() {
    c = cnt(l) + cnt(r) + 1;
//    if(l) l->par = this;
//    if(r) r->par = this;
}

void add_val(Node* n, int val, int v0) {
    if(!n) return ;
    n->a0 += v0;
    n->r0 += v0;

    n->add += val;
    n->v.first += val;
}

void Node::push_down() {
    if(add || a0) {
        add_val(l, add, a0);
        add_val(r, add, a0);
        add = 0;
        a0 = 0;
    }
}

//template<class F> void each(Node* n, F f) {
//    if (n) { each(n->l, f); f(n->val); each(n->r, f); }
//}

pair<Node*, Node*> sp(Node* n, int k) {
    if (!n) return {};
    n->push_down();
    if (cnt(n->l) >= k) { // "n->val >= v" for lower_bound(v)
        auto pa = sp(n->l, k);
        n->l = pa.second;
        n->recalc();
        return {pa.first, n};
    } else {
        auto pa = sp(n->r, k - cnt(n->l) - 1);
        n->r = pa.first;
        n->recalc();
        return {n, pa.second};
    }
}

pair<Node*, Node*> split(Node *n, int k) {
    auto p = sp(n, k);
    return p;
}

Node* merge(Node* l, Node* r) {
    if (!l) return r;
    if (!r) return l;
    l->push_down();
    r->push_down();

    if (l->y > r->y) {
        l->r = merge(l->r, r);
        l->recalc();
        return l;
    } else {
        r->l = merge(l, r->l);
        r->recalc();
        return r;
    }
}

Node* ins(Node* t, Node* n, int pos) {
    auto pa = sp(t, pos);
    return merge(merge(pa.first, n), pa.second);
}

Node* del(Node* t, int pos) {
    auto pa = sp(t, pos);
    auto pb = sp(pa.second, 1);
    return merge(pa.first, pb.second);
}

void print(Node *n, int d) {
    if (n) {
        n->push_down();
        print(n->l, d + 1);
//        cout << (n->v) << " ";
        print(n->r, d + 1);
        n->recalc();
    }
}


typedef pair<Node*, int> pni;
Node *rt;

Node* find(Node *cur, int k) {
    if(!cur) return 0;
    if(cnt(cur->l) > k) return find(cur->l, k);
    else if(cnt(cur -> l) == k) return cur;
    else return find(cur->r, k - cnt(cur->l) - 1);
}

pni lower_bound(Node *cur, pii v, int pos) {
    if(!cur) return {0, pos};
    cur->push_down();
    if(cur->v >= v) {
        auto res = lower_bound(cur->l, v, pos);
        if(res.first) return res;
        else return {cur, pos + cnt(cur->l)};
    } else return lower_bound(cur->r, v, pos + cnt(cur->l) + 1);
}

Node *getright(Node *cur) {
    while(cur->r) {
        cur->push_down();
        cur = cur->r;
    }
    return cur;
}

Node *getleft(Node *cur) {
    while(cur->l) {
        cur->push_down();
        cur = cur->l;
    }
    return cur;
}

void dfs(Node *n) {
    if(!n) return ;
    n->push_down();
    dfs(n->l);
    dfs(n->r);
}

int n;
struct P{
    int c, q;
} p[N];

int q;
pii b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) {
        cin >> p[i].c >> p[i].q;
    }
    sort(p, p + n, [](const P &p0, const P &p1) {
        return p0.q != p1.q ? p0.q > p1.q : p0.c < p1.c;
    });

    cin >> q;
    rep(i, 0, q) {
        cin >> b[i].first;
        b[i].second = i;
    }
    sort(b, b + q);
    vector<Node*> vs(q);

    rep(i, 0, q) {
        vs[b[i].second] = new Node(b[i].first, b[i].second);
        rt = ins(rt, vs[b[i].second], i);
    }
//    print(rt, 0);
//    cout << endl;
    rep(i, 0, n) {
        auto it = lower_bound(rt, {p[i].c, -1}, 0);
        auto p0 = split(rt, it.second);
        Node *r0, *r1;
        tie(r0, r1) = p0;
        add_val(r1, -p[i].c, 1);

//        cout << "two tree:\n";
//        print(r0, 0);
//        cout << endl;
//        print(r1, 0);
//        cout << endl;
        if(r0) {
            Node* rmx = getright(r0);
            while (r1 && rmx->v > getleft(r1) ->v) {
                auto p1 = split(r1, 1);
//            cout << "one node\n";
//            print(p1.first, 0);
//            cout << endl;
                r1 = p1.second;
                int bl = lower_bound(r0, p1.first->v, 0).second;

                r0 = ins(r0, p1.first, bl);
            }
        }
        rt = merge(r0, r1);
    }
    dfs(rt);
    rep(i, 0, q) {
        cout << vs[i]->r0 << " ";
    }
    cout << '\n';


}