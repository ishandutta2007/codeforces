#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);

    int T = 0;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        ll A, B, C;
        cin >> A >> B >> C;
        int m = max (max (A, B), C);
        if (m * 2 > A + B + C + 1)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
}