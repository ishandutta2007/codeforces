#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N;
int cost[MAXN];
int nval[MAXN];
int seen[MAXN];
int ans;

int nround;

void flood (int cloc)
{
    if (seen[cloc] == nround)
    {
        int np = nval[cloc];
        int res = 1e9;
        while (true)
        {
            res = min (res, cost[np]);
            if (np == cloc) break;
            np = nval[np];
        }
        ans += res;
        return;
    }
    if (seen[cloc])
        return;
    seen[cloc] = nround;
    flood (nval[cloc]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> cost[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> nval[i];
        nval[i]--;
    }

    for (int i = 0; i < N; i++)
    {
        nround++;
        flood (i);
    }
    cout << ans << "\n";
}