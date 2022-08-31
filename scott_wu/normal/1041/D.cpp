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

int N, H;
ll xstart[MAXN], xend[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> H;
    for (int i = 0; i < N; i++)
        cin >> xstart[i] >> xend[i];
    xstart[N] = xend[N] = 2e9;
    N++;

    int cloc = 0;
    ll cq = 0, ans = 0;
    for (int i = 0; i < N; i++)
    {
        while (xstart[i] - xstart[cloc] - cq >= H)
        {
            cq -= (xend[cloc] - xstart[cloc]);
            cloc++;
        }
        cq += xend[i] - xstart[i];
        ans = max (ans, cq);
    }
    cout << ans + H << "\n";
}