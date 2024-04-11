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
const int MAXN = 100100;
const ll MM = 1500000;

int N;
pair <int, int> ev[MAXN];
int ord[MAXN];
int res[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> ev[i].first >> ev[i].second;

    while (true)
    {
        for (int i = 0; i < N; i++)
            ord[i] = i;
        for (int i = 0; i < N; i++)
            swap (ord[i], ord[rand() % (i + 1)]);

        ll cx = 0, cy = 0;
        bool bad = false;
        for (int i = 0; i < N; i++)
        {
            int cloc = ord[i];
            ll xleft = cx + ev[cloc].first, yleft = cy + ev[cloc].second;
            ll xright = cx - ev[cloc].first, yright = cy - ev[cloc].second;
            if (xleft * xleft + yleft * yleft > xright * xright + yright * yright)
            {
                res[cloc] = -1;
                cx = xright;
                cy = yright;
            }
            else
            {
                res[cloc] = 1;
                cx = xleft;
                cy = yleft;
            }
        }
        if (cx * cx + cy * cy <= MM * MM)
        {
            break;
        }
    }
    for (int i = 0; i < N; i++)
        cout << res[i] << " ";
}