#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll v[3];

int main()
{
    ios_base::sync_with_stdio(0);

    for (int i = 0; i < 3; i++)
        cin >> v[i];
    cout << "First\n" << flush;

    ll a = 1e10;
    cout << a << "\n" << flush;

    int res; cin >> res;
    res--;
    v[res] += a;

    ll hi = v[res];
    ll ct = 0;
    for (int i = 0; i < 3; i++)
        ct += hi - v[i];

    cout << ct << "\n" << flush;
    cin >> res;
    res--;
    v[res] += ct;
    hi = v[res];
    ct = 1e12;
    for (int i = 0; i < 3; i++)
        if (hi != v[i])
            ct = min (ct, hi - v[i]);
    cout << ct << "\n" << flush;

    int x; cin >> x;
    return 0;
}