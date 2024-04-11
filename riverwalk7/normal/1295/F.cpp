#include <iostream>
#include <fstream>
#include <algorithm>
#define MAXN 52
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
ll inv(ll g)
{
    ll cur1 = g; ll cur2 = g;
    for(int i=1; i<30; i++)
    {
        cur2 = cur2*cur2%MOD;
        if((1<<i) & (MOD-2))
        {
            cur1 = cur1*cur2%MOD;
        }
    }
    return cur1;
}
ll l[MAXN], r[MAXN];
ll DP[MAXN][2*MAXN];
ll x[MAXN]; //the important coordinates
ll invfact[MAXN];
int N; ll ans = 1; ll cur4; ll ans2;
bool flag;
ll choose(ll a, ll b)
{
    ll cur = 1;
    for(int i=0; i<b; i++)
    {
        cur = cur*(a-(ll)(i))%MOD;
    }
    cur = cur*invfact[b] % MOD;
    return cur;
}
int main()
{
    cin>>N;
    invfact[0] = 1;
    for(int i=1; i<=N; i++)
    {
        cin>>l[N+1-i]>>r[N+1-i];
        ans = ans * inv(r[N+1-i]-l[N+1-i]+1)%MOD;
        x[2*i-1] = l[N+1-i]; x[2*i] = r[N+1-i]+1;
        invfact[i] = invfact[i-1]*inv(i)%MOD;
    }
    sort(x+1, x+2*N+1);
    x[2*N+1] = MOD-1;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=2*N; j++)
        {
            if(l[i] == x[j])
            {
                l[i] = j;
                break;
            }
        }
        for(int j=1; j<=2*N; j++)
        {
            if(r[i]+1 == x[j])
            {
                r[i] = j-1;
                break;
            }
        }
    }
    for(int i=1; i<=N; i++)
    {
        for(int j=l[i]; j<=r[i]; j++)
        {
            for(int k=0; k<i; k++)
            {
                cur4 = 0;
                for(int m=0; m<j; m++)
                {
                    cur4 += DP[k][m];
                    cur4 %= MOD;
                }
                if(k == 0) cur4 = 1;
                flag = true;
                for(int m=k+1; m<=i; m++)
                {
                    if(j < l[m] || j > r[m])
                    {
                        flag = false;
                        break;
                    }
                }
                if(flag)
                {
                    DP[i][j] += cur4 * choose(x[j+1]-x[j]+i-k-1, i-k);
                    DP[i][j] %= MOD;
                }
            }
        }
    }
    for(int i=0; i<=2*N; i++)
    {
        ans2 += DP[N][i];
        ans2 %= MOD;
    }
    cout<<ans*ans2%MOD<<endl;
}