#include <iostream>

using namespace std;

int N;
int dp[3100];
int s[3100], c[3100];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> s[i];
    for (int i = 0; i < N; i++)
    {
        cin >> c[i];
        dp[i] = 1e9;
    }
    
    int ans = 1e9;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
            if (s[j] < s[i])
            {
                dp[i] = min(dp[i], c[i] + c[j]);
                ans = min (ans, dp[j] + c[i]);
            }
    }
    if (ans > 9e8) cout << "-1\n";
    else cout << ans << "\n";
}