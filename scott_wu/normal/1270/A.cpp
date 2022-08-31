#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void gogo()
{
    int N, K1, K2;
    cin >> N >> K1 >> K2;

    int amax = 0, bmax = 0;
    for (int i = 0; i < K1; i++)
    {
        int x; cin >> x;
        amax = max (amax, x);
    }
    for (int i = 0; i < K2; i++)
    {
        int x; cin >> x;
        bmax = max (bmax, x);
    }

    if (amax > bmax)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}