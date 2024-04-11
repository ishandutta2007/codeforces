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
const int MAXP = (1 << 22) + 100;

int N, M;
int par[MAXP];
bool has[MAXP];
bool dive[MAXP];
int arr[MAXP];

int ufind (int x)
{
    if (x == par[x])
        return x;
    return par[x] = ufind(par[x]);
}

void uni (int x, int y)
{
    par[ufind(x)] = ufind(y);
}

set <int> res;

void flood (int cloc)
{
    if (dive[cloc] || !has[cloc])
        return;
    dive[cloc] = true;
    for (int i = 0; i < N; i++)
    {
        if (cloc & (1 << i))
        {
            int neigh = cloc - (1 << i);
            if (!dive[neigh])
            {
                flood (neigh);
            }
            if (has[neigh])
            {
                uni (cloc, neigh);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    for (int i = 0; i < MAXP; i++)
    {
        par[i] = i;
        dive[i] = false;
    }

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < MAXP; i++)
    {
        has[i] = false;
    }
    for (int i = 0; i < M; i++)
        has[arr[i]] = true;

    for (int i = 0; i < (1 << N); i++)
    {
        if (has[i])
        {
            for (int j = 0; j < N; j++)
            {
                has[i | (1 << j)] = true;
            }
        }
    }

    int tot = (1 << N) - 1;
    for (int i = 0; i < M; i++)
    {
        if (has[tot - arr[i]])
        {
            flood (tot - arr[i]);
            uni (arr[i], tot - arr[i]);
        }
    }

    for (int i = 0; i < M; i++)
    {
        res.insert(ufind(arr[i]));
    }
    cout << res.size() << "\n";
}