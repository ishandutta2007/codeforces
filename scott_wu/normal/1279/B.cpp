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
        int N; ll S;
        cin >> N >> S;

        int ans = 0, aloc = 0;
        ll ctot = 0, chi = 0;
        int cloc = 0;
        for (int i = 0; i < N; i++)
        {
            ll x; cin >> x;
            ctot += x;
            if (x > chi)
            {
                chi = x;
                cloc = i + 1;
            }

            if (ctot <= S)
            {
                if (ans < i + 1)
                {
                    ans = i + 1;
                    aloc = 0;
                }
            }
            if (ctot - chi <= S)
            {
                if (ans < i)
                {
                    ans = i;
                    aloc = cloc;
                }
            }
        }
        cout << aloc << "\n";
    }
}