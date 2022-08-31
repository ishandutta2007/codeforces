#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = 2600;
const ld PI = acos ((ld) -1.0);

int N;
ll x[MAXN], y[MAXN];

vector <ld> angs;

ll revolve (int ind)
{
    angs.clear();
    for (int i = 0; i < N; i++)
    {
        if (i == ind) continue;
        angs.push_back (atan2 ((ld) y[i] - y[ind], (ld) x[i] - x[ind]));
        angs.push_back (angs.back() + 2 * PI);
    }
    sort (angs.begin(), angs.end());

    int cend = 0;
    ll res = 0;
    for (int i = 0; i < angs.size() / 2; i++)
    {
        while (cend < angs.size() && angs[cend] < angs[i] + PI)
            cend++;

        ll nmore = cend - i - 1;
        res = res + (nmore * (nmore - 1) * (nmore - 2)) / 6;
    }
    //cout << ind << " " << res << "\n";
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> x[i] >> y[i];

    ll res = 0;
    for (int i = 0; i < N; i++)
        res += revolve (i);
    ll ntot = N * (ll) (N - 1) * (ll) (N - 2) * (ll) (N - 3) * (ll) (N - 4) / 24;
    cout << ntot - res << "\n";
}