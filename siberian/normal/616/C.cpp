#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops") 
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <stdio.h>

using namespace std;
#define FAST ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr)

#define int long long
const int MAXN = 1e3 + 10;
char dp[MAXN][MAXN];
int color[MAXN][MAXN];
int cnt[MAXN*MAXN];
int n, m;
void read()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> dp[i][j];
        }
    }
}
bool used[MAXN][MAXN];
void go(int i, int j, int c)
{
    used[i][j] = true;
    color[i][j] = c;
    cnt[c]++;
    if (dp[i - 1][j] == '.' && !used[i - 1][j])
    {
        go(i - 1, j, c);
    }
    if (dp[i + 1][j] == '.' && !used[i + 1][j])
    {
        go(i + 1, j, c);
    }
    if (dp[i][j - 1] == '.' && !used[i][j - 1])
    {
        go(i, j - 1, c);
    }
    if (dp[i][j + 1] == '.' && !used[i][j + 1])
    {
        go(i, j + 1, c);
    }
}
char ans[MAXN][MAXN];
void run()
{
    int col = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (dp[i][j] == '.' && !used[i][j])
            {
                go(i, j, col);
                col++;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            ans[i][j] = '.';
            if (dp[i][j] == '*')
            {
                set<int> cols;
                cols.insert(color[i - 1][j]);
                cols.insert(color[i + 1][j]);
                cols.insert(color[i][j - 1]);
                cols.insert(color[i][j + 1]);
                ans[i][j] = '0';
                int hue = 1;
                for (auto k : cols)
                {

                    hue += cnt[k];
                }
                ans[i][j] += hue % 10;
            }
        }
    }
}

void write()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << ans[i][j];
        }
        cout << endl;
    }
}

signed main()
{
    FAST;
    read();
    run();
    write();
    return 0;
}