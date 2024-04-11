#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1200000+10;
#define lson l, mid, rt<<1
#define rson mid+1, r, rt<<1|1
typedef long long LL;

int n, m, t, x, y;
LL a[N], f[N], sum[N], mx[N];
void push_up(int rt) {
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
    mx[rt] = max(mx[rt<<1], mx[rt<<1|1]);
}
void build(int l, int r, int rt) {
    if (l == r) {
        mx[rt] = sum[rt] = a[l];
        return; 
    }
    int mid = (l + r) >> 1;
    build(lson); build(rson); push_up(rt);
}
void update(int l, int r, int rt, int L, int R) {
    if (L <= l && r <= R && mx[rt] <= 2) return;
    if(l == r) {
        sum[rt] = mx[rt] = f[sum[rt]];
        return;
    }
    int mid = (l + r) >> 1;
    if (L <= mid) update(lson, L, R);
    if (R  > mid) update(rson, L, R);
    push_up(rt);
}
LL query(int l, int r, int rt, int L, int R) {
    if (L <= l && r <= R) {
        return sum[rt];
    }
    int mid = (l + r) >> 1;
    LL ans = 0;
    if (L <= mid) ans += query(lson, L, R);
    if (R  > mid) ans += query(rson, L, R);
    return ans;
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++) scanf("%lld", &a[i]);
    for (int i = 1; i <= 1e6; i ++) for (int j = i; j <= 1e6; j += i) f[j] ++; 
    build(1, n, 1);
    for (int i = 1; i <= m; i ++) {
        scanf("%d %d %d", &t, &x ,&y);
        if (t == 1) {
            update(1,n,1,x,y);
        } else {
            printf("%lld\n", query(1,n,1,x,y));
        }
    }
}