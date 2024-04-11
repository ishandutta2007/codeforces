#include <iostream>
#include <fstream>
#define MAXN 1000100
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int T;
ll N, M, K;
ll inv[MAXN];
ll solve()
{
    inv[1] = 1;
    for(int i=2; i<=N; i++)
    {
        inv[i] = (MOD/i) * (MOD-inv[MOD % i]) % MOD;
    }
    ll tot = 0;
    ll cur = 1;
    for(ll i=0; i<M; i++)
    {
        tot += (cur * (M-i));
        tot %= MOD;
        cur *= (N-i);
        cur %= MOD;
        cur *= inv[i+1];
        cur %= MOD;
    }
    tot *= K;
    tot %= MOD;
    for(ll i=0; i<N-1; i++)
    {
        tot *= inv[2];
        tot %= MOD;
    }
    return tot;
}
int main()
{
    cin>>T;
    for(int i=0; i<T; i++)
    {
        cin>>N>>M>>K;
        cout<<solve()<<endl;
    }
}