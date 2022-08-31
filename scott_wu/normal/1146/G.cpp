#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAXN = 55;

int N, H, M;
int dp[MAXN][MAXN][MAXN]; // sum of building values minus indiv restrictions on [i..j] assuming max height k
int l[MAXN], r[MAXN], x[MAXN], c[MAXN];

vector <int> get_inds (int lo, int hi)
{
    vector <int> res;
    for (int i = 0; i < M; i++)
    {
        if (l[i] >= lo && r[i] <= hi)
            res.push_back(i);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N >> H >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> l[i] >> r[i] >> x[i] >> c[i];
        l[i]--;
        r[i]--;
    }

    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            for (int k = 0; k < MAXN; k++)
                dp[i][j][k] = 0;
    for (int i = 0; i < N; i++)
    {
        vector <int> ivs = get_inds (i, i);
        for (int j = 0; j <= H; j++)
        {
            int nt = 0;
            for (int k : ivs)
            {
                if (l[k] <= i && i <= r[k] && x[k] < j)
                    nt -= c[k];
            }
            dp[i][i][j] = j * j + nt;
            if (j)
                dp[i][i][j] = max (dp[i][i][j], dp[i][i][j-1]);
        }
    }

    for (int len = 1; len < N; len++)
        for (int i = 0; i + len < N; i++)
        {
            int j = i + len;
            vector <int> ivs = get_inds (i, j);
            for (int loc = i; loc <= j; loc++)
            {
                for (int h = 0; h <= H; h++)
                {
                    int nt = 0;
                    for (int k : ivs)
                    {
                        if (l[k] <= loc && loc <= r[k] && x[k] < h)
                            nt -= c[k];
                    }
                    int nv = h * h + nt;
                    if (loc > i)
                        nv += dp[i][loc-1][h];
                    if (loc < j)
                        nv += dp[loc+1][j][h];
                    dp[i][j][h] = max (dp[i][j][h], nv);
                }
            }

            for (int h = 1; h <= H; h++)
                dp[i][j][h] = max (dp[i][j][h], dp[i][j][h-1]);
        }
    cout << dp[0][N-1][H] << "\n";
}