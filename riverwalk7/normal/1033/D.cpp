#include <iostream>
#include <fstream>
#include <map>
#include <cmath>
#include <algorithm>
#define MAXN 510
#define MOD 998244353LL
using namespace std;
typedef long long ll;
int N;
ll a[MAXN];
ll r[MAXN];
ll cur;
map<ll, ll> m;
map<ll, bool> t;
ll ans;
bool flag;
ll c;
ll root(ll u, int v)
{
    ll lbound = 1; ll avg, hbound;
    if(v == 2)
    {
        hbound = 1.5e9;
    }
    if(v == 3)
    {
        hbound = 1.3e6;
    }
    if(v == 4)
    {
        hbound = 4e4;
    }
    while(lbound != hbound)
    {
        avg = (lbound + hbound)/2;
        ll cur2 = 1;
        for(int i=0; i<v; i++)
        {
            cur2 *= avg;
        }
        if(cur2 <= u)
        {
            lbound = avg+1;
        }
        else
        {
            hbound = avg;
        }
    }
    while(true)
    {
        ll cur2 = 1;
        for(int i=0; i<v; i++)
        {
            cur2 *= avg;
        }
        if(cur2 > u)
        {
            --avg;
            continue;
        }
        cur2 = 1;
        for(int i=0; i<v; i++)
        {
            cur2 *= (avg+1);
        }
        if(cur2 <= u)
        {
            ++avg;
            continue;
        }
        break;
    }
    return avg;
}
int main()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>a[i];
    }
    for(int i=0; i<N; i++)
    {
        cur = root(a[i], 4);
        if(cur * cur * cur * cur == a[i])
        {
            m[cur] += 4;
            continue;
        }
        cur = root(a[i], 2);
        if(cur * cur == a[i])
        {
            m[cur] += 2;
            continue;
        }
        cur = root(a[i], 3);
        if(cur * cur * cur == a[i])
        {
            m[cur] += 3;
            continue;
        }
        flag = false;
        for(int j=0; j<N; j++)
        {
            if(a[j] != a[i])
            {
                c = __gcd(a[j], a[i]);
                if(c != a[i] && c != 1)
                {
                    m[c]++;
                    m[a[i]/c]++;
                    flag = true;
                    break;
                }
            }
        }
        if(flag) continue;
        m[a[i]]++;
        t[a[i]] = true;
    }
    ans = 1;
    for (std::map<ll,ll>::iterator it=m.begin(); it!=m.end(); ++it)
    {
        cur = it->second;
        if(t[it -> first]) ans *= (cur+1)*(cur+1);
        else ans *= (cur + 1);
        ans %= MOD;
    }
    cout<<ans<<endl;
}