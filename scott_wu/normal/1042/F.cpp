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
const int MAXN = 2e6 + 100;

int N, K;
vector <int> edge[MAXN];
int mdep[MAXN];
int mpass[MAXN];
int ans;

void flood (int cloc, int last)
{
    mpass[cloc] = 0;
    mdep[cloc] = -1e7;

    bool leaf = true;
    for (int neigh : edge[cloc])
        if (neigh != last)
        {
            leaf = false;
            flood (neigh, cloc);
            mpass[cloc] = max (mpass[cloc], mpass[neigh] - 1);
        }
    if (leaf) mdep[cloc] = 0;

    for (int neigh : edge[cloc])
        if (neigh != last)
        {
            if (mdep[neigh] >= mpass[cloc])
                mdep[cloc] = max (mdep[cloc], mdep[neigh] + 1);
        }
    if (mdep[cloc] == K)
    {
        mdep[cloc] = -1e7;
        mpass[cloc] = K;
        ans++;
    }
    if (last == -1 && mdep[cloc] > 0)
        ans++;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> N >> K;
    int nnew = N;
    for (int i = 0; i < N - 1; i++)
    {
        int a, b; cin >> a >> b;
        a--, b--;
        edge[a].push_back(nnew);
        edge[b].push_back(nnew);
        edge[nnew].push_back(a);
        edge[nnew].push_back(b);
        nnew++;
    }

    N = nnew;
    flood (N - 1, -1);
    cout << ans << "\n";
}