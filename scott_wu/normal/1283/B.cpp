#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int i = 0; i < T; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x % y > y / 2)
        {
            x -= (x % y);
            x += y / 2;
        }
        cout << x << "\n";
    }
}