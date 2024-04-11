#include <iostream>
#include <algorithm>
using namespace std;
const int N = 200000 + 10;
int k1, k2, k3;
int a[N], b[N], c[N];

int preb[N], prec[N];
int mn[N<<2];
void build(int l, int r, int rt) {
    if (l == r) {
        mn[rt] = prec[l] - preb[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, rt<<1);
    build(mid+1, r, rt<<1|1);
    mn[rt] = min(mn[rt<<1], mn[rt<<1|1]); 
}
int query(int l, int r, int rt, int L, int R) {
    if (L <= l && r <= R) return mn[rt];
    int mid = (l + r) >> 1;
    int ans = 1e9 + 7;
    if (L <= mid) ans = min(query(l, mid, rt<<1, L, R), ans);
    if (R  > mid) ans = min(query(mid+1, r, rt<<1|1, L, R), ans);
    return ans;
}
int main() {
    scanf("%d%d%d", &k1, &k2, &k3);
    int n = k1 + k2 + k3;
    for (int i = 1; i <= k1; i ++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= k2; i ++) {
        scanf("%d", &b[i]); preb[b[i]] ++;
    }
    for (int i = 1; i <= k3; i ++) {
        scanf("%d", &c[i]); prec[c[i]] ++;
    } 
    for (int i = 1; i <= n; i ++) {
        preb[i] += preb[i-1];
        prec[i] += prec[i-1];
    }
    build(0, n, 1);
    sort(a + 1, a + 1 + k1);
    sort(b + 1, b + 1 + k2);
    sort(c + 1, c + 1 + k3);

    int ans = 1e9 + 7;
    for (int x=0,i=1,j=1,k=1; x <= n; x ++) {
        while (i <= k1 && a[i] <= x) i ++;
        while (j <= k2 && b[j] <= x) j ++;
        while (k <= k3 && c[k] <= x) k ++;
        i --;
        int cost = (x - i) + (k1 - i);
        //printf("x = %d, cost = %d, ", x, cost);
        if (j <= k2 && k <= k3) {
            int R = b[k2], L = c[k];
            //printf("# [%d, %d]\n", L, R);
            if (L <= R) {
                //printf("[%d, %d] %d\n", L-1, R, query(0,n,1,L-1,R));
                cost += preb[R] - prec[L-1] + query(0,n,1,L-1,R);
            }
        }
        //printf("%d\n", cost);
        ans = min(ans, cost);
    }
    printf("%d\n", ans);

}

/*
prec[x] - prec[L-1] + preb[r] - preb[x]
4 3 4
1 2 3 4
5 6 7
8 9 10 11

4 3 4
2 7 4 11
5 6 3 
1 8 9 10
*/