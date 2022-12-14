#include <iostream>
using namespace std;
const int MOD = 1e9 + 1;
int n, q, x, lastans, temperature;

struct node {
    int add, vmin, vmax;
    node *lf, *rt;
    node(int l, int r) {
        add = 0;
        vmin = l, vmax = r;
        lf = rt = NULL;
    }
    void build(int val) {
        add += val;
        vmin += val;
        vmax += val;
    }
    void down(int l, int r) {
        int mid = (l+r) / 2;
        if (lf == NULL) lf = new node(l, mid);
        if (rt == NULL) rt = new node(mid+1, r);
        lf->build(add);
        rt->build(add);
        add = 0;
    }
} *root;

void update(int l, int r, node *u) {
    if (u->vmax < temperature) {
        u->build(1);
        return;
    }
    else if (u->vmin > temperature) {
        u->build(-1);
        return;
    }
    else if (u->vmin == u->vmax) return;
    if (u->vmin < temperature) ++u->vmin;
    if (u->vmax > temperature) --u->vmax;
    u->down(l, r);
    int mid = (l+r) / 2;

    update(l, mid, u->lf);
    update(mid+1, r, u->rt);
}

int query(int l, int r, node *u) {
    int mid = (l+r) / 2;
    if (x <= mid) {
        if (u->lf == NULL) return x + u->add;
        return query(l, mid, u->lf) + u->add;
    }
    else {
        if (u->rt == NULL) return x + u->add;
        return query(mid+1, r, u->rt) + u->add;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    root = new node(0, MOD - 1);
    cin >> n;
    for(int i=1; i<=n; ++i) {
        cin >> temperature;
        update(0, MOD - 1, root);
        cin >> q;
        while (q--) {
            cin >> x;
            (x += lastans) %= MOD;
            cout << (lastans = query(0, MOD - 1, root)) << '\n';
        }
    }
}