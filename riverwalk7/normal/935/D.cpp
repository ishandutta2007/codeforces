#include <iostream>
#include <fstream>
#define MOD 1000000007
#define MAXN 100100
using namespace std;
typedef long long ll;
ll N, M;
ll a[MAXN], b[MAXN];
ll DP[MAXN], DP2[MAXN];
ll inv(ll x)
{
    ll xx[30]; ll cur = 1;
    xx[0] = x;
    for(int i=1; i<30; i++)
    {
        xx[i] = xx[i-1]*xx[i-1] % MOD;
    }
    for(int i=29; i>=0; i--)
    {
        if((MOD-2) & (1<<i))
        {
            cur *= xx[i];
            cur %= MOD;
        }
    }
    return cur;

}
int main()
{
    cin>>N>>M;
    ll inverse = inv(M);
    for(int i=1; i<=N; i++)
    {
        cin>>a[i];
    }
    for(int i=1; i<=N; i++)
    {
        cin>>b[i];
    }
    DP2[0] = 1;
    for(int i=1; i<=N; i++)
    {
        if(a[i]!=0&&b[i]!=0)
        {
            if(a[i]>b[i])
            {
                DP[i] = (DP[i-1]+DP2[i-1]) % MOD;
                DP2[i] = 0;
            }
            if(a[i]<b[i])
            {
                DP[i] = DP[i-1] % MOD;
                DP2[i] = 0;
            }
            if(a[i]==b[i])
            {
                DP[i] = DP[i-1];
                DP2[i] = DP2[i-1];
            }
        }
        if(a[i]==0&&b[i]!=0)
        {
            DP2[i] = DP2[i-1]*inverse%MOD;
            DP[i] = (DP[i-1] + ((DP2[i-1]*inverse)%MOD*(M-b[i])))%MOD;
        }
        if(a[i]!=0&&b[i]==0)
        {
            DP2[i] = DP2[i-1]*inverse%MOD;
            DP[i] = (DP[i-1] + ((DP2[i-1]*inverse)%MOD*(a[i]-1)))%MOD;
        }
        if(a[i]==0&&b[i]==0)
        {
            DP2[i] = DP2[i-1]*inverse%MOD;
            DP[i] = (DP[i-1] + ((DP2[i-1])*(1+MOD-inverse)%MOD)*500000004)%MOD;
        }
    }
    cout<<DP[N] % MOD<<endl;
}