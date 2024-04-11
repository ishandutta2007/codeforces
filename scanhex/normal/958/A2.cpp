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

const int M = 1791791791;
const int B = 239;

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <string> a(n), b(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    map <int, int> ans;
    for (int i = 0; i + m - 1 < n; i++)
    {
        int kek = 0;
        for (int x = i; x <= i + m - 1; x++)
        {
            for (int y = 0; y < m; y++)
            {
                kek = (kek * (ll) B + a[x][y]) % M;
            }
        }
        ans[kek] = i;
    }
    for (int j = 0; j + m - 1 < n; j++)
    {
        int kek = 0;
        for (int x = 0; x < m; x++)
        {
            for (int y = j; y <= j + m - 1; y++)
            {
                kek = (kek * (ll) B + b[x][y]) % M;
            }
        }
        if (ans.count(kek))
        {
            cout << ans[kek] + 1 << ' ' << j + 1 << '\n';
            return 0;
        }
    }
}