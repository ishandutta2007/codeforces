#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);

    int R, C;
    cin >> R >> C;
    if (R == 1 && C == 1)
    {
        cout << "0\n";
        return 0;
    }

    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            if (j > 1) cout << " ";
            if (R > C) cout << (i + C) * j;
            else cout << i * (R + j);
        }
        cout << "\n";
    }
}