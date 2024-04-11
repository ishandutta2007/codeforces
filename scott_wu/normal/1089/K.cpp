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
const int P = (1 << 20);
const int MAXP = 2 * P + 100;
const int MAXN = 300100;

int Q;
ll seg[MAXP];
ll rmin[MAXP];

int t[MAXN], d[MAXN];

void upd (int cloc, int cv)
{
    cloc += P;
    seg[cloc] += cv;
    rmin[cloc] += cv;
    while (cloc > 1)
    {
        cloc /= 2;
        rmin[cloc] = min (rmin[2*cloc], seg[2*cloc] + rmin[2*cloc+1]);
        seg[cloc] += cv;
    }
}

ll query (int x)
{
    int cloc = x + P + 1;
    ll ct = 0;
    while (cloc > 1)
    {
        if (cloc & 1)
        {
            ct += seg[cloc-1];
        }
        cloc /= 2;
    }

    ll cans = 0;
    cloc = x + P;
    while (cloc > 1)
    {
        if (cloc & 1)
        {
            cans += seg[cloc-1];
            cans = min (cans, rmin[cloc-1]);
        }
        cloc /= 2;
    }
    return ct - cans + 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    for (int i = 0; i <= 1000100; i++)
        upd (i, -1);

    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        char c; cin >> c;
        cin >> t[i];
        if (c == '?')
        {
            cout << query (t[i]) << "\n";
        }
        else if (c == '+')
        {
            cin >> d[i];
            upd (t[i], d[i]);
        }
        else
        {
            t[i]--;
            upd (t[t[i]], -d[t[i]]);
        }
    }
}