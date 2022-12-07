#include <iostream>
#include <fstream>
#define MOD 1000000007
#define MAXN 150
using namespace std;
typedef long long ll;
ll N; int K; ll d;
bool flag;
ll choose[20000][100];
ll DP[MAXN];
ll inverse[MAXN];
ll inv(ll x)
{
    ll c = 1; ll g[30];
    for(int i=0; i<30; i++)
    {
        if(i==0)
        {
            g[i] = x;
        }
        else
        {
            g[i] = g[i-1]*g[i-1]%MOD;
        }
        if((1<<i)&(MOD-2))
        {
            c = c*g[i] % MOD;
        }
    }
    return c;
}
ll solve(ll a, ll b)
{
    a %= MOD;
    DP[b] = 1;
    for(int i=0; i<b; i++)
    {
        DP[i] = 0;
    }
    for(int i=0; i<K; i++)
    {
        for(int j=0; j<=b; j++)
        {
            DP[j] *= inverse[j+1];
            DP[j] %= MOD;
            for(int k=j+1; k<=b; k++)
            {
                DP[j] += (DP[k]*inverse[k+1]);
                DP[j] %= MOD;
            }
        }
    }
    ll cur = 1; ll total = 0;
    for(int j=0; j<=b; j++)
    {
        total += (cur*DP[j]%MOD);
        cur = cur * a % MOD;
    }
    return total;
}
int main()
{
    ll ans = 1;
    cin>>N>>K;
    for(ll i = 1; i < 100; i++)
    {
        inverse[i] = inv(i);
    }
    for(ll i=2; i<=40000000; i++)
    {
        d = 0;
        while(N%i==0)
        {
            N /= i;
            ++d;
        }
        if(d)
        {
            ans = ans*(solve(i, d)) % MOD;
        }
    }
    if(N)
    {
        ans = ans*solve(N, 1) % MOD;
    }
    cout<<ans<<endl;
}