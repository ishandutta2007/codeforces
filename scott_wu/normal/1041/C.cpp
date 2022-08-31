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

int N, M, D;
pair <int, int> a[MAXN];
int g[MAXN];
int ng;

int ans[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> M >> D;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort (a, a + N);

    int cg = 0;
    for (int i = 0; i < N; i++)
    {
        if (i <= cg || a[i].first - a[cg].first <= D)
        {
            g[i] = ng++;
        }
        else
        {
            g[i] = g[cg];
            cg++;
        }
    }

    for (int i = 0; i < N; i++)
        ans[a[i].second] = g[i];

    cout << ng << "\n";
    for (int i = 0; i < N; i++)
    {
        if (i) cout << " ";
        cout << ans[i] + 1;
    }
    cout << "\n";
}