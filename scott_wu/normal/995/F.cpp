#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 3100;
const ll MOD = 1e9 + 7;
const ll P = MOD;

int N, D;
int pascal[MAXN][MAXN];
int par[MAXN];
vector <int> child[MAXN];
vector <pair <int, int> > pp[MAXN];
int sz[MAXN];
int dp[MAXN][MAXN];
int work[MAXN];
ll invs[MAXN];

ll cpow (ll x, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return x;
    ll l = cpow (x, b / 2);
    l = (l * l) % P;
    if (b % 2 == 1)
        l = (l * x) % P;
    return l;
}

ll inv (ll x)
{
    return cpow (x % P, P - 2);
}

void flood (int cloc)
{
    sz[cloc] = 1;
    for (int i = 1; i <= N + 10; i++)
        dp[cloc][i] = 1;
    for (int i = 0; i < child[cloc].size(); i++)
    {
        int neigh = child[cloc][i];
        flood (neigh);
        sz[cloc] += sz[neigh];

        for (int j = 1; j <= N + 10; j++)
        {
            dp[cloc][j] = (dp[cloc][j] * (ll) dp[neigh][j]) % MOD;
        }
    }
    for (int j = 2; j <= N + 10; j++)
    {
        dp[cloc][j] = (dp[cloc][j] + dp[cloc][j-1]) % MOD;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    for (int i = 0; i < N; i++)
        pascal[0][i] = 0;
    pascal[0][0] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        for (int j = 0; j < MAXN; j++)
        {
            pascal[i][j] = pascal[i-1][j];
            if (j)
                pascal[i][j] = (pascal[i][j] + pascal[i-1][j-1]) % MOD;
        }
    }

    cin >> N >> D;
    for (int i = 1; i < N; i++)
    {
        cin >> par[i];
        par[i]--;
        child[par[i]].push_back(i);
    }

    flood (0);

    for (int i = 0; i <= N; i++)
        invs[i] = inv(i);

    ll ans = 0;
    for (int i = 0; i <= N; i++)
    {
        ll res = dp[0][i];
        for (int j = 0; j <= N; j++)
        {
            if (i == j) continue;
            ll num = ((D - j) % P + P) % P;
            ll den = i - j;
            res = (res * num) % MOD;
            if (den >= 0)
                res = (res * invs[den]) % MOD;
            else
                res = (res * (P - invs[-den])) % MOD;
        }
        ans += res;
    }
    cout << ans % MOD << "\n";
}