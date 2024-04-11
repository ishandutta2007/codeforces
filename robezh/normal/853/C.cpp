#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;

const int N = (int)2e5 + 50;
typedef pair<int, int> P;
typedef long long ll;

//Need to initialize before every test case!
int ncnt = 1;

struct node{
    int ls, rs, sum;
} ns[N * 30];

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
int num[N];
int x[N], zeros[N];
int vs[N];


struct Tree{
    int n;

    int build(int a[], int tl, int tr){
        if(tl == tr) return newnode(a[tl]);
        int mid = (tl + tr) / 2;
        return newnode(build(a, tl, mid), build(a, mid + 1, tr));
    }

    int get_sum(int v, int l, int r, int tl, int tr){
        if(tr < l || tl > r) return 0;
        if(l <= tl && tr <= r) return ns[v].sum;
        int tm = (tl + tr) / 2;

        return get_sum(ns[v].ls, l, r, tl, tm)
               + get_sum(ns[v].rs, l, r, tm + 1, tr);
    }

    int update(int v, int pos, int tl, int tr){
        if(tl == tr) return newnode(ns[v].sum + 1);
        int tm = (tl + tr) / 2;
        if(pos <= tm) return newnode(update(ns[v].ls, pos, tl, tm), ns[v].rs);
        else return newnode(ns[v].ls, update(ns[v].rs, pos, tm+1, tr));
    }

    int build(int a[]) {
        return build(a, 0, n-1);
    }

    int get_sum(int v, int l, int r) {
        return get_sum(v, l, r, 0, n-1);
    }

    int update(int v, int pos) {
        return update(v, pos, 0, n-1);
    }

} tree;

ll calc(int l, int d, int r, int u) {
    ll res = tree.get_sum(vs[r], d, u) - tree.get_sum(vs[l-1], d, u);
    return res * (res - 1) / 2;
}

ll get(int x) {
    return 1LL * x * (x - 1) / 2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    tree.n = n + 1;
    vs[0] = tree.build(zeros);
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
        vs[i] = tree.update(vs[i-1], x[i]);
    }
    while(q--) {
        int l, d, r, u;
        cin >> l >> d >> r >> u;
        ll res = 1LL * n * (n - 1) / 2 - get(l-1) - get(d-1) - get(n-u) - get(n-r)
                + calc(1, u + 1, l - 1, n) + calc(1, 1, l - 1, d - 1)
                + calc(r + 1, 1, n, d - 1) + calc(r + 1, u + 1, n, n);
        cout << res << "\n";
    }

}