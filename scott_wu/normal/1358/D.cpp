#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 400100;

int N;
ll X;
ll arr[MAXN];

ll calc (ll p)
{
    return (p * (p + 1)) / 2;
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N >> X;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        arr[i+N] = arr[i];
    }

    ll ctot = 0;
    ll tscore = 0;
    int cend = 0;
    ll ans = 0;
    for (int i = 0; i < 2 * N; i++)
    {
        ctot += arr[i];
        tscore += calc (arr[i]);
        while (ctot - arr[cend] >= X)
        {
            ctot -= arr[cend];
            tscore -= calc (arr[cend]);
            cend++;
        }

        if (ctot >= X)
            ans = max (ans, tscore - calc (ctot - X));
    }
    cout << ans << "\n";
}