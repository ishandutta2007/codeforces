#include <cstdio>
#include <iostream>
using namespace std;
const int N = 3002;

int n, k, a[N], cnt, cntpre[N], cntsuf[N];
long long sum, dpre[N], dsuf[N];

int main(){
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        sum += a[i];
        cnt += (a[i] == 0);
    }
    if(sum < -1ll * cnt * k || sum > 1ll * cnt * k){
        puts("-1");
        return 0;
    }
    sum = -sum;
    for (int i = 1; i <= n; i++){
        dpre[i] = dpre[i - 1] + a[i];
        cntpre[i] = cntpre[i - 1] + (a[i] == 0);
    }
    for (int i = n - 1; i; i--){
        dsuf[i] = dsuf[i + 1] + a[i + 1];
        cntsuf[i] = cntsuf[i + 1] + (a[i + 1] == 0);
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j <= n; j++){
            long long x = min(sum + 1ll * (cntpre[i] + cntsuf[j]) * k, 1ll * (cnt - cntpre[i] - cntsuf[j]) * k);
            long long y = max(sum - 1ll * (cntpre[i] + cntsuf[j]) * k, -1ll * (cnt - cntpre[i] - cntsuf[j]) * k);
            ans = max(ans, max(x - sum - dpre[i] - dsuf[j], -(y - sum - dpre[i] - dsuf[j])));
        }
    printf("%lld", ans + 1);
    return 0;
}