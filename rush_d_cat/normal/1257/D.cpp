#include <iostream>
using namespace std;
const int N = 200000 + 10;

int T, n, m;
int a[N];
int p[N], s[N];
int suf[N];
int mn[N << 2];
void build(int l, int r, int rt) {
    if (l==r) {
        mn[rt] = a[l]; return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, rt<<1);
    build(mid+1, r, rt<<1|1);
    mn[rt] = max(mn[rt<<1], mn[rt<<1|1]);
}
int query(int l, int r, int rt, int L, int R) {
    if (L <= l && r <= R) return mn[rt];
    int mid = (l + r) >> 1;
    int ans = 0;
    if (L <= mid) ans = max(query(l, mid, rt<<1, L, R), ans);
    if (R  > mid) ans = max(query(mid+1, r, rt<<1|1, L, R), ans);
    return ans;
}
int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &a[i]);
        }
        build(1, n, 1);
        scanf("%d", &m);
        for (int i = 0; i <= n + 1; i ++) suf[i] = 0;
        for (int i = 1; i <= m; i ++) {
            scanf("%d%d", &p[i], &s[i]);
            suf[ s[i] ] = max(suf[ s[i] ], p[i]);
        }
        for (int i = n; i >= 1; i --) {
            suf[i] = max(suf[i], suf[i + 1]);
        }
        int now = 1, ans = 0;
        while (now <= n) {
            int lef = now, rig = n + 1;
            if (suf[1] < a[now]) {
                ans = -1; break;
            }
            //printf("now = %d\n", now);
            while (rig - lef > 1) {
                int mid = (lef + rig) >> 1;
                //printf("mid = %d, %d, %d\n", mid, query(1,n,1,now,mid), suf[mid-now+1]);
                if (query(1, n, 1, now, mid) <= suf[mid - now + 1]) lef = mid;
                else rig = mid;
            }
            //printf("now = %d, lef = %d\n", now, lef);
            ans ++; now = lef + 1;
        }
        printf("%d\n", ans);
    }
}