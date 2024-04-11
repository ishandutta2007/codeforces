#include <iostream>
using namespace std;
typedef long long LL;
const LL N = 500000+10;
const LL INF = 1e16;
#define lson l, mid,rt<<1
#define rson mid+1, r, rt<<1|1

struct Func {
    LL m, r;
    Func(){m = -INF, r = INF;}
    Func(LL m_, LL r_) {
        m = m_, r = r_;
    }
    LL get(LL x) {
        return max(max(-2*x, m), 2*x - r);
    }
    Func operator + (const Func &o) {
        return Func(max(m,o.m), min(r, o.r));
    }
} nod[N];

LL n, q, a[N], b[N]; 
LL sum = 0;
void push_up(LL rt) {
    nod[rt] = nod[rt<<1] + nod[rt<<1|1];
}
void update(LL l, LL r, LL rt, LL pos, Func f) {
    if (l == r) {
        nod[rt] = f;
        return;
    }
    LL mid = (l + r) >> 1;
    if (mid >= pos) 
        update(lson, pos, f);
    else
        update(rson, pos, f);
    push_up(rt);
}
Func query(LL l, LL r, LL rt, LL L, LL R) {
    if (L <= l && r <= R) {
        return nod[rt];
    }
    LL mid = (l + r) >> 1;
    Func ans(-INF, INF);
    if (mid >= L)
        ans = ans + query(lson, L, R);
    if (mid  < R)
        ans = ans + query(rson, L, R);
    return ans;
}
Func generator(LL p, LL q) {
    p = -p, q = -q;
    //printf("p %lld q %lld\n", p, q);
    LL m, r;
    if (p >= 0 && q >= 0) m = - 2 * min(p, q), r = 2 * (p + q);
    if (p >= 0 && q <= 0) m = 0, r = 2 * p;
    if (p <= 0 && q >= 0) m = 0, r = 2 * q;
    if (p <= 0 && q <= 0) m = 0, r = 0;  
    //printf("m = %lld r = %lld\n", m, r);
    return Func(m, r);
}
int main() {
    scanf("%lld", &n);
    for (LL i = 1; i <= n; i ++) {
        scanf("%lld", &a[i]);
    }
    for (LL i = 1; i < n; i ++) {
        b[i] = a[i] - a[i+1];
        sum += abs(b[i]);
    }
    for (LL i = 2; i < n; i ++) {
        update(1, n, 1, i, generator(-b[i-1], b[i]));
    }
    scanf("%lld", &q);
    while (q --) {
        LL op, l, r, x;
        scanf("%lld %lld %lld %lld", &op, &l, &r, &x);
        
        if (op == 2) {
            if (l > 1) {
                sum = sum - abs(b[l-1]) + abs(b[l-1] - x);
                b[l-1] = b[l-1] - x;
                update(1,n,1,l,generator(-b[l-1], b[l]));
                if (l > 2) update(1,n,1,l-1,generator(-b[l-2],b[l-1]));
            }
            if (r < n) {
                sum = sum - abs(b[r]) + abs(b[r] + x);
                b[r] = b[r] + x;
                update(1,n,1,r,generator(-b[r-1], b[r]));
                if (r < n-1) update(1,n,1,r+1,generator(-b[r], b[r+1]));
            }
        }

        if (op == 1) {
            LL ans = -INF;
            if (l == 1) {
                ans = max(ans, sum - abs(b[1]) + abs(b[1] + x)); l ++;
            }
            if (r == n) {
                ans = max(ans, sum - abs(b[n-1]) + abs(b[n-1] - x)), r --;
            }
            if (l <= r) {
                ans = max(ans, sum + query(1,n,1,l,r).get(x));
            }
            printf("%lld\n", ans);
        }
    }
}
/*
5
1 1 1 1 1
5
1 2 4 1
2 2 3 1
2 4 4 2
2 3 4 1
1 3 3 2

1 2 3 4 1
*/