#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;

const int N = (int)3e5 + 50, M = (int)1e6 + 50;
typedef pair<int, int> P;

//Need to initialize before every test case!
int ncnt = 1;

struct node{
    int ls, rs, sum;
} ns[21 * N + 4 * M];

int newnode(int val){
    ns[ncnt].ls = ns[ncnt].rs = 0;
    ns[ncnt].sum = val;
    return ncnt++;
}

int newnode(int ls, int rs){
    ns[ncnt].ls = ls;
    ns[ncnt].rs = rs;
    ns[ncnt].sum = (ls ? ns[ls].sum : 0) + (rs ? ns[rs].sum : 0);
    return ncnt++;
}

int n, q;
int x[N], zeros[N];
int vs[M];
vector<int> seg[M];

int build(int a[], int tl = 0, int tr = M-1){
    if(tl == tr) return newnode(a[tl]);
    int mid = (tl + tr) / 2;
    return newnode(build(a, tl, mid), build(a, mid + 1, tr));
}

int get_sum(int v, int l, int r, int tl = 0, int tr = M-1){
    if(tr < l || tl > r) return 0;
    if(l <= tl && tr <= r) return ns[v].sum;
    int tm = (tl + tr) / 2;

    return get_sum(ns[v].ls, l, r, tl, tm)
           + get_sum(ns[v].rs, l, r, tm + 1, tr);
}

int update(int v, int pos, int tl = 0, int tr = M-1){
    if(tl == tr) return newnode(ns[v].sum + 1);
    int tm = (tl + tr) / 2;
    if(pos <= tm) return newnode(update(ns[v].ls, pos, tl, tm), ns[v].rs);
    else return newnode(ns[v].ls, update(ns[v].rs, pos, tm+1, tr));
}

int get_seg(int l, int r) {
    if(l > r) return 0;
    return get_sum(vs[r], l, r) - get_sum(vs[l-1], l, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        int l, r; cin >> l >> r; seg[r].push_back(l);
    }
    vs[0] = build(zeros);
    for(int i = 1; i < M; i++) {
        vs[i] = vs[i-1];
        for(int x : seg[i]) vs[i] = update(vs[i], x);
    }
    while(q--) {
        int k, cur, la = 0;
        int res = n;
        cin >> k;
        while(k--) {
            cin >> cur;
            res -= get_seg(la + 1, cur - 1);
            la = cur;
        }
        res -= get_seg(la + 1, M - 1);
        cout << res << "\n";
    }
}