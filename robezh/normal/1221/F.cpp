#include <bits/stdc++.h>
using namespace std;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

typedef long long ll;
typedef pair<int, int> P;
const int N = (int)5e5 + 50;

struct point {
    int x, y, c;
} p[N];

int n;
int xlen, ylen;
int xs[N], ys[N];
vector<int> eve[N];
ll ini_y[N];

struct node {
    ll sum, mxsum;
    int len, mxlen;

    void init(ll _sum) {
        sum = mxsum = _sum;
        len = mxlen = 1;
    }

    void merge(node &LHS, node &RHS) {
        sum = LHS.sum + RHS.sum;
        len = LHS.len + RHS.len;
        if(LHS.sum + RHS.mxsum > LHS.mxsum) {
            mxsum = LHS.sum + RHS.mxsum;
            mxlen = LHS.len + RHS.mxlen;
        }
        else {
            mxsum = LHS.mxsum;
            mxlen = LHS.mxlen;
        }
    }
};

struct Tree {
    node dat[N * 4];

    void init_dat(int l, int r, int x){
        if(l == r){
            dat[x].init(ini_y[l]);
            return ;
        }

        int mid = (l + r) / 2;
        init_dat(l, mid, lson(x));
        init_dat(mid+1, r, rson(x));
        dat[x].merge(dat[lson(x)], dat[rson(x)]);
    }

    void update(int pos, int x, int l, int r, int delta){
        int mid = (l + r) / 2;
        if(l == r) {
            dat[x].init(dat[x].sum + delta);
            return ;
        }
        if(pos <= mid) update(pos, lson(x), l, mid, delta);
        else update(pos, rson(x), mid+1, r, delta);
        dat[x].merge(dat[lson(x)], dat[rson(x)]);
    }

    node query(int a, int b, int x, int l, int r){
        if(r < a || b < l) return {0, 0, 0, 0};

        int mid = (l + r) / 2;
        if(a <= l && r <= b) return dat[x];

        node res;
        node LHS = query(a, b, lson(x), l, mid);
        node RHS = query(a, b, rson(x), mid+1, r);
        if(LHS.len == 0) return RHS;
        res.merge(LHS, RHS);
        return res;
    }
} tree;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y >> p[i].c;
        if(p[i].x >= p[i].y) swap(p[i].x, p[i].y);
        xs[i] = p[i].x;
        ys[i] = p[i].y;
    }
    sort(xs, xs + n);
    xlen = (int)(unique(xs, xs + n) - xs);
    sort(ys, ys + n);
    ylen = (int)(unique(ys, ys + n) - ys);
    for(int i = 0; i < n; i++) {
        p[i].x = (int)(lower_bound(xs, xs + xlen, p[i].x) - xs);
        p[i].y = (int)(lower_bound(ys, ys + ylen, p[i].y) - ys);
        eve[p[i].x].push_back(i);
        ini_y[p[i].y] += p[i].c;
    }
    ini_y[0] -= ys[0];
    for(int i = 1; i < ylen; i++) {
        ini_y[i] -= (ys[i] - ys[i-1]);
    }
    tree.init_dat(0, ylen - 1, 0);
    ll res = 0, lx = (int)2e9, ry = (int)2e9;
    for(int i = 0; i < xlen; i++) {
        int sty = (int)(lower_bound(ys, ys + ylen, xs[i]) - ys);
        node cur = tree.query(sty, ylen - 1, 0, 0, ylen - 1);
        ll cur_res = cur.mxsum - (sty > 0 ? ys[sty - 1] : 0) + xs[i];
        if(cur_res > res) {
            res = cur_res;
            lx = xs[i];
            ry = ys[sty + cur.mxlen - 1];
        }
        for(int j : eve[i]) {
            tree.update(p[j].y, 0, 0, ylen - 1, -p[j].c);
        }
    }
    cout << res << "\n" << lx << " " << lx << " " << ry << " " << ry << endl;
}