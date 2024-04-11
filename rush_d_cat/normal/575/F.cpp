#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1e4 +7;
 
int a[N], l[N], r[N];
LL f[2][N];
 
int main(){
    int n, m = 0, x;
    scanf("%d%d", &n, &x); a[++m] = x;
    for (int i = 1; i <= n; i++){
        scanf("%d%d", &l[i], &r[i]);
        a[++m] = l[i]; a[++m] = r[i];
    }
    sort(a + 1, a + m + 1);
    //printf("%d\n", m);
    m = unique(a + 1, a + m + 1) - a - 1;
    for (int i = 1; i <= m; i++){
        if (a[i] == x) f[0][i] = 0;
        else f[0][i] =  1e18;
    }
    int now = 0;
    for (int i = 1; i <= n; i++){
        LL mi = 1e18;
        for (int j = 1; j <= m; j++){
            mi = min(mi, f[now][j] - a[j]);
            f[now ^ 1][j] = a[j] + mi;
        }
        mi = 1e18;
        for (int j = m; j >= 1; j--){
            mi = min(mi, f[now][j] + a[j]);
            f[now ^ 1][j] = min(f[now ^ 1][j], mi - a[j]);
        }
        for (int j = 1; j <= m; j++){
            if (a[j] < l[i]) f[now ^ 1][j] += l[i] - a[j];
            else if (a[j] > r[i]) f[now ^ 1][j] += a[j] - r[i];
        }
        now ^= 1;
    }
    LL ans = 1e18;
    for (int i = 1; i <= m; i++) ans = min(ans, f[now][i]);
    printf("%lld", ans);
    return 0;
}