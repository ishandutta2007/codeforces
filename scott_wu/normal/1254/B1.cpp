#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1000100;

int N;
ll arr[MAXN];
ll csum;

ll nv[MAXN];
ll dp[MAXN][2];

ll gogo (ll x)
{
    nv[0] = 0;
    for (int i = 0; i < N; i++)
    {
        nv[i+1] = (nv[i] + arr[i]) % x;
    }

    for (int i = 0; i <= N; i++)
    {
        dp[i][0] = dp[i][1] = 3e18;
    }

    dp[0][0] = nv[1]; // give away
    dp[0][1] = (x - nv[1]); // add to
    for (int i = 1; i < N; i++)
    {
        if ((x - nv[i]) + nv[i+1] <= arr[i])
            dp[i][0] = min (dp[i][0], dp[i-1][1] + nv[i+1]);
        if (nv[i+1] - nv[i] <= arr[i])
            dp[i][0] = min (dp[i][0], dp[i-1][0] + nv[i+1]);
        if ((x - nv[i]) + (nv[i+1] - x) <= arr[i])
            dp[i][1] = min (dp[i][1], dp[i-1][1] + (x - nv[i+1]));
        dp[i][1] = min (dp[i][1], dp[i-1][0] + (x - nv[i+1]));
    }

    return min (dp[N-1][1], dp[N-1][0]);
}

int main()
{
    ios_base::sync_with_stdio(0);

    csum = 0;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        csum += arr[i];
    }

    vector <ll> v;
    for (ll i = 2; i < MAXN; i++)
    {
        if (csum % i == 0)
        {
            v.push_back(i);
            while (csum % i == 0)
                csum /= i;
        }
    }
    if (csum > 1)
        v.push_back(csum);


    ll ans = 3e18;
    for (ll f : v)
        ans = min (ans, gogo(f));
    if (ans > 2e18)
        cout << "-1\n";
    else
        cout << ans << "\n";
}