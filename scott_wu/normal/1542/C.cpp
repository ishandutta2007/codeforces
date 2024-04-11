#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

ll gcd (ll a, ll b)
{
    if (b == 0) return a;
    return gcd (b, a % b);
}

void gogo()
{
    ll N;
    cin >> N;

    ll res = N;

    ll tt = 1;
    for (int i = 1; i <= 50; i++)
    {
        ll v = gcd (tt, i);
        tt = (tt / v * i);
        if (tt > N) break;
        res += N / tt;
    }
    cout << (res % MOD) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}