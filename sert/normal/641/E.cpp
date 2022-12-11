#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
vector <pair<ld, ld> > ans;
const int N = 1e6 + 34;
int a[N], t[N], x[N], lst, cur, n;
pair <int, int> h[N];

struct Node {
    int x;
    int y, sum, cur;
    Node *l, *r;
};

ll sum(Node *v) {
    return (v == nullptr ? 0 : v->sum);
}

void relax(Node *v) {
    if (v == nullptr)
        return;
    v->sum = v->cur + sum(v->l) + sum(v->r);
}

void split(Node *v, ll x, Node *&l, Node *&r) {
    if (v == nullptr) {
        l = r = nullptr;
        return;
    }
    if (v->x > x) {
        split(v->l, x, l, v->l);
        r = v;
    } else {
        split(v->r, x, v->r, r);
        l = v;
    }
    relax(v);
}

Node* merg(Node *v1, Node *v2) {
    if (v1 == nullptr) return v2;
    if (v2 == nullptr) return v1;
    if (v1->y > v2->y) {
        v1->r = merg(v1->r, v2);
        relax(v1);
        return v1;
    } else {
        v2->l = merg(v1, v2->l);
        relax(v2);
        return v2;
    }
}

void ins(Node *&root, ll x, ll val) {
    Node *l, *r;
    Node *v = new Node();
    v->x = x;
    v->y = (rand() << 16) ^ rand();
    v->cur = v->sum = val;
    v->l = v->r = nullptr;

    split(root, x, l, r);
    root = merg(merg(l, v), r);
}

void getsum(Node *&root, ll x) {
    Node *l, *r;
    split(root, x, l, r);
    printf("%I64d\n", sum(l));
    root = merg(l, r);
}

vector <Node*> root;
Node *curroot;

int main() {
    srand(3431);
    //freopen("a.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", a + i, t + i, &h[i].first);
        h[i].second = i;
    }
    sort(h, h + n);
    lst = h[0].first;
    for (int i = 0; i < n; i++) {
        if (h[i].first != lst) {
            cur++;
            lst = h[i].first;
        }
        h[i].first = h[i].second;
        h[i].second = cur;
    }
    sort(h, h + n);
    for (int i = 0; i < n; i++)
        x[i] = h[i].second;
    /*for (int i = 0; i < n; i++)
        cout << x[i] << " ";*/

    for (int i = 0; i < n; i++)
        root.push_back(nullptr);

    for (int i = 0; i < n; i++) {
        cur = x[i];
        curroot = root[cur];
        if (a[i] == 1)
            ins(curroot, t[i], 1);
        if (a[i] == 2)
            ins(curroot, t[i], -1);
        if (a[i] == 3)
            getsum(curroot, t[i]);
        root[cur] = curroot;
    }

    return 0;
}