#include <cstdio>
using namespace std;
const int N = 61, p = 998244353;

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

int t, n, fac[N] = {1};

int C(int n, int m){
    return 1ll * fac[n] * fpow(fac[m]) % p * fpow(fac[n - m]) % p;
}

int main(){
    for (int i = 1; i < N; i++)
        fac[i] = 1ll * i * fac[i - 1] % p;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int ans = 0;
        for (int i = 1; i <= n; i += 4){
            ans = (ans + C(n - i, (n - i) / 2)) % p;
            if(i + 3 <= n)
                ans = (ans + C(n - i - 3, (n - i - 3) / 2 - 1)) % p;
        }
        printf("%d %d %d\n", ans, ((C(n, n / 2) - ans - 1) % p + p) % p, 1);
    }
    return 0;
}