#include <iostream>
#include <fstream>
#define MOD 1000000007
#define MAXN 1010
using namespace std;
typedef long long ll;
ll inv(ll x)
{
    ll pwr[30];
    ll power[30];
    pwr[0] = x; power[0] = 1;
    ll cur = MOD-2;
    ll q = 1;
    for(int i=1; i<30; i++)
    {
        pwr[i] = pwr[i-1]*pwr[i-1];
        pwr[i] %= MOD;
        power[i] = power[i-1] * 2;
    }
    for(int i=29; i>=0; i--)
    {
        if(cur >= power[i])
        {
            cur -= power[i];
            q *= pwr[i];
            q %= MOD;
        }
    }
    return q;

}
int k; ll pa, pb;
ll a, b;
ll DP[MAXN][MAXN];
ll ans, cur1, cur2;
int main()
{
    cin>>k>>pa>>pb;
    a = pa*inv(pa+pb);
    a %= MOD;
    b = pb*inv(pa+pb);
    b %= MOD;
    DP[1][0] = 1;
    for(int i=1; i<=k; i++)
    {
        for(int j=0; j<=k; j++)
        {
            if(i>0&&(i+j)<=k)
                DP[i][j] += DP[i-1][j]*a;
            if(j>=i&&j<k&&i!=0)
                DP[i][j] += DP[i][j-i]*b;
            DP[i][j] %= MOD;
            if((i+j) >= k)
            {
                cur1 = a*inv(b)+i+j;
                cur1 %= MOD;
                cur2 = DP[i][j]*cur1;
                ans += cur2;
                ans %= MOD;
            }
        }
    }
    cout<<ans<<endl;
}