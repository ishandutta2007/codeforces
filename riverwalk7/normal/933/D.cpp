#include <iostream>
#include <fstream>
#include <cmath>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
ll M, K, ans;
ll aa;
ll bb[7];
ll ii[10];
ll c[10][10];
ll cc[4];
ll inv(ll x)
{
    ll g[30]; ll cur = 1;
    g[0] = x;
    for(int i=1; i<30; i++)
    {
        g[i] = g[i-1]*g[i-1]%MOD;
    }
    for(int i=0; i<30; i++)
    {
        if((1<<i)&(MOD-2))
        {
            cur = cur*g[i]%MOD;
        }
    }
    return cur;
}
ll sum(ll a, ll b) //1^b+2^b+...+a^b
{
    ll cur = 0; ll cur2 = 1;
    for(int i=b; i>=0; i--)
    {
        cur2 = cur2*a%MOD;
        cur += ii[b+1]*c[b+1][i]%MOD*bb[i]%MOD*cur2;
        cur %= MOD;
    }
    return cur;
}
int main()
{
    bb[0] = 1; bb[1] = inv(2); bb[2] = inv(6); bb[4] = inv(MOD-30); bb[6] = inv(42);
    for(int i=0; i<10; i++)
    {
        c[i][0] = 1;
        for(int j=1; j<=i; j++)
        {
            c[i][j] = c[i-1][j-1]+c[i-1][j];
        }
        if(i>=1)
        ii[i] = inv(i);
    }
    cin>>M;
    cc[1] = (M+2)%MOD;
    cc[2] = M%MOD*((M-1)%MOD)%MOD*ii[2]%MOD;
    cc[3] = M%MOD*((M+1)%MOD)%MOD*((M+2)%MOD)%MOD*ii[6]%MOD;
    for(ll i=1; i<=sqrt(M); i++)
    {
        K = i*i%MOD;
        aa = sqrt(M-i*i);
        ans += (cc[3]+(MOD-cc[1])*K%MOD*(MOD+K-1)%MOD*ii[2]%MOD+(K+1)%MOD*K%MOD*(K+MOD-1)%MOD*ii[3])%MOD;
        ans += (2*ii[3]%MOD*((K*K%MOD*K%MOD*aa%MOD+3*K*K%MOD*sum(aa, 2)%MOD+3*K*sum(aa,4)%MOD+sum(aa,6)%MOD+((MOD-K)%MOD)%MOD*aa+(MOD-sum(aa,2))%MOD)%MOD))%MOD;
        ans += (2*aa*cc[3]%MOD);
        ans += (MOD-cc[1])*(aa*K%MOD*K%MOD+(2*sum(aa,2)-aa+MOD)*K%MOD+sum(aa,4)+(MOD-sum(aa,2)))%MOD;
        ans %= MOD;
    }
    ans *= 2;
    int i = 0;
    K = i*i%MOD;
    aa = sqrt(M-i*i);
    ans += (cc[3]+(MOD-cc[1])*K%MOD*(MOD+K-1)%MOD*ii[2]%MOD+(K+1)%MOD*K%MOD*(K+MOD-1)%MOD*ii[3])%MOD;
    ans += (2*ii[3]%MOD*((K*K%MOD*K%MOD*aa%MOD+3*K*K%MOD*sum(aa, 2)%MOD+3*K*sum(aa,4)%MOD+sum(aa,6)%MOD+((MOD-K)%MOD)%MOD*aa+(MOD-sum(aa,2))%MOD)%MOD))%MOD;
    ans += (2*aa*cc[3]%MOD);
    ans += (MOD-cc[1])*(aa*K%MOD*K%MOD+(2*sum(aa,2)-aa+MOD)*K%MOD+sum(aa,4)+(MOD-sum(aa,2)))%MOD;
    ans %= MOD;
    cout<<ans<<endl;
}