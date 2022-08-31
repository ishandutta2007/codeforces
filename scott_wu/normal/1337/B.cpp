#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
    {
        int x, n, m;
        cin >> x >> n >> m;
        for (int i = 0; i < n; i++)
            if (x > 20)
                x = (x / 2) + 10;
        if (x <= 10 * m) cout << "YES\n";
        else cout << "NO\n";
    }
}