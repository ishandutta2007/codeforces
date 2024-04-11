#include <iostream>
#include <fstream>
#include <vector>
#define MAXN 100100
using namespace std;
typedef long long ll;
int N;
ll a[MAXN];
vector<int> primes;
bool flag;
ll k[20];
ll x[2048];
ll DP[2048];
bool b[MAXN];
ll s[2048];
ll power[MAXN];
ll cur;
ll ans, MOD;
int main()
{
    cin>>N;
    MOD = 1000000007;
    ans = 1;
    for(int i=2; i<=70; i++)
    {
        flag = false;
        for(int j=0; j<primes.size(); j++)
        {
            if(i%primes[j]==0)
            {
                flag = true;
                break;
            }
        }
        if(!flag)
        {
            primes.push_back(i);
        }
    }
    power[0] = 1;
    for(int i=1; i<MAXN; i++)
    {
        power[i] = power[i-1]*2;
        power[i] %= MOD;
    }
    for(int i=0; i<N; i++)
    {
        cin>>a[i];
        for(int j=8; j>=1; j--)
        {
            if(a[i]%(j*j)==0)
            {
                a[i]/=(j*j);
            }
        }
    }
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<primes.size(); j++)
        {
            if(a[i]==primes[j]&&a[i]>35)
            {
                k[j]++;
                b[i] = true;
            }
        }
    }
    for(int i=0; i<20; i++)
    {
        if(k[i]>0)
        {
            ans *= power[k[i]-1];
            ans %= MOD;
        }
    }
    for(int i=0; i<N; i++)
    {
        cur = 0;
        for(int j=0; j<11; j++)
        {
            if(a[i]%primes[j]==0)
            {
                cur += power[j];
                cur %= MOD;
            }
        }
        if(!b[i])
        {
            x[cur]++;
        }
    }
    DP[0] = power[x[0]];
    for(int i=1; i<2048; i++)
    {
        for(int j=0; j<2048; j++)
        {
            if(x[i]>0)
            {
                s[j] = DP[j]*power[x[i]-1] + power[x[i]-1]*DP[i^j];
                s[j] %= MOD;
            }
        }
        if(x[i]>0)
        {
            for(int j=0; j<2048; j++)
            {
                DP[j] = s[j];
            }
        }
    }
    ans *= DP[0];
    ans += (MOD-1);
    ans %= MOD;
    cout<<ans<<endl;
}