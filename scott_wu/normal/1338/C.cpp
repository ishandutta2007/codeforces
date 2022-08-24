#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void gogo()
{
    ll N; cin >> N;
    N--;

    ll vm = N % 3;
    N /= 3;

    ll cmult = 1;
    while (N >= cmult)
    {
        N -= cmult;
        cmult *= 4;
    }

    ll A = N + cmult, B = 2 * cmult;

    ll cx = 1;
    while (cx < cmult)
    {
        ll v = N % 4;
        if (v)
            B += cx * ((v % 3) + 1);

        cx *= 4;
        N /= 4;
    }

    if (vm == 0)
        cout << A;
    else if (vm == 1)
        cout << B;
    else
        cout << (A^B);
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}