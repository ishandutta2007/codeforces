#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;

const int N = (int)1e5 + 50;
typedef pair<int, int> P;

//Need to initialize before every test case!
int ncnt = 1;

struct node{
    int ls, rs;
    int pref, suf, mx, len;
} ns[N * 30];

struct pac{
    int pref, suf, mx;
    int len;
};

int newnode(int ls = 0, int rs = 0, int one = 0){
    ns[ncnt].ls = ls;
    ns[ncnt].rs = rs;
    ns[ncnt].mx = ns[ncnt].pref = ns[ncnt].suf = one;
    ns[ncnt].len = (ls == 0 ? 1 : ns[ls].len + ns[rs].len);
    return ncnt++;
}


int newnode(int ls, int rs, int tl, int tr){
    ns[ncnt].ls = ls;
    ns[ncnt].rs = rs;
    ns[ncnt].mx = max(max(ns[ls].mx, ns[rs].mx), ns[ls].suf + ns[rs].pref);
    ns[ncnt].pref = ns[ls].pref + (ns[ls].pref == ns[ls].len ? ns[rs].pref : 0);
    ns[ncnt].suf = ns[rs].suf + (ns[rs].suf == ns[rs].len ? ns[ls].suf : 0);
    ns[ncnt].len = ns[ls].len + ns[rs].len;
    return ncnt++;
}

int n, q;
P num[N];
int x[N], zeros[N];
int vs[N];

int build(int a[], int tl = 0, int tr = n-1){
    if(tl == tr) return newnode();
    int mid = (tl + tr) / 2;
    return newnode(build(a, tl, mid), build(a, mid + 1, tr), 0);
}

pac get_sum(int v, int l, int r, int tl = 0, int tr = n-1){
    if(tr < l || tl > r) return {0, 0, 0, 0};
    if(l <= tl && tr <= r) return {ns[v].pref, ns[v].suf, ns[v].mx, tr - tl + 1};
    int tm = (tl + tr) / 2;

    pac LHS = get_sum(ns[v].ls, l, r, tl, tm);
    pac RHS = get_sum(ns[v].rs, l, r, tm + 1, tr);
    pac res;
    res.mx = max(max(LHS.mx, RHS.mx), LHS.suf + RHS.pref);
    res.pref = LHS.pref + (LHS.pref == LHS.len ? RHS.pref : 0);
    res.suf = RHS.suf + (RHS.suf == RHS.len ? LHS.suf : 0);
    res.len = LHS.len + RHS.len;
    return res;
}

//int query(int v, int l, int r, int tl = 0, int tr = n-1){
//    if(tr < l || tl > r) return 0;
//    if(l <= tl && tr <= r) return ns[v].mx;
//    int tm = (tl + tr) / 2;
//    int res = max(query(ns[v].ls, l, r, tl, tm), query(ns[v].rs, l, r, tm+1, tr));
//    res = max(res, min(ns[ns[v].ls].suf, tm - tl + 1) + min(ns[ns[v].rs].pref, tr - tm));
//    return res;
//}

int update(int v, int pos, int tl = 0, int tr = n-1){
//    cout << v << " " << pos << " " << tl << " " << tr << endl;

    if(tl == tr) return newnode(0, 0, 1);
    int tm = (tl + tr) / 2;
    if(pos <= tm) return newnode(update(ns[v].ls, pos, tl, tm), ns[v].rs, tl, tm);
    else return newnode(ns[v].ls, update(ns[v].rs, pos, tm+1, tr), tm + 1, tr);
}

int get_ans(int l, int r, int w){
    int lb = -1, rb = n - 1, mid;
    while(lb + 1 < rb){
        mid = (lb + rb) / 2;
        int mx = get_sum(vs[mid+1], l, r).mx;
        if(mx >= w) rb = mid;
        else lb = mid;
    }
    return rb;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &num[i].first);
        num[i].second = i;
        x[i] = num[i].first;
    }
    sort(num, num + n, greater<P>());
    vs[0] = build(zeros);
    for(int i = 0; i < n; i++){
        vs[i+1] = update(vs[i], num[i].second);
    }
    scanf("%d", &q);
    while(q--){
        int l, r, w;
        scanf("%d%d%d", &l, &r, &w); l--, r--;
        printf("%d\n", num[get_ans(l, r, w)].first);
    }


}