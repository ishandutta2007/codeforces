#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, b, a) for (int i = (b)-1; i >= (a); --i)
#define FILL(A, value) memset(A, value, sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<Int, Int> PLL;
typedef pair<double, double> PDD;
typedef complex<double> base;

const int INF = 1000000000;
const int MOD = 998244353;
const double Pi = acos(-1.);

const int MAX = 1000007;

int dp[MAX][5][5];
int cnt[MAX];

int main()
{
    int n, m;
    cin >> n >> m;
    FOR(i, 0, n)
    {
        int x;
        scanf("%d", &x);
        --x;
        cnt[x]++;
    }

    FOR(i, 0, MAX)
    FOR(j, 0, 5)
    FOR(k, 0, 5)
    dp[i][j][k] = -INF;
    dp[0][0][0] = 0;

    FOR(i, 0, m)
    FOR(j, 0, 5)
    FOR(k, 0, 5)
    {
        int max_prev = min(min(cnt[i], 2), min(j, k));
        FOR(prev, 0, max_prev + 1)
        {
            int cur = cnt[i] - prev;
            dp[i + 1][cur % 3][j - prev] = max(dp[i + 1][cur % 3][j - prev], dp[i][j][k] + prev + cur / 3);
            if (cur >= 3)
                dp[i + 1][min(4, cur % 3 + 3)][j - prev] = max(dp[i + 1][min(4, cur % 3 + 3)][j - prev], dp[i][j][k] + prev + cur / 3 - 1);
            if (cur >= 6)
                dp[i + 1][4][j - prev] = max(dp[i + 1][4][j - prev], dp[i][j][k] + prev + cur / 3 - 2);
        }
    }

    int res = 0;
    FOR(j, 0, 5)
    FOR(k, 0, 5)
    res = max(res, dp[m][j][k]);
    cout << res << endl;
    return 0;
}