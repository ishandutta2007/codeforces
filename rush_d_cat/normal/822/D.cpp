#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long LL;
const int NICO = 5000000+10;
const LL MOD = 1e9+7;
int small[NICO];
LL f[NICO];
LL t, l, r;

int n, prime[NICO], e;
bool not_prime[NICO];//is_prime0 

void solve()// 
{

    for(int i=2;i<NICO;i++)
    {
        if(!not_prime[i])
        {
            prime[++e] = i; 
            small[i] = i;
            if((LL)i * i>NICO) continue;//int 
            
            for(int j=(LL)i*i;j<NICO;j+=i) {
                not_prime[j] = 1;
                if(small[j] == 0) {
                    small[j] = i;
                }
            }
        }
    }
}


int main()
{
    solve();
    cin >> t >> l >> r;
    f[2] = 1, f[3] = 3;

    for(int i=4;i<=r;i++) {
        f[i] = f[i / small[i]] + (LL)i * (LL)(small[i] - 1) / 2;
        f[i] = (f[i] % MOD + MOD) % MOD;
    }

    LL ans = 0;
    LL temp = 1;
    for(int i=l;i<=r;i++) {
        ans += temp * f[i];
        ans = (ans % MOD + MOD) % MOD;
        temp *= t;
        temp %= MOD;
    }
    cout << ans << endl;
}