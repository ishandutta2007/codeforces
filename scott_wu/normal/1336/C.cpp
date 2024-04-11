#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 3100;
const ll MOD = 998244353;

int N, M;
string S, T;
ll dp[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> S >> T;
    N = S.length();
    M = T.length();

    for (int i = 0; i <= N; i++)
        dp[i][i] = 1;

    ll ans = 0;
    for (int len = 0; len < N; len++)
        for (int i = 0; i + len <= N; i++)
        {
            int lo = i, hi = i + len;
            char nc = S[len];
            if (lo > 0 && ((lo - 1 >= M) || T[lo-1] == nc))
                dp[lo-1][hi] = (dp[lo-1][hi] + dp[lo][hi]) % MOD;
            if (hi < N && ((hi >= M) || T[hi] == nc))
                dp[lo][hi+1] = (dp[lo][hi+1] + dp[lo][hi]) % MOD;
        }
    for (int i = M; i <= N; i++)
        ans = (ans + dp[0][i]) % MOD;
    cout << ans << "\n";
}