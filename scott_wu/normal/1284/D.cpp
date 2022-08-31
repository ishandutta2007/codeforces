#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 100100;
const ll MOD = 1e9 + 7;

int N;
pair <int, int> pp[2][MAXN];
pair <int, int> cv[MAXN];
ll mv[MAXN];

vector <pair <ll, ll> > event;

ll gogo()
{
    event.clear();
    for (int i = 0; i < N; i++)
    {
        event.push_back(make_pair(2*cv[i].first, mv[i]));
        event.push_back(make_pair(2*cv[i].second+1, -mv[i]));
    }

    sort (event.begin(), event.end());

    ll res = 0;
    ll ctot = 0;
    for (auto ppair : event)
    {
        ll cz = ppair.second;
        if (cz > 0)
            ctot += cz;
        else
        {
            ctot = (ctot + MOD + cz) % MOD;
            res = (res + (ctot * -cz)) % MOD;
        }

        ctot = (ctot % MOD + MOD) % MOD;
    }
    return (res % MOD + MOD) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> pp[0][i].first >> pp[0][i].second >> pp[1][i].first >> pp[1][i].second;
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < N; j++)
            mv[j] = rng();

        for (int j = 0; j < N; j++)
            cv[j] = pp[0][j];
        ll res = gogo();
        for (int j = 0; j < N; j++)
            cv[j] = pp[1][j];
        ll res2 = gogo();

        if (res != res2)
        {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}