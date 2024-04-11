#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
#define mid ((l+r)>>1)
int n, q, x, a[1<<21];
LL f[102][2];

void solve(int l, int r, int dep) {
    if (dep == 0) return;

    solve(l,mid,dep-1); solve(mid+1,r,dep-1);
    
    for (int i = l; i <= mid; i ++) {
        LL tmp1 = lower_bound(a+mid+1, a+r+1, a[i]) - (a+mid) - 1;
        LL tmp2 = (r-mid) - (upper_bound(a+mid+1, a+r+1, a[i]) - (a+mid) - 1);
        f[dep][0] += tmp1;
        f[dep][1] += tmp2;
    }
    
    sort(a+l, a+r+1);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= (1<<n); i ++)
        scanf("%d", &a[i]);
    scanf("%d", &q);

    solve(1, 1<<n, n);
    


    while (q --) {
        scanf("%d", &x);
        for (int i = 0; i <= x; i ++)
            swap(f[i][0], f[i][1]);

        LL ans = 0;
        for (int i = 0; i <= n; i ++)
            ans += f[i][0];

        printf("%lld\n", ans);
    }
}