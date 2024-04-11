#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define forn(i, n) for(int i = 0; i < (int)n; ++i)
#define ford(i, n) for(int i = (int)n - 1; i >= 0; --i)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define sqrt(x) sqrt(fabs(x))
#define clr(x) memset(x, 0, sizeof(x))

int main()
{
    int n;
    cin >> n;
    int dp[n + 1];
    clr(dp);
    int right = 0;
    for(int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        dp[a] = dp[a - 1] + 1;
        if (dp[a] > dp[right])
            right = a;
    }
    int cur = right;
    while(dp[cur] > 1)
        --cur;
    int left = cur;
    cout << n - dp[right] << endl;
    return 0;
}