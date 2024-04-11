#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, K;
string s;

void gogo()
{
    cin >> N >> K;
    cin >> s;

    set <ll> ss;
    for (int i = 0; i < N; i++)
    {
        if (s[i] == '1') ss.insert(i);
    }
    ss.insert(-1e10);
    ss.insert(1e10);

    for (int i = 0; i < N; i++)
    {
        auto it = ss.lower_bound(i);
        ll v = *it;
        it--;
        ll v2 = *it;

        ll d1 = (i - v2), d2 = (v - i);
        if (d1 != d2 && min (d1, d2) <= (ll) K)
            cout << 1;
        else
            cout << 0;
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}