#include <bits/stdc++.h>
#define MAXN 300300
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
ll power(ll x, int y)
{
    ll cur = 1; ll cur2 = x;
    for(int i=0; i<30; i++)
    {
        if((1<<i) & y)
        {
            cur = cur * cur2 % MOD;
        }
        cur2 = cur2 * cur2 % MOD;
    }
    return cur;
}
ll inv(ll x)
{
    return power(x, MOD-2);
}
ll D[MAXN];
int N, M;
ll circumference;
int v;
int main()
{
    cin>>N>>M;
    for(int i=0; i<N; i++)
    {
        cin>>D[i];
        circumference += D[i];
    }
    int counter = 0; ll cursum = 0; ll countersum = 0;
    for(int i=0; i<N; i++)
    {
        cursum += D[i];
        while(2*(cursum - countersum) > circumference)
        {
            countersum += D[counter];
            ++counter;
        }
        if(counter > 0 && 2*(cursum - countersum) == circumference)
        {
            ++v;
        }
    }
    ll ans = 0; ll choose = 1; ll prod = 1;
    for(int i=0; i<=v; i++) //Number of diametrically opposite points with the same color
    {
        ans += (power(M-i, N-v-i) * power(M-i-1, v-i) % MOD * prod % MOD * choose);
        ans %= MOD;
        choose = choose * (v-i) % MOD * inv(i+1) % MOD;
        prod = prod * (M-i) % MOD;
    }
    cout<<ans<<endl;
}