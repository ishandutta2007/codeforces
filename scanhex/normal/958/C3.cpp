#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <iomanip>
#include <bitset>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

const int K = 100 + 1;
const int P = 100 + 1;

int dp[2][K][P];

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, p;
    cin >> n >> k >> p;
    k = min(k, (int) 2e8 / (n * p));
    vector <int> a(n);
    int it = 0;
    for (int i = 0; i < 2; i++) for (int j = 0; j <= k; j++) for (int x = 0; x <= p; x++) dp[i][j][x] = 1e9;
    dp[0][0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] %= p;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            for (int x = 0; x < p; x++)
            {
                int go_x = x + a[i];
                if (go_x >= p) go_x -= p;
                dp[it ^ 1][j][go_x] = min(dp[it ^ 1][j][go_x], dp[it][j][x]);
                if (i != 0)
                {
                    dp[it ^ 1][j + 1][a[i]] = min(dp[it ^ 1][j + 1][a[i]], dp[it][j][x] + x);
                }
                dp[it][j][x] = 1e9;
            }
        }
        it ^= 1;
    }
    int ans = 1e9;
    for (int x = 0; x < p; x++)
    {
        ans = min(ans, dp[it][k - 1][x] + x);
    }
    cout << ans << '\n';
}