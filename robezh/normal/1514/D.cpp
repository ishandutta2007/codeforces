#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = (int)3e5 + 50;
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

int build(int a[], int tl = 0, int tr = n-1){
    if(tl == tr) return newnode(a[tl]);
    int mid = (tl + tr) / 2;
    return newnode(build(a, tl, mid), build(a, mid + 1, tr));
}

int get_sum(int v, int l, int r, int tl = 0, int tr = n-1){
    if(tr < l || tl > r) return 0;
    if(l <= tl && tr <= r) return ns[v].sum;
    int tm = (tl + tr) / 2;

    return get_sum(ns[v].ls, l, r, tl, tm)
           + get_sum(ns[v].rs, l, r, tm + 1, tr);
}

int update(int v, int pos, int tl = 0, int tr = n-1){
    if(tl == tr) return newnode(ns[v].sum + 1);
    int tm = (tl + tr) / 2;
    if(pos <= tm) return newnode(update(ns[v].ls, pos, tl, tm), ns[v].rs);
    else return newnode(ns[v].ls, update(ns[v].rs, pos, tm+1, tr));
}

int find(int rem, int v0, int v1, int tl, int tr) {
    if(tl == tr) return tl;
    int tm = (tl + tr) / 2;
    int sleft = ns[ns[v0].ls].sum - ns[ns[v1].ls].sum;
    if(sleft >= rem) return find(rem, ns[v0].ls, ns[v1].ls, tl, tm);
    else return find(rem - sleft, ns[v0].rs, ns[v1].rs, tm + 1, tr);
}

int c[N];
vector<int> ocu[N];

int count(int l, int r, int c) {
    return lower_bound(all(ocu[c]), r + 1) - lower_bound(all(ocu[c]), l);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;

    vs[0] = build(zeros, 0, n - 1);
    rep(i, 1, n + 1) {
        cin >> c[i]; c[i]--;
        ocu[c[i]].push_back(i);
        vs[i] = update(vs[i - 1], c[i], 0, n - 1);
    }
    while(q--) {
        int l, r; cin >> l >> r;
        int len = r - l + 1;
        int md = len / 2 + 1;
        int v = find(md, vs[r], vs[l - 1], 0, n - 1);
        int cnt_v = count(l, r, v);
        cout << max(1, cnt_v - (len - cnt_v)) << '\n';
    }


}