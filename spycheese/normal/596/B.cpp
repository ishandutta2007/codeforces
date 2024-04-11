#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int IINF = 0x3f3f3f3f;
const int N = 200179;

int n;

int main()
{
    ios::sync_with_stdio(false);

    cin >> n;
    ll ans = 0, s = 0;
    for (int i = 0; i < n; ++i)
    {
        ll b;
        cin >> b;
        ans += abs(s - b);
        s = b;
    }
    cout << ans << "\n";

    return 0;
}