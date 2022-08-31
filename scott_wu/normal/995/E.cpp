#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;

int U, V, P;

ll cpow (ll x, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return x;
    ll l = cpow (x, b / 2);
    l = (l * l) % P;
    if (b % 2 == 1)
        l = (l * x) % P;
    return l;
}

ll inv (ll x)
{
    return cpow (x % P, P - 2);
}

map <int, int> mlast;
vector <int> q, v;

int bfs()
{
    q.push_back(U);
    q.push_back(V+P);
    mlast[U] = -1;
    mlast[V+P] = -1;

    for (int i = 0; i < q.size(); i++)
    {
        int cloc = q[i] % P, ct = q[i] / P;
        v.clear();
        v.push_back((inv(cloc)));
        v.push_back((cloc + 1) % P);
        v.push_back((cloc + P - 1) % P);

        for (int j = 0; j < v.size(); j++)
        {
            int neigh = v[j] + ct * P;
            if (mlast.find(neigh) == mlast.end())
            {
                mlast[neigh] = j;
                q.push_back(neigh);
                if (mlast.find(v[j] + (1 - ct) * P) != mlast.end())
                {
                    return v[j];
                }
            }
        }
    }
    return -1;
}

vector <int> ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> U >> V >> P;
    int c = bfs();
    int cc = c;

    while (c != U)
    {
        ans.push_back (mlast[c]);
        if (mlast[c] == 0)
            c = inv(c);
        else if (mlast[c] == 1)
            c = (c + P - 1) % P;
        else
            c = (c + 1) % P;
    }
    reverse (ans.begin(), ans.end());

    c = cc;
    while (c != V)
    {
        ans.push_back (3 - mlast[c+P]);
        if (mlast[c+P] == 0)
            c = inv(c);
        else if (mlast[c+P] == 1)
            c = (c + P - 1) % P;
        else
            c = (c + 1) % P;
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i]) cout << ans[i];
        else cout << ans[i] + 3;
        cout << " ";
    }
}