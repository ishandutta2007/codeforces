#include <iostream>
using namespace std;
const double EPS = 1e-6;
const int N = 100000+10;
#define lson l, mid, rt<<1
#define rson mid+1, r, rt<<1|1
double sum[N<<3], a[N], lazy1[N<<3], lazy2[N<<3];
int n, q, op, l1, r1, l2, r2;
void push_up(int rt) {
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void push_down(int rt, int l, int r) {
    if (lazy2[rt] < 1 - EPS) {
        lazy2[rt<<1] *= lazy2[rt];
        lazy2[rt<<1|1] *= lazy2[rt];
        lazy1[rt<<1] *= lazy2[rt];
        lazy1[rt<<1|1] *= lazy2[rt];
        sum[rt<<1] *= lazy2[rt];
        sum[rt<<1|1] *= lazy2[rt];
        lazy2[rt] = 1; 
    }
    if (lazy1[rt] > EPS) {
        lazy1[rt<<1] += lazy1[rt];
        lazy1[rt<<1|1] += lazy1[rt];
        sum[rt<<1] += lazy1[rt] * ((l+r)/2 - l + 1);
        sum[rt<<1|1] += lazy1[rt] * (r - (l+r)/2);
        lazy1[rt] = 0;
    }

}
void build(int l, int r, int rt) {
    lazy1[rt] = 0, lazy2[rt] = 1;
    if (l == r) {
        sum[rt] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(lson);
    build(rson);
    push_up(rt);
} 
void update1(int l, int r, int rt, int L, int R, double d) {
    if (L <= l && r <= R) {
        sum[rt] += d * (r - l + 1);
        lazy1[rt] += d;
        return;
    }
    push_down(rt, l, r);
    int mid = (l + r) >> 1;
    if (L <= mid) update1(lson, L, R, d);
    if (R  > mid) update1(rson, L, R, d);
    push_up(rt);
}
void update2(int l, int r, int rt, int L, int R, double p) {
    if (L <= l && r <= R) {
        sum[rt] *= p;
        lazy2[rt] *= p;
        lazy1[rt] *= p;
        return;
    }
    push_down(rt, l, r);
    int mid = (l + r) >> 1;
    if (L <= mid) update2(lson, L, R, p);
    if (R  > mid) update2(rson, L, R, p);
    push_up(rt);
}
double query(int l, int r, int rt, int L, int R) {
    push_down(rt, l, r);
    if (L <= l && r <= R) {
        return sum[rt];
    }
    int mid = (l + r) >> 1;
    double ans = 0;
    if (L <= mid) ans += query(lson, L, R);
    if (R  > mid) ans += query(rson, L, R);
    return ans;
}
int main() {
    scanf("%d %d", &n, &q);

    for (int i = 1; i <= n; i ++) 
        scanf("%lf", &a[i]);
    
    build(1, n, 1);

    while (q --) {
        scanf("%d %d %d", &op, &l1, &r1);
        if (op == 1) {
            scanf("%d %d", &l2, &r2);
            double s1 = query(1,n,1,l1,r1) / (r1-l1+1) / (r2-l2+1);
            double s2 = query(1,n,1,l2,r2) / (r2-l2+1) / (r1-l1+1);
            update2(1,n,1,l1,r1,1.0*(r1-l1)/(r1-l1+1));
            update2(1,n,1,l2,r2,1.0*(r2-l2)/(r2-l2+1));
            update1(1,n,1,l1,r1,s2);
            update1(1,n,1,l2,r2,s1);
        }
        if (op == 2) {
            printf("%.6f\n", query(1,n,1,l1,r1));
        }
    }
}