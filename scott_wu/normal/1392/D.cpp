#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
string S;

void gogo()
{
    cin >> N;
    cin >> S;

    bool bad = true;
    for (int i = 0; i < N - 1; i++)
        if (S[i] != S[i+1])
            bad = false;

    if (bad)
    {
        cout << (N + 2) / 3 << "\n";
        return;
    }

    int cend = N;
    while (S[0] == S[cend-1])
        cend--;

    int cc = N - cend, ans = 0;
    for (int i = 0; i < cend; i++)
    {
        if (i == 0 || S[i] == S[i-1])
            cc++;
        else
        {
            ans += cc / 3;
            cc = 1;
        }
    }
    ans += cc / 3;
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
    {
        gogo();
    }
}