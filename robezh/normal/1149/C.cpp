#include <bits/stdc++.h>
using namespace std;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

typedef long long ll;
const int N = (int)2e5 + 50, INF = (int)1e9 + 50;

int n,q;
string str;

struct node {
    int d;
    int a, b2, ab2, cb2, ab2c;

    void merge(const node &ls, const node &rs) {
        d = ls.d + rs.d;
        a = max(ls.a, rs.a + ls.d);
        b2 = max(ls.b2, rs.b2 - 2 * ls.d);
        ab2 = max(max(ls.ab2, rs.ab2 - ls.d), ls.a + rs.b2 - 2 * ls.d);
        cb2 = max(max(ls.cb2, rs.cb2 - ls.d), ls.b2 + rs.a + ls.d);
        ab2c = max(max(ls.ab2c, rs.ab2c), max(ls.ab2 + rs.a + ls.d, ls.a + rs.cb2 - ls.d));
    }
};

struct Tree {
    node nd[N * 4];

    void init_dat(int l, int r, int x){
        if(l == r){
            nd[x].d = (str[l] == '(' ? 1 : -1);
            return ;
        }

        int mid = (l + r) / 2;
        init_dat(l, mid, lson(x));
        init_dat(mid+1, r, rson(x));
        nd[x].merge(nd[lson(x)], nd[rson(x)]);
    }

    void update(int pos, int x, int l, int r){
        int mid = (l + r) / 2;
        if(l == r) {
            nd[x].d = -nd[x].d;
            return ;
        }
        if(pos <= mid) update(pos, lson(x), l, mid);
        else update(pos, rson(x), mid+1, r);
        nd[x].merge(nd[lson(x)], nd[rson(x)]);
    }

    node query(int a, int b, int x, int l, int r){
        if(r < a || b < l) return {0, -INF, -INF, -INF, -INF, -INF};

        int mid = (l + r) / 2;
        if(a <= l && r <= b) return nd[x];

        node LHS = query(a, b, lson(x), l, mid);
        node RHS = query(a, b, rson(x), mid+1, r);
        node res;
        res.merge(LHS, RHS);
        return res;
    }
} tree;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    n = 2 * n - 2;
    cin >> str;
    tree.init_dat(0, n-1, 0);
    cout << tree.query(0, n-1, 0, 0, n-1).ab2c << endl;
    while(q--) {
        int l, r; cin >> l >> r; l--, r--;
        tree.update(l, 0, 0, n-1);
        tree.update(r, 0, 0, n-1);
        cout << tree.query(0, n-1, 0, 0, n-1).ab2c << "\n";
    }
}