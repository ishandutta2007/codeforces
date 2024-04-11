#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    int count[n + 1];

    for(int i = 1; i <= n; ++i)
    {
        cin >> count[i];
    }
    int x, y;
    cin >> x >> y;

    int s1 = 0, s2 = accumulate(count + 1, count + n + 1, 0);

    for(int i = 1; i <= n; ++i)
    {
        s1 += count[i];
        s2 -= count[i];

        if (s1 >= x && s1 <= y && s2 >= x && s2 <= y)
        {
            cout << i + 1 << endl;
            return;
        }
    }
    cout << "0" << endl;

}

int main()
{
    solve();
    return 0;
}