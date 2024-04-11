#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;

    int ans = 0;
    for (int i = 0; i <= min (A, D); i++)
    {
        int ct = i * E + min (min (B, C), D - i) * F;
        ans = max (ans, ct);
    }
    cout << ans << "\n";
}