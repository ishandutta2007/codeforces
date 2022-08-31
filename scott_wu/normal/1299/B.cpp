#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N;
int x[MAXN], y[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> x[i] >> y[i];

    if (N % 2 == 1)
    {
        cout << "NO\n";
        return 0;
    }

    bool bad = false;
    for (int i = 0; i < N; i++)
    {
        int oloc = (i + N/2) % N;
        if (x[i] + x[oloc] != x[(i+1)%N] + x[(oloc+1)%N])
            bad = true;
        if (y[i] + y[oloc] != y[(i+1)%N] + y[(oloc+1)%N])
            bad = true;
    }
    if (bad)
        cout << "NO\n";
    else
        cout << "YES\n";
}