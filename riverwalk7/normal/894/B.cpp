#include <iostream>
#include <fstream>
#define MOD 1000000007
typedef long long ll;
using namespace std;
ll x;
ll n, m, k, t;
ll p[32];
ll cur;
ll power(ll a, ll b)
{
    cur = 1;
    p[0] = a;
    for(int i=1; i<63; i++)
    {
        p[i] = p[i-1]*p[i-1];
        p[i] %= MOD;
    }
    for(int i=30; i>=0; i--)
    {
        if((1<<i) <= b)
        {
            b -= (1<<i);
            cur *= p[i];
            cur %= MOD;
        }
    }
    return cur;
}
int main()
{
    cin>>n>>m>>k;
    if(k==-1&&((m%2)!=(n%2)))
    {
        cout<<0<<endl;
        return 0;
    }
    else
    {
        n = (n-1)%(MOD-1);
        m = (m-1)%(MOD-1);
        t = (n*m) % (MOD-1);
        cout<<power(2, t)<<endl;
    }
}