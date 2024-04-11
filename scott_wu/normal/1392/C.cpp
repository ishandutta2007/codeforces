#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void gogo()
{
    int N; cin >> N;

    ll ans = 0, p = -1e9;
    for (int i = 0; i < N; i++)
    {
        ll x; cin >> x;
        if (x < p)
            ans += p - x;
        p = x;
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
    {
        gogo();
    }
}