#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXM = 200100;

int N;
int nf[MAXM];

ll gcf (ll a, ll b)
{
    if (b == 0) return a;
    return gcf (b, a % b);
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a; cin >> a;
        for (int j = 1; j * j <= a; j++)
        {
            if (a % j) continue;
            nf[j]++;
            if (j * j < a)
                nf[a/j]++;
        }
    }

    ll res = 1;
    for (int i = 1; i < MAXM; i++)
    {
        if (nf[i] >= N - 1)
        {
            ll g = gcf (res, i);
            res = (res / g) * i;
        }
    }
    cout << res << "\n";
}