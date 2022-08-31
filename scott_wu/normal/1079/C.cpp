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
const int MAXN = 100100;

int N;
int arr[MAXN];
int dp[MAXN][6];
int ans[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < MAXN; i++)
        for (int j = 1; j <= 5; j++)
        {
            if (i)
                dp[i][j] = 0;
            else
                dp[i][j] = -1;
        }

    for (int i = 1; i < N; i++)
    {
        for (int pv = 1; pv <= 5; pv++)
            for (int nv = 1; nv <= 5; nv++)
            {
                if (!dp[i-1][pv]) continue;
                if (arr[i-1] < arr[i] && pv >= nv) continue;
                if (arr[i-1] > arr[i] && pv <= nv) continue;
                if (arr[i-1] == arr[i] && pv == nv) continue;
                dp[i][nv] = pv;
            }
    }

    int cloc = 0;
    for (int i = 1; i <= 5; i++)
        if (dp[N-1][i])
            cloc = i;
    if (!cloc)
    {
        cout << "-1\n";
        return 0;
    }

    for (int i = N - 1; i >= 0; i--)
    {
        ans[i] = cloc;
        cloc = dp[i][cloc];
    }
    for (int i = 0; i < N; i++)
    {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << "\n";
}