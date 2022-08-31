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
const int MAXN = 200100;

int N;
vector <int> edge[MAXN];
int ddep[MAXN], ssize[MAXN];

void flood (int cloc, int last)
{
    ssize[cloc] = 1;
    for (int neigh : edge[cloc])
    {
        if (neigh == last) continue;
        ddep[neigh] = ddep[cloc] + 1;
        flood (neigh, cloc);
        ssize[cloc] += ssize[neigh];
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
    ll nodd = 0;
    ll res = 0;
    for (int i = 1; i < N; i++)
    {
        res += ssize[i] * (ll) (N - ssize[i]);
        if (ddep[i] % 2 == 1)
            nodd++;
    }
    res += nodd * (ll) (N - nodd);
    cout << res / 2 << "\n";
}