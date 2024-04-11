#include <iostream>
using namespace std;
typedef long long LL;
const int NICO = 200000 + 10; 
const LL MOD = 1000000000 + 7;
int n, cnt[NICO];

LL mod_pow(LL p, LL k, LL mod)
{
    LL res = 1;
    while(k > 0)
    {
        if(k % 2 == 1) res = res * p % mod;
        p = p * p % mod;
        k /= 2;
    }
    return res % mod;
}

int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        int k; cin >> k;
        cnt[k] ++;    
    }
    LL M = 1, ans = 1;
    for(int i=1;i<NICO;i++)
    {
        M = M * (cnt[i] + 1) % (2*MOD-2);
    }
    for(int i=1;i<NICO;i++)
    {
        LL tmp = M * cnt[i] % (2*MOD-2) / 2;
        ans = ans * mod_pow(i, tmp, MOD) % MOD;
    }
    cout << ans << endl;
}