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
const int MAXN = 1100;
const int MAXD = MAXN * MAXN;
const ll MOD = 998244353;

int N, M;
int arr[MAXN][MAXN];

pair <int, pair <int, int> > pp[MAXD];
ll dp[MAXD];

ll cpow (ll x, ll e)
{
    ll r = x, ans = 1;
    while (e)
    {
        if (e & 1)
            ans = (ans * r) % MOD;
        e /= 2;
        r = r * r % MOD;
    }
    return ans;
}

ll inv (ll x)
{
    return cpow (x, MOD - 2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
            pp[i*M+j] = make_pair(arr[i][j], make_pair (i, j));
        }
    }

    sort (pp, pp + N * M);
    int ccur = 0;

    ll dpsum = 0, xsum = 0, ysum = 0, x2sum = 0, y2sum = 0;
    while (ccur < N * M)
    {
        int ncur = ccur;
        while (ncur < N * M && pp[ccur].first == pp[ncur].first)
        {
            ncur++;
        }

        if (ccur)
        for (int i = ccur; i < ncur; i++)
        {
            ll x = pp[i].second.first, y = pp[i].second.second;
            dp[i] = x2sum + ccur * x * x - 2 * xsum * x;
            dp[i] += y2sum + ccur * y * y - 2 * ysum * y;
            dp[i] += dpsum;
            dp[i] = (dp[i] % MOD + MOD) % MOD;
            dp[i] = (dp[i] * inv (ccur)) % MOD;
        }

        for (int i = ccur; i < ncur; i++)
        {
            ll x = pp[i].second.first, y = pp[i].second.second;
            dpsum += dp[i];
            xsum += x;
            x2sum += (x * x);
            ysum += y;
            y2sum += (y * y);
            dpsum %= MOD;
            xsum %= MOD;
            ysum %= MOD;
            x2sum %= MOD;
            y2sum %= MOD;
        }
        dpsum %= MOD;
        xsum %= MOD;
        ysum %= MOD;
        x2sum %= MOD;
        y2sum %= MOD;

        ccur = ncur;
    }

    int r, c;
    cin >> r >> c;
    r--, c--;
    for (int i = 0; i < N * M; i++)
    {
        if (pp[i].second.first == r && pp[i].second.second == c)
            cout << dp[i] << "\n";
    }
}