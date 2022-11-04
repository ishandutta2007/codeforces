#include <bits/stdc++.h>
 
using namespace std;
 
const int sz = 1e7 + 10, maxn = 3e5 + 10;
int dat[sz], ls[sz], rs[sz], tot;
void insert(int &p, int pre, int lp, int rp, int x, int v) {
    if(!p) p = ++tot;
    if(lp == rp) { dat[p] = dat[pre] + v; return ; }
    int mid = (lp + rp) >> 1;
    if(x <= mid) rs[p] = rs[pre], insert(ls[p], ls[pre], lp, mid, x, v);
    else ls[p] = ls[pre], insert(rs[p], rs[pre], mid+1, rp, x, v);
    dat[p] = dat[ls[p]] + dat[rs[p]];
}
 
int qry(int pl, int pr, int lp, int rp) {
    if(lp == rp) return dat[pr] - dat[pl];
    int mid = (lp + rp) >> 1;
    if(dat[ls[pr]] - dat[ls[pl]] < dat[rs[pr]] - dat[rs[pl]]) return qry(rs[pl], rs[pr], mid + 1, rp);
    return qry(ls[pl], ls[pr], lp, mid);
}
 
int a[maxn], rt[maxn];
 
int main() {
    int n, q; scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; ++i) scanf("%d", a + i), insert(rt[i], rt[i-1], 1, n, a[i], 1);
    for(int qr = 1; qr <= q; ++qr) {
        int l, r; scanf("%d %d", &l, &r);
        int su = qry(rt[l-1], rt[r], 1, n);
        printf("%d\n", max(su-((r-l+1)-su+1)+1,1));
    }
    return 0;
}