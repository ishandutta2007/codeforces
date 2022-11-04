#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 2e5 + 1;

int t, n, k, a[N];
long long b[N];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &k);
        long long ans = -1ll * k * (k - 1) / 2;
        for (int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            ans += a[i];
            b[i] = 1ll * (n - i) - a[i];
        }
        sort(b + 1, b + 1 + n);
        for (int i = 1; i <= k; i++)
            ans += b[i];
        printf("%lld\n", ans);
    }
    return 0;
}