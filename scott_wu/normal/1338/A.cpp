#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void gogo()
{
    int N; cin >> N;
    vector <ll> v(N);

    ll vhi = -2e9, vdiff = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
        vhi = max (vhi, v[i]);
        vdiff = max (vdiff, vhi - v[i]);
    }

    if (!vdiff)
    {
        cout << "0\n";
    }
    else
    {
        int ans = 1;
        while ((1LL << ans) - 1 < vdiff)
            ans++;
        cout << ans << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}