#include <iostream>
#include <fstream>
#define MAXN 2600
#define MAXK 100100
using namespace std;
typedef long long ll;
ll N, H;
ll MOD;
ll a[MAXN];
ll p[MAXK];
ll q[MAXK];
ll c[31];
ll sum;
ll ways, d;
ll ans;
ll inverse(ll x)
{
    ll cur = 1;
    ll cur2 = MOD-2;
    c[0] = x;
    for(int i=1; i<31; i++)
    {
        c[i] = c[i-1]*c[i-1];
        c[i] %= MOD;
    }
    for(int i=30; i>=0; i--)
    {
        if(cur2 >= (1<<i))
        {
            cur2 -= (1<<i);
            cur *= c[i];
            cur %= MOD;
        }
    }
    return cur;
}
int main()
{
    MOD = 1e9+7;
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>a[i];
        sum += a[i];
        H = max(H, a[i]);
    }
    p[1] = (sum-1)*(sum-1);
    p[1] %= MOD;
    q[1] = sum*inverse(2);
    q[1] %= MOD;
    ways = (sum*(sum-1)) % MOD;
    for(int i=2; i<=H; i++)
    {
        p[i] = (p[i-1]-q[i-1]+MOD)%MOD;
        q[i] = (q[i-1]*(i-1)) % MOD;
        q[i] *= inverse(i+1);
        q[i] %= MOD;
        d = (ways*inverse(i+1)) % MOD;
        d = (d*inverse(sum-i)) % MOD;
        q[i] += d;
        q[i] %= MOD; //make sure number is smaller than mod
    }
    for(int i=0; i<N; i++)
    {
        ans += (p[a[i]]*a[i]);
        ans %= MOD;
    }
    ans *= inverse(sum);
    ans %= MOD;
    cout<<ans<<endl;
}