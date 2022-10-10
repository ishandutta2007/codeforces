#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long cnt[100000 + 5], dp[100000 + 5];
    memset(cnt, 0, sizeof(cnt));
    memset(dp, 0, sizeof(dp));
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        long long a;
        cin >> a;
        cnt[a]++;
    }
    for(int i = 1; i <= 100000; i++)
    {
        if(i > 1) dp[i] = max(dp[i - 1], dp[i - 2] + i*cnt[i]);
        else dp[i] = cnt[1];
    }
    cout << dp[100000];
}