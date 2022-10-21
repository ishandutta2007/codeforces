#include<bits/stdc++.h>
#define ls(x) x * 2 + 1
#define rs(x) x * 2 + 2

using namespace std;

const int N = (int)3e5 + 50;
int INF = (int)1e9 + 50;

int n,r;

struct node {
    int mx, add;

    void add_val(int x) {
        mx += x;
        add += x;
    }

    void merge(node &ls, node &rs) {
        mx = max(ls.mx, rs.mx);
    }
};

struct Tree {
    node dat[4 * N];

    void push_down(int x, int l, int r) {
        if(dat[x].add) {
            if(l < r) {
                dat[ls(x)].add_val(dat[x].add);
                dat[rs(x)].add_val(dat[x].add);
            }
            dat[x].add = 0;
        }
    }

    int query(int a, int b, int x = 0, int l = 0, int r = n-1) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return 0;

        push_down(x, l, r);

        if(l >= a && r <= b) return dat[x].mx;

        return max(query(a, b, ls(x), l, mid), query(a, b, rs(x), mid+1, r));
    }

    void update(int a, int b, int x, int l, int r, int delta) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return ;

        push_down(x, l, r);

        if(l >= a && r <= b) {
            dat[x].add_val(delta);
            return ;
        }

        update(a, b, ls(x), l, mid, delta);
        update(a, b, rs(x), mid+1, r, delta);

        dat[x].merge(dat[ls(x)], dat[rs(x)]);
    }

    void update(int a, int b, int delta) {
        update(a, b, 0, 0, n - 1, delta);
    }


} tree;

struct Pt {
    int x, y, e;
} pt[2 * N];

int ys[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> r;
    r *= 2;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        pt[i].x = x + y;
        pt[i].y = x - y;
        pt[i].e = 0;
        ys[i] = pt[i].y;
    }
    sort(ys, ys + n);

    for(int i = 0; i < n; i++) {
        pt[i+n].x = pt[i].x + r + 1;
        pt[i+n].y = pt[i].y;
        pt[i+n].e = 1;
    }
    sort(pt, pt + 2 * n, [](const Pt &p1, const Pt &p2) {
        return p1.x < p2.x;
    });
    int ir = 0;
    int res = 0;
    for(int i = 0; i < 2 * n; i = ir) {
//        cout << i << endl;
        while(ir < 2 * n && pt[i].x == pt[ir].x) {
            int ri = (int)(upper_bound(ys, ys + n, pt[ir].y) - ys) - 1;
            int li = (int)(lower_bound(ys, ys + n, pt[ir].y - r) -  ys);
            tree.update(li, ri, pt[ir].e ? -1 : 1);
//            cout << li << " " << ri << " " << pt[ir].e << endl;
            ir++;
        }
        res = max(res, tree.query(0, n - 1, 0, 0, n - 1));
    }
    cout << res << endl;




}