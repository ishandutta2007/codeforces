#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 15100;
const int MAXS = 350;
const int B = 600;
const int C = 60;

int N;
int arr[MAXN];
int loc[MAXN]; // inverse of arr
int dp[MAXN][MAXS][2]; // 0 = lo end, 1 = hi end

void gogo()
{
    for (int i = 0; i < MAXN; i++)
    {
        arr[i] = loc[i] = 0;
    }

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        //arr[i] = rand() % N;
        cin >> arr[i];
        arr[i]--;
        loc[arr[i]] = i;
    }

    int mtot = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        if (i == N - 1)
            dp[i][1][0] = dp[i][1][1] = arr[i];
        /*else
        {
            dp[i][1][0] = arr[i] + 1;
            dp[i][1][1] = arr[i] - 1;
        }*/

        for (int k = 0; k < 2; k++)
        {
            int mj = 0;
            for (int j = 1; j < MAXS; j++)
                if (dp[i][j][k] != -1)
                {
                    mj = j;
                    mtot = max (mtot, j);
                }

            for (int j = max (1, max (mj - C, mtot - 100)); j < MAXS; j++)
            {
                if (dp[i][j][k] == -1) continue;
                int v = dp[i][j][k];

                int lo = min (arr[i], v), hi = max (arr[i], v);

                for (int m = lo - 1; m >= lo - B && m >= 0; m--)
                {
                    int l = loc[m];
                    if (l >= i) continue;
                    if ((k == 0) || (k == 1 && i - l >= j))
                    {
                        if (dp[l][j+1][0] == -1) dp[l][j+1][0] = hi;
                        else dp[l][j+1][0] = min (dp[l][j+1][0], hi);
                    }
                }

                for (int m = hi + 1; m <= hi + B && m < N; m++)
                {
                    int l = loc[m];
                    if (l >= i) continue;
                    if ((k == 1) || (k == 0 && i - l >= j))
                    {
                        if (dp[l][j+1][1] == -1) dp[l][j+1][1] = lo;
                        else dp[l][j+1][1] = max (dp[l][j+1][1], lo);
                    }                    
                }
                for (int l = i - 1; l >= 0 && l >= i - B; l--)
                {
                    if (arr[l] < lo)
                    {
                        if ((k == 0) || (k == 1 && i - l >= j))
                        {
                            if (dp[l][j+1][0] == -1) dp[l][j+1][0] = hi;
                            else dp[l][j+1][0] = min (dp[l][j+1][0], hi);
                        }
                    }
                    else if (arr[l] > hi)
                    {
                        if ((k == 1) || (k == 0 && i - l >= j))
                        {
                            if (dp[l][j+1][1] == -1) dp[l][j+1][1] = lo;
                            else dp[l][j+1][1] = max (dp[l][j+1][1], lo);
                        }
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < MAXS; j++)
            for (int k = 0; k < 2; k++)
                if (dp[i][j][k] != -1)
                    ans = max (ans, j);
    //cout << ans << "\n";

    for (int i = 0; i <= N; i++)
        for (int j = 0; j < MAXS; j++)
            for (int k = 0; k < 2; k++)
                dp[i][j][k] = -1;

    mtot = 0;
    for (int i = N - 2; i >= 0; i--)
    {
        {
            dp[i][2][0] = arr[i];
            dp[i][2][1] = arr[i];
        }

        for (int k = 0; k < 2; k++)
        {
            int mj = 0;
            for (int j = 1; j < MAXS; j++)
                if (dp[i][j][k] != -1)
                {
                    mj = j;
                    mtot = max (mtot, j);
                }

            for (int j = max (1, max (mj - C, mtot - 100)); j < MAXS; j++)
            {
                if (dp[i][j][k] == -1) continue;
                int v = dp[i][j][k];

                int lo = min (arr[i], v), hi = max (arr[i], v);
                for (int m = lo - 1; m >= lo - B && m >= 0; m--)
                {
                    int l = loc[m];
                    if (l >= i) continue;
                    if ((k == 0) || (k == 1 && i - l >= j))
                    {
                        if (dp[l][j+1][0] == -1) dp[l][j+1][0] = hi;
                        else dp[l][j+1][0] = min (dp[l][j+1][0], hi);
                    }
                }
                for (int m = hi + 1; m <= hi + B && m < N; m++)
                {
                    int l = loc[m];
                    if (l >= i) continue;
                    if ((k == 1) || (k == 0 && i - l >= j))
                    {
                        if (dp[l][j+1][1] == -1) dp[l][j+1][1] = lo;
                        else dp[l][j+1][1] = max (dp[l][j+1][1], lo);
                    }                    
                }
                for (int l = i - 1; l >= 0 && l >= i - B; l--)
                {
                    if (arr[l] < lo)
                    {
                        if ((k == 0) || (k == 1 && i - l >= j))
                        {
                            if (dp[l][j+1][0] == -1) dp[l][j+1][0] = hi;
                            else dp[l][j+1][0] = min (dp[l][j+1][0], hi);
                        }
                    }
                    else if (arr[l] > hi)
                    {
                        if ((k == 1) || (k == 0 && i - l >= j))
                        {
                            if (dp[l][j+1][1] == -1) dp[l][j+1][1] = lo;
                            else dp[l][j+1][1] = max (dp[l][j+1][1], lo);
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < N; i++)
        for (int j = 1; j < MAXS; j++)
            for (int k = 0; k < 2; k++)
                if (dp[i][j][k] != -1)
                    ans = max (ans, j - 1);

    cout << ans << "\n";

    for (int i = 0; i <= N; i++)
        for (int j = 0; j < MAXS; j++)
            for (int k = 0; k < 2; k++)
                dp[i][j][k] = -1;
}

int main()
{
    ios_base::sync_with_stdio(0);

    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXS; j++)
            for (int k = 0; k < 2; k++)
                dp[i][j][k] = -1;

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}