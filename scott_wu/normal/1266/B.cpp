#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
    {
        ll x; cin >> x;
        if (x > 14 && (x % 14 >= 1 && x % 14 <= 6))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}