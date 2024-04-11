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

int N, K;
ll a[55];
ll ps[55];
bool dp[55][55];

bool works (ll x)
{
    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= N; j++)
            dp[i][j] = 0;
    dp[0][0] = 1;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < K; j++)
        {
            for (int k = i; k < N; k++)
                if (((ps[k+1] - ps[i]) & x) == x)
                    dp[k+1][j+1] |= dp[i][j];
        }

    return dp[N][K];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        ps[i+1] = ps[i] + a[i];
    }

    ll res = 0;
    for (int i = 60; i >= 0; i--)
        if (works (res + (1LL << i)))
            res += (1LL << i);
    cout << res << "\n";

}