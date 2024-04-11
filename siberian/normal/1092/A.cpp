#include <bits/stdc++.h>

using namespace std;

void run()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        char a = 'a' + i % k;
        cout << a;
    }
    cout << endl;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
        run();
    return 0;
}