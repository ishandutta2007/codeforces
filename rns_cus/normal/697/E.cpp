#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

long long a[1000001];

int pw(int x, int y) {
    if(!y) return 1;
    int z = pw(x, y/ 2);
    z = 1ll * z * z % mod;
    if(y % 2) return 1ll * z * x % mod;
    return z;
}

int main() {
    ///freopen("E.in", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) scanf("%I64d", &a[i]);
    bool bf = 1;
    for(int i = 0; i < n; i ++) if(a[i] % 2 == 0) bf = 0;
    int m = 1;
    for(int i = 0; i < n; i ++) m = 1ll * m * (a[i] % (mod - 1)) % (mod - 1);
    m = (m + mod - 2) % (mod - 1);
    if(bf) {
        int res = 1ll * (pw(2, m) - 1) * pw(3, mod - 2) % mod;
        printf("%d/%d", res, pw(2, m));
        return 0;
    }
    int res = 1ll * (pw(2, m + 1) - 1) * pw(3, mod - 2) % mod;
    res -= 2ll * (pw(2, m - 1) - 1) * pw(3, mod - 2) % mod;
    if(res < 0) res += mod;
    printf("%d/%d", res, pw(2, m));
}