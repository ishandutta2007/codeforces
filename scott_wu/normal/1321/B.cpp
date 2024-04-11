#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
map <int, ll> mm;

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;
    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        int x; cin >> x;
        mm[x-i] += x;
        ans = max (ans, mm[x-i]);
    }
    cout << ans << "\n";
}