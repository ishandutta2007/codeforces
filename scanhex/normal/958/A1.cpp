#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <iomanip>
#include <bitset>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n;
    cin >> n;
    vector <string> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (int sw_x = 0; sw_x < 2; sw_x++)
    {
        for (int sw_y = 0; sw_y < 2; sw_y++)
        {
            for (int swp = 0; swp < 2; swp++)
            {
                bool bad = false;
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        int x = (sw_x ? n - 1 - i : i);
                        int y = (sw_y ? n - 1 - j : j);
                        if (swp) swap(x, y);
                        if (a[i][j] != b[x][y])
                        {
                            bad = true;
                        }
                    }
                }
                if (!bad)
                {
                    cout << "Yes\n";
                    return 0;
                }
            }
        }
    }
    cout << "No\n";
}