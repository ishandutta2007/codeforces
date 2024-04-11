#include <bits/stdc++.h>

using namespace std;

const int N = 2000;

int a[N];

int dp[N];

int n, k;

void read()
{
    //n = 2000, k = 500;
    cin >> n >> k;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
}


bool check(long long d)
{
    for(int i = 0; i < n; ++i)
    {
        dp[i] = i;

        for(int j = 0; j < i; ++j)
            if (abs(a[i] - a[j]) <= (i - j) * d)
                dp[i] = min(dp[i], i - j - 1 + dp[j]);
    }
    int res = n;
    for(int i = 0; i < n; ++i)
    {
        res = min(res, dp[i] + n - 1 - i);
    }
    //cout << d << " " << res << endl;
    return res <= k;
}

void solve()
{
    int l = 0, r = 2e9 + 1;

    while(l < r)
    {
        int m = l + (r - l) / 2;

        if (check(m))
            r = m;
        else
            l = m + 1;
    }

    cout << l << endl;
}

int main()
{
    read();
    solve();
    return 0;
}