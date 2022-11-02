//40_C
#include <bits/stdc++.h>
using namespace std;

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define abs(a) ((a) > 0 ? (a) : -(a))

int n, m, x, y;

int main(){
    //freopen("c.in", "r", stdin);
    for(int runs = 0; runs < 1; runs ++){
        scanf("%d %d %d %d", &n, &x, &m, &y);
        y -= x;

        long long ans = 0;
        for(int i = 1; i <= m; i ++){
            if(y - i && y - i <= n && y - i >= -n) ans ++;
            if(y + i && y + i <= n && y + i >= -n) ans ++;
            ans += 2 * max(0, min(n + 1, y + i) - abs(y - i) - 1);
            ans += 2 * max(0, min(n + 1, i - y) - abs(i + y) - 1);
        }
        if(ans) ans += 2;
        else ans ++;

        ans += max(0, min(m + 1, -n - y) - 1);
        ans += max(0, min(m + 1, y - n) - 1);
        ans += max(0, m - max(n - y, n + y));

        ans += max(0, min(n + 1, y - m) - 1);
        ans += max(0, min(n + 1, -y - m) - 1);
        ans += max(0, n - max(m - y, m + y));

        printf("%I64d\n", ans);
    }
    ///return 9;
}