#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
    {
        int x, y;
        cin >> x >> y;
        cout << (x * y + 1) / 2 << "\n";
    }
}