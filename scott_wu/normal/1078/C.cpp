#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 300100;
const ll MOD = 998244353;

int N;
vector <int> edge[MAXN];

ll filled[MAXN];
ll need[MAXN];
ll solo[MAXN]; // single node

void flood (int cloc, int clast)
{
    vector <ll> n, f, s;
    vector <ll> p1, p2;
    for (int neigh : edge[cloc])
    {
        if (neigh == clast) continue;
        flood (neigh, cloc);

        n.push_back(need[neigh]);
        f.push_back(filled[neigh]);
        s.push_back(solo[neigh]);
    }

    solo[cloc] = 1;
    for (int i = 0; i < n.size(); i++)
    {
        solo[cloc] = (solo[cloc] * (f[i] + s[i])) % MOD;
    }
    need[cloc] = 1;
    for (int i = 0; i < n.size(); i++)
    {
        need[cloc] = (need[cloc] * (2 * f[i] + s[i])) % MOD;
    }
    need[cloc] = (need[cloc] - solo[cloc] + MOD) % MOD;

    p1.push_back(1);
    p2.push_back(1);
    for (int i = 0; i < n.size(); i++)
    {
        p1.push_back((p1.back() * (2 * f[i] + s[i])) % MOD);
        p2.push_back((p2.back() * (2 * f[n.size()-1-i] + s[n.size()-1-i])) % MOD);
    }

    filled[cloc] = 0;
    for (int i = 0; i < n.size(); i++)
    {
        ll nadd = ((n[i] + s[i]) * ((p1[i] * p2[n.size() - 1 - i]) % MOD)) % MOD;
        //cout << nadd << "\n";
        filled[cloc] = (filled[cloc] + nadd) % MOD;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    flood (0, -1);
    /*for (int i = 0; i < N; i++)
    {
        cout << need[i] << " " << filled[i] << " " << solo[i] << "\n";
    }*/
    cout << (filled[0] + solo[0]) % MOD << "\n";
}