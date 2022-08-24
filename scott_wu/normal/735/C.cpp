#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main()
{
    ios_base::sync_with_stdio(0);

    ll N; cin >> N;

    ll r1 = 1, r2 = 2;
    ll ans = 0;
    while (r2 <= N)
    {
        ans++;
        r2 = r2 + r1;
        r1 = r2 - r1;
    }
    cout << ans << "\n";
}