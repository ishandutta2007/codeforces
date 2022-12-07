#include <iostream>
#include <fstream>
#include <cmath>
#define MAXN 31
#define MAXQ (ll) (1<<30)
#define MOD (ll) (1e9 + 7)
using namespace std;
typedef long long ll;
ll power[MAXN];
int Q;
ll a1, b1, a2, b2, k;
ll solve(ll l, ll r, ll u, ll d)
{
    ll w = (u-1) ^ (l-1);
    ll d1 = r-l+1;
    ll d2 = d-u+1;
    if(d1 < d2)
    {
        swap(d1, d2);
    }
    w -= (w % d1);
    ll maxval = max(w, min(k, w+d1));
    ll ans = ((maxval - w) * (maxval + w + 1)/2) % MOD;
    ans = (ans * d2) % MOD;
    return ans;
}
ll query(ll l, ll r, ll u, ll d)
{
    if(l>a2||r<a1)
    {
        return 0;
    }
    else if(a1<=l&&r<=a2)
    {
        if(u>b2||d<b1)
        {
            return 0;
        }
        else if(b1<=u&&d<=b2)
        {
            return solve(l, r, u, d);
        }
        else
        {
            return (query(l, r, u, (u+d)/2) + query(l, r, (u+d)/2+1, d)) % MOD;
        }
    }
    else
    {
        return (query(l, (l+r)/2, u, d) + query((l+r)/2+1, r, u, d)) % MOD;
    }
}
int main()
{
    power[0] = 1;
    for(int i=1; i<MAXN; i++)
    {
        power[i] = 2 * power[i-1];
    }
    cin>>Q;
    for(int i=0; i<Q; i++)
    {
        cin>>a1>>b1>>a2>>b2>>k;
        cout<<query(1, MAXQ, 1, MAXQ)<<endl;
    }
}