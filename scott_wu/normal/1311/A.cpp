#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    for (int i = 0; i < T; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a == b)
            cout << "0\n";
        else if (a > b)
        {
            if ((a + b) % 2) cout << "2\n";
            else cout << "1\n";
        }
        else
        {
            if ((a + b) % 2) cout << "1\n";
            else cout << "2\n";
        }
    }
}