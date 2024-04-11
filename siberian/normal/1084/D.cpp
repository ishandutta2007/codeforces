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
const int MAXN = 3 * 1e5 + 10;
vector <pair <int, int> > g[MAXN];
int w[MAXN];
int n;
void read()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int v, u, cost;
        cin >> v >> u >> cost;
        v--;
        u--;
        g[v].push_back({ u, cost });
        g[u].push_back({ v, cost });
    }
}

int dp[MAXN][2];

void dfs(int v, int p)
{
    int best1 = 0;
    int best2 = 0;
    for (auto i : g[v])
    {
        if (i.first != p)
        {
            dfs(i.first, v);
            if (dp[i.first][0] - i.second > best2)
            {
                best2 = dp[i.first][0] - i.second;
                if (best1 < best2)
                {
                    swap(best1, best2);
                }
            }
        }
    }
    dp[v][1] = best1 + best2 + w[v];
    dp[v][0] = best1 + w[v];
}

int ans = 0;

void run()
{
    dfs(0, 0);
    for (int i = 0; i < n; i++)
    {
        ans = max(max(dp[i][0], dp[i][1]), ans);
    }
}

void write()
{
    cout << ans;
}

signed main()
{
    FAST;
    read();
    run();
    write();
    return 0;
}