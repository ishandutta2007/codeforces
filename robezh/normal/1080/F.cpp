#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int N = (int)3e5 + 50, INF = (int)1e9 + 50;
//Need to initialize before every test case!
int ncnt = 1;

struct seg{
    int l, r, id;
};

struct node{
    int ls, rs, val;
} ns[N * 30];

int newnode(int val){
    ns[ncnt].ls = ns[ncnt].rs = 0;
    ns[ncnt].val = val;
    return ncnt++;
}

int newnode(int ls, int rs){
    ns[ncnt].ls = ls;
    ns[ncnt].rs = rs;
    ns[ncnt].val = max((ls ? ns[ls].val : 0), (rs ? ns[rs].val : 0));
    return ncnt++;
}

int n,m,k;
vector<P> sg[N];
vector<seg> segs;
int rb[N];
int num[N], zeros[N];
int vs[N];

int build(int a[], int tl = 0, int tr = k-1){
    if(tl == tr) return newnode(a[tl]);
    int mid = (tl + tr) / 2;
    return newnode(build(a, tl, mid), build(a, mid + 1, tr));
}

int get_max(int v, int l, int r, int tl = 0, int tr = k - 1){
    if(tr < l || tl > r) return 0;
    if(l <= tl && tr <= r) return ns[v].val;
    int tm = (tl + tr) / 2;

    return max(get_max(ns[v].ls, l, r, tl, tm), get_max(ns[v].rs, l, r, tm + 1, tr));
}

int update(int v, int pos, int val, int tl = 0, int tr = k-1){
    if(tl == tr) {
        return newnode(val);
    }
    int tm = (tl + tr) / 2;
    if(pos <= tm) return newnode(update(ns[v].ls, pos, val, tl, tm), ns[v].rs);
    else return newnode(ns[v].ls, update(ns[v].rs, pos, val, tm+1, tr));
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < k; i++) {
        int l, r, id;
        scanf("%d%d%d", &l, &r, &id); id--;
        num[i] = l;
        segs.push_back({l, r, id});
    }
    sort(num, num + k);

    for(seg &s : segs){
        int l = lower_bound(num, num + k, s.l) - num;
        sg[l].emplace_back(s.r, s.id);
    }

    fill(zeros, zeros + k, INF);
    fill(rb, rb + k, INF);
    vs[k] = build(zeros);

    for(int i = k - 1; i >= 0; i--) {
        int cur = vs[i+1];
        for(P &p : sg[i]) {
            if(p.first >= rb[p.second]) continue;

            cur = update(cur, p.second, p.first);
            rb[p.second] = p.first;

        }
        vs[i] = cur;
    }



    while(m--) {
        int a, b, x, y;
        scanf("%d%d%d%d", &a, &b, &x, &y);
        a--, b--;
        x = (int)(lower_bound(num, num + k, x) - num);
        int mx = get_max(vs[x], a, b);
        if(mx > y) printf("no\n");
        else printf("yes\n");
        fflush(stdout);
    }


}