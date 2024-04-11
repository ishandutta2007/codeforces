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

int N, S;
vector <int> edge[MAXN];
int deg[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    for (int i = 0; i < MAXN; i++)
    {
        deg[i] = 0;
    }

    cin >> N >> S;
    for (int i = 0; i < N - 1; i++)
    {
        int x, y; cin >> x >> y;
        x--, y--;
        edge[x].push_back(y);
        edge[y].push_back(x);

        deg[x]++;
        deg[y]++;
    }

    cout << fixed << setprecision(9);
    double ans;
    if (N == 2)
    {
        ans = S;
    }
    else
    {
        int nleaf = 0;
        for (int i = 0; i < N; i++)
            if (deg[i] == 1)
                nleaf++;
        ans = (double) S * (2. / nleaf);
    }
    cout << ans << "\n";
}