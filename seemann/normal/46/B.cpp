#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <utility>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>

using namespace std;

#define FOR(a, b) for (int a = 0; a < b; a++)
#define clr(a) memset(a, 0, sizeof(a))
#define ll long long
//define _in_s(a, b) (((a) < h)&&((a) >= 0)&&((b) < w)&&((b) >= 0))
map <string, int> f;
map <int, string> uf;
int a[5];
const int nx[5][5] = {{0, 1, 2, 3, 4}, {1, 2, 0, 3, 4},{2, 3, 1, 4, 0},{3, 4, 2, 1, 0},{4, 3, 2, 1, 0}};

int main()
{
    f["S"] = 0;
    f["M"] = 1;
    f["L"] = 2;
    f["XL"] = 3;
    f["XXL"] = 4;
    uf[0] = "S";
    uf[1] = "M";
    uf[2] = "L";
    uf[3] = "XL";
    uf[4] = "XXL";
    FOR(i, 5)
        cin >> a[i];

    int k;
    cin >> k;
    FOR(i, k)
    {
        string s;
        cin >> s;
        FOR(j, 5)
            if (a[nx[f[s]][j]] != 0)
            {
                cout << uf[nx[f[s]][j]] << '\n';
                a[nx[f[s]][j]]--;
                break;
            }

    }
    return 0;
}