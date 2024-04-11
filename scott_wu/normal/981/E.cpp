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
const ll MOD = 1e18 + 1;
const int MAXN = 10100;

int N, Q;
long long dp[MAXN];
bool f[MAXN];
vector <int> v[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N >> Q;
    for (int i = 0; i < Q; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        v[x-1].push_back(z);
        v[y].push_back(-z);
    }

    dp[0] = 1;
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
            if (dp[j])
                f[j] = true;

        for (int j = 0; j < v[i].size(); j++)
        {
            int x = v[i][j];
            if (x > 0)
            {
                for (int j = N; j >= 0; j--)
                    if (j + x <= N)
                    {
                        dp[j+x] = (dp[j+x] + dp[j]);
                        if (dp[j+x] >= MOD)
                            dp[j+x] -= MOD;
                    }
            }
            else
            {
                x = -x;
                for (int j = 0; j <= N; j++)
                    if (j + x <= N)
                    {
                        dp[j+x] = (dp[j+x] + MOD - dp[j]);
                        if (dp[j+x] >= MOD)
                            dp[j+x] -= MOD;
                    }
            }
        }
    }
    int nr = 0;
    for (int i = 1; i <= N; i++)
        if (f[i]) nr++;
    cout << nr << "\n";
    for (int i = 1; i <= N; i++)
        if (f[i]) cout << i << " ";
}