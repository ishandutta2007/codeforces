#include <iostream>
#include <fstream>
#define MAXN 5050
#define MOD 998244353LL
using namespace std;
typedef long long ll;
ll DP[MAXN][MAXN];
ll N, M, K, ans;
ll power(ll a, ll b)
{
    ll cur2 = a;
    ll cur = 1;
    if(b%2 == 1) cur = a;
    for(int i=1; i<30; i++)
    {
        cur2 = cur2*cur2%MOD;
        if((1<<i) & b)
        {
            cur = cur*cur2%MOD;
        }
    }
    return cur;
}
ll inv(ll a)
{
    return power(a, MOD-2);
}
int main()
{
    cin>>N>>M>>K;
    DP[0][0] = 1;
    for(ll i=1; i<=K; i++)
    {
        for(ll j=1; j<=K; j++)
        {
            DP[i][j] = ((N-j+1)*DP[i-1][j-1]+j*DP[i-1][j])%MOD;
        }
    }
    for(ll i=1; i<=K; i++)
    {
        ans += DP[K][i]*power(inv(M), i);
        ans %= MOD;
    }
    cout<<ans<<endl;
}