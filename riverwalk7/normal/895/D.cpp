#include <iostream>
#include <fstream>
#include <string>
#define MAXN 1000100
using namespace std;
typedef long long ll;
ll c[31];
ll MOD;
ll inv(ll x)
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
string a, b;
int x[26];
int y[26];
int g;
ll f[MAXN];
ll cur;
ll ans, ans2;
ll t, p;
ll kk;
int main()
{
    MOD = 1e9+7;
    cin>>a>>b;
    f[0] = 1;
    for(int i=1; i<MAXN; i++)
    {
        f[i] = f[i-1] * i;
        f[i] %= MOD;
    }
    for(int i=0; i<a.length(); i++)
    {
        x[a[i]-'a']++;
        y[a[i]-'a']++;
    }
    cur = f[a.length()];
    for(int i=0; i<26; i++)
    {
        cur *= inv(f[x[i]]);
        cur %= MOD;
    }
    t = a.length();
    for(int i=0; i<a.length(); i++)
    {
        g = b[i]-'a';
        kk = 0;
        for(int j=0; j<g; j++)
        {
            kk += x[j];
        }
        p = cur * inv(t);
        p %= MOD;
        p *= kk;
        p %= MOD;
        ans += p;
        ans %= MOD;
        if(x[g]>0)
        {
            cur *= inv(t);
            cur %= MOD;
            cur *= x[g];
            cur %= MOD;
            x[g]--;
            t--;
        }
        else
        {
            break;
        }
    }
    cur = f[a.length()];
    for(int i=0; i<26; i++)
    {
        cur *= inv(f[y[i]]);
        cur %= MOD;
    }
    t = a.length();
    for(int i=0; i<a.length(); i++)
    {
        g = a[i]-'a';
        kk = 0;
        for(int j=0; j<g; j++)
        {
            kk += y[j];
        }
        p = cur * inv(t);
        p %= MOD;
        p *= kk;
        ans2 += p;
        ans2 %= MOD;
        if(y[g]>0)
        {
            cur *= inv(t);
            cur %= MOD;
            cur *= y[g];
            cur %= MOD;
            y[g]--;
            t--;
        }
        else
        {
            break;
        }
    }
    cout<<(ans-ans2-1+2*MOD)%MOD<<endl;
}