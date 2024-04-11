#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void gogo()
{
    int a, b;
    cin >> a >> b;
    if (a < b) swap (a, b);
    if (a < 2 * b) a = 2 * b;
    cout << a * a << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    while (T--)
    {
        gogo();
    }
}