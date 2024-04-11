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
const int MAXN = 4001;
const int MAXK = 38;
const ll MOD = 998244353;

int N1, N2, K;
vector <int> edge1[MAXN], edge2[MAXN];

ll dp[MAXN][MAXK];
ll cdp[2*MAXN][MAXK];
ll dp2[MAXN][MAXK];
ll ndp[MAXN][MAXK];
int N;
vector <int> edge[MAXN];
vector <int> ind[MAXN];
ll ntot[MAXK], ntot2[MAXK];

ll pascal[2*MAXK][2*MAXK];

void dp_solve()
{
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXK; j++)
            dp[i][j] = ndp[i][j] = 0;
    for (int i = 0; i < 2 * MAXN; i++)
        for (int j = 0; j < MAXK; j++)
            cdp[i][j] = 0;
    for (int i = 0; i < 2 * N; i++)
    {
        cdp[i][0] = 1;
    }

    for (int i = 0; i < N; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= K; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int o = 1; o <= i; o++)
            {
                ll ctot = 0;
                for (int k = 0; k < edge[j].size(); k++)
                {
                    ctot += cdp[ind[j][k] ^ 1][o-1];
                }
                ctot %= MOD;
                dp[j][i] = (dp[j][i] + ctot * dp[j][i-o]) % MOD;
                for (int k = 0; k < edge[j].size(); k++)
                {
                    int nx = ind[j][k];
                    cdp[nx][i] = (cdp[nx][i] + (ctot + MOD - cdp[nx ^ 1][o-1]) * cdp[nx][i-o]) % MOD;
                }
            }
            
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    pascal[0][0] = 1;
    for (int i = 1; i < 2 * MAXK; i++)
    {
        pascal[i][0] = 1;
        for (int j = 1; j < 2 * MAXK; j++)
        {
            pascal[i][j] = (pascal[i-1][j] + pascal[i-1][j-1]) % MOD;
        }
    }
    cin >> N1 >> N2 >> K;
    if (K % 2 == 1)
    {
        cout << "0\n";
        return 0;
    }
    K /= 2;

    for (int i = 0; i < N1 - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        edge[x].push_back(y);
        edge[y].push_back(x);
        ind[x].push_back(2*i);
        ind[y].push_back(2*i+1);
    }
    N = N1;
    dp_solve();
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXK; j++)
            dp2[i][j] = dp[i][j];

    for (int i = 0; i < N2; i++)
    {
        edge[i].clear();
        ind[i].clear();
    }
    for (int i = 0; i < N2 - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        edge[x].push_back(y);
        edge[y].push_back(x);
        ind[x].push_back(2*i);
        ind[y].push_back(2*i+1);
    }
    N = N2;
    dp_solve();

    for (int i = 0; i <= K; i++)
    {
        ntot[i] = ntot2[i] = 0;
    }

    for (int i = 0; i <= K; i++)
    {
        for (int j = 0; j < MAXN; j++)
        {
            ntot[i] = (ntot[i] + dp[j][i]) % MOD;
            ntot2[i] = (ntot2[i] + dp2[j][i]) % MOD;
        }
    }

    ll ans = 0;
    for (int i = 0; i <= K; i++)
    {
        //cout << ntot[i] << " " << ntot2[K-i] << " " << pascal[2*K][2*i] << "\n";
        ll v = ntot[i] * ntot2[K-i];
        v %= MOD;
        v = v * pascal[2*K][2*i];
        v %= MOD;
        //cout << v << "\n";
        ans = (ans + v) % MOD;
    }
    cout << ans << "\n";
}