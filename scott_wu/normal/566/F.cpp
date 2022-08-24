#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 1000100;

int N;
int arr[MAXN];
int dp[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    
    for (int i = 0; i < MAXN; i++)
        arr[i] = dp[i] = 0;
    
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x; cin >> x;
        arr[x]++;
    }
    
    int ans = 0;
    for (int i = 1; i < MAXN; i++)
    {
        dp[i] = max (dp[i], arr[i]);
        ans = max (ans, dp[i]);
        for (int j = 2; j <= (MAXN - 1) / i; j++)
            dp[i*j] = max (dp[i*j], dp[i] + arr[i*j]);
    }
    
    cout << ans << "\n";
    return 0;
}