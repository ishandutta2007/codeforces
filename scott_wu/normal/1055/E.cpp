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
const int MAXN = 1600;

int N, S, M, K;
int arr[MAXN];
int far[MAXN];

pair <int, int> ord[MAXN];
int d[MAXN];

int dp[MAXN][MAXN]; // min to get to i and skip k

bool works (int X)
{
    for (int i = 0; i < N; i++)
    {
        if (i < X)
            d[ord[i].second] = 1;
        else
            d[ord[i].second] = 0;
    }

    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            dp[i][j] = MAXN;
    dp[0][0] = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            dp[i+1][j+d[i]] = min (dp[i+1][j+d[i]], dp[i][j]);

        if (far[i] >= i)
        {
            for (int j = 0; j < N; j++)
                dp[far[i]+1][j] = min (dp[far[i]+1][j], dp[i][j] + 1);
        }
    }

    int nskip = X - K;
    for (int i = 0; i <= nskip; i++)
        if (dp[N][i] <= M)
            return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    for (int i = 0; i < MAXN; i++)
        far[i] = -1;

    cin >> N >> S >> M >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        ord[i] = make_pair (arr[i], i);
    }
    for (int i = 0; i < S; i++)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        far[l] = max (far[l], r);
    }
    for (int i = 1; i < N; i++)
        far[i] = max (far[i], far[i-1]);

    sort (ord, ord + N);

    if (!works (N))
    {
        cout << "-1\n";
        return 0;
    }
    int lo = K, hi = N;
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (works (mid))
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    cout << ord[lo-1].first << "\n";
}