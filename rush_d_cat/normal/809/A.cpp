#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const LL inv = 500000004;

int n;LL a[300000+10];
LL p[3000000+10], s[3000000+10];
int main()
{
    scanf("%d", &n);
    s[0] = p[0] = 1;
    for (int i = 1; i <= n; i ++)
    {
        scanf("%lld", &a[i]);
        p[i] = p[i-1] * 2 % MOD; 
        s[i] = (s[i-1] + p[i]) % MOD;

    }
    sort(a + 1, a + 1 + n);
    LL ans = 0, sum = 0;
    
    LL k = 1;
    for (int i = 2; i <= n; i ++)
    {
        sum += k * a[i];
        sum %= MOD;
        k = k * 2 % MOD;
    }
    
    for (int i = 1; i < n; i ++)
    {
        LL temp = - s[n-i-1] * a[i] % MOD;
        (ans += (sum + temp)) %= MOD;
        sum = (sum - a[i+1]) * inv % MOD;
    }

    printf("%lld\n", (ans + MOD) % MOD);

}