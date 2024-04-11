#include <cstdio>
#include <iostream>
using namespace std;
const int N = 2e5 + 1;

int t, n, k;
long long a[N];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++){
            scanf("%lld", &a[i]);
            a[i] += a[i - 1];
        }
        if(n == 1){
            printf("%lld\n", a[1] + k - 1);
            continue;
        }
        if(k <= n){
            long long ans = 0;
            for (int i = 0; i + k <= n; i++)
                ans = max(ans, a[i + k] - a[i]);
            printf("%lld\n", ans + (k - 1ll) * k / 2);
            continue;
        }
        long long ans = a[n] + 1ll * (k - 1) * n - 1ll * n * (n - 1) / 2;
        printf("%lld\n", ans);
    }
    return 0;
}