#include <cstdio>
using namespace std;
const int N = 5e5 + 1, p = 1e9 + 7;

int fpow(int base, int t = p - 2){
    int ret = 1;
    while(t){
        if(t & 1)
            ret = 1ll * ret * base % p;
        base = 1ll * base * base % p;
        t >>= 1;
    }
    return ret;
}

int n, a[N], fac[N] = {1}, inv[N];

int C(int n, int m){
    return 1ll * fac[n] * inv[m] % p * inv[n - m] % p;
}

int main(){
    scanf("%d", &n);
    n++;
    for (int i = 1; i < N; i++)
        fac[i] = 1ll * fac[i - 1] * i % p;
    inv[N - 1] = fpow(fac[N - 1]);
    for (int i = N - 1; i > 0; i--)
        inv[i - 1] = 1ll * inv[i] * i % p;
    int ans = 0;
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        if(a[i] == 0)
            break;
        ans = (ans + C(i + a[i], i + 1)) % p;
    }
    printf("%d", ans);
    return 0;
}