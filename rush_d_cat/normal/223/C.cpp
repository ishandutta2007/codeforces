#include <iostream>
using namespace std;
typedef long long LL;
const LL MOD = 1e9+7;
LL cof[2002], n, k, a[2002], b[2002], ans[2002];

LL mpow(LL n, LL x) 
{
    if (x == 0) return 1;
    if (x & 1) 
    {
        return n * mpow(n, x - 1) % MOD;
    } else {
        LL ans = mpow(n, x / 2);
        return ans * ans % MOD;
    }
}

LL inv(LL x) 
{
    return mpow(x, MOD-2);
}

LL C(LL n, LL k) 
{
    cof[0] = 1;
    for (int i = 1; i <= k; i ++) 
    {
        cof[i] = cof[i-1] * (n-i+1) % MOD * inv(i) % MOD;// % MOD * inv(i+1) % MOD;
    }
    return cof[k];
}

int main()
{
    // cout <<C(7, 2) << endl;
    // cof[i] = c(k+i-1, i) 
    
    cin >> n >> k;
    for (int i = 0; i < n; i ++) 
    {
        ans[i] = C(k+i-1, i);
    }

    //printf("%d\n", cof[1]);

    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i ++)
    {
        for (int j = i; j < n; j ++) {
            b[j] = b[j] + a[i] * ans[j - i];
            b[j] %= MOD;
            //if (i == 0) printf("%d %d %d %d %d\n", j, b[j], a[i], j-i, cof[j-i]);
        }
        //or (int i = 0; i < n; i ++) printf("%lld ", b[i]);
    }

    for (int i = 0; i < n; i ++) {
        printf("%lld ", b[i]);
    }




}