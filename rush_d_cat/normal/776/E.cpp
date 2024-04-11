#include <iostream>
#include <cmath>
#include <map>
#include <set>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string.h>
using namespace std;
typedef long long LL;
#define fastio ios::sync_with_stdio(false)
#define INF 1e18
const LL MOD = 1000000007;
const int MAXN = 1000000+10;
LL prime[MAXN];
LL f[MAXN][2];
void getPrim()
{
    memset(prime, 0, sizeof(prime));
    for(int i=2;i<MAXN;i++)
    {
        if(!prime[i])
        {
            prime[++prime[0]] = i;
        }
        for(int j=1;(j<=prime[0])&&(prime[j]<=(MAXN/i));j++)
        {
            prime[prime[j]*i] = 1;
            if(i%prime[j]==0) break;
        }
    }
}
LL getFactor(LL x)
{
    LL cnt = 0, i;
    LL tmp = x;
    for(i = 1; prime[i] * prime[i] <=tmp && (i <= prime[0]) ;i++)
    {
        if(tmp % prime[i] == 0)
        {
            f[++cnt][1] = 0;
            f[cnt][0] = prime[i];
            while(tmp % prime[i] == 0)
            {
                f[cnt][1]++;
                tmp /= prime[i];
            }
        }
    }
    if(tmp!=1)
    {
        f[++cnt][0] = tmp;
        f[cnt][1] = 1;
    }
    return cnt;
}

LL getEuler(LL x)
{
    getPrim();
    int cnt = getFactor(x), i;
    for(i = 1; i <= cnt; i++)
    {
        x = x / f[i][0] * (f[i][0] - 1);
    }
    return x;
}
    
LL n, k;
int main()
{
    cin >> n >> k;
    LL t = (k+1)/2; 
    LL ans = n;
    for(LL i=1;i<=t;i++) 
    {
        ans = getEuler(ans);
        if(ans == 1) break;
    }   
    ans %= MOD;
    cout << ans << endl;
}