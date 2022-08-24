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
        cout << 1440 - 60 * x - y << "\n";
    }
}