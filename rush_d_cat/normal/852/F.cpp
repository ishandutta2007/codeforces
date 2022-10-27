#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
#define max(a, b) (a > b ? a : b)
#define N 1000000 + 200
LL n, m, a, q;
LL ans[N], inv[N];

LL C[N], mod = 1;

LL quick_mod(LL a,LL b,LL m)  
{  
    LL ans = 1;  
    a %= m;  
    while(b)  
    {  
        if(b & 1)  
        {  
            ans = ans * a % m;  
            b--;  
        }  
        b >>= 1;  
        a = a * a % m;  
    }  
    return ans;  
}  
  

void init()
{
    inv[1] = 1, C[0] = 1;
    for (int i = 2; i < mod; ++i)
    {
        inv[i] = ( (mod / i) * inv[mod % i] ) % mod;
        inv[i] = (-inv[i] + mod) % mod;
    }

    for (int i = 1; i <= m; i ++)
    {
        C[i] = C[i-1] * (m + 1 - i) % mod * inv[i] % mod;
    }
}

int main()
{
    cin >> n >> m >> a >> q;

    LL temp = a;

    while(temp != 1)
    {
        temp = temp * a % q;
        mod ++;
    }

    init();

    for (LL i = n; i >= max(n - m + 1, 1); i --)
    {
        ans[i] = ( ans[i + 1] + C[m - (n - i)] ) % mod;
    }

    for (LL i = max(n - m, 0); i >= 1; i --)
    {
        if (i == n - m)
            ans[i] = ( ans[i + 1] + 1 ) % mod;
        else 
            ans[i] = ans[i + 1];
    }

    for (LL i = 1; i <= n; i ++)
    {
        printf("%lld ", quick_mod(a, ans[i], q));
    }

}