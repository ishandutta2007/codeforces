#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 1000100;
const int MOD = 1e9 + 7;

int N;
ll a[MAXN];
ll ss[MAXN];
int par[MAXN];
int nc[MAXN];
int pc[MAXN];
bool bgood[MAXN];
int dp[MAXN];

ll gcd (ll x, ll y)
{
    if (y == 0) return x;
    return gcd (y, x % y);
}

int main()
{
    scanf ("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int p;
        scanf ("%d", &p);
        a[i] = (ll) p;
    }
    for (int i = 1; i < N; i++)
    {
        scanf("%d", par + i);
        par[i]--;
    }

    for (int i = 0; i < MAXN; i++)
        ss[i] = nc[i] = pc[i] = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        ss[i] += a[i];
        if (i)
            ss[par[i]] += ss[i];
    }

    ll ntot = ss[0];
    for (int i = 0; i < N; i++)
    {
        //cout << ntot << " " << ss[i] << "\n";
        ll cv = ntot / gcd (ntot, ss[i]);
        if (cv <= N)
        {
            nc[cv]++;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (nc[i])
        {
            for (int j = i; j <= N; j += i)
                pc[j] += nc[i];
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (pc[i] >= i)
        {
            bgood[i] = true;
            //cout << i << " ";
        }
        else bgood[i] = false;
    }

    for (int i = 0; i <= N; i++)
        dp[i] = 0;

    dp[1] = 1;
    for (int i = 1; i <= N; i++)
    {
        if (bgood[i])
        {
            for (int j = 2 * i; j <= N; j += i)
            {
                if (bgood[j])
                {
                    dp[j] += dp[i];
                    if (dp[j] >= MOD) dp[j] -= MOD;
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= N; i++)
        if (bgood[i])
            ans = (ans + dp[i]) % MOD;
    cout << ans << "\n";
}