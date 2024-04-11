#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
 
using namespace std;
typedef long long ll;
const int MAXN = 1100;
const ll MOD = 998244353;

int N, K;
int arr[MAXN];
int dp[MAXN][MAXN];
int ps[MAXN][MAXN];

ll figure (int k)
{
    if (k * (K - 1) > arr[N-1])
        return 0;

    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= K; j++)
            dp[i][j] = ps[i][j] = 0;
    for (int i = 1; i <= N; i++)
        dp[i][1] = 1;
    int cstop = 0;
    for (int i = 0; i < N; i++)
    {
        while (cstop < i && arr[i] - arr[cstop] >= k)
            cstop++;

        //cout << cstop << " " << i << "\n";
        for (int j = 1; j < K; j++)
        {
            dp[i+1][j+1] = ps[cstop][j];
        }
        for (int j = 0; j <= K; j++)
        {
            ps[i+1][j] = (ps[i][j] + dp[i+1][j]) % MOD;
        }
    }
    return ps[N][K];
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort (arr, arr + N);

    ll ans = 0;
    for (int i = 1; i <= 100000; i++)
        ans = (ans + figure (i)) % MOD;
    cout << ans << "\n";
}