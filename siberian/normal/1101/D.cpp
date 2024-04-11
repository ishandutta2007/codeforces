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

//#define int long long
const int MAXN = 2 * 1e5 + 10;
int val[MAXN];
vector <int> g[MAXN];
int n;
void read()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
}


int ans;
vector <pair <int, int> > dp[MAXN];
int fans[MAXN];

void dfs(int v, int p)
{
    for (auto i : g[v])
    {
        if (i != p)
            dfs(i, v);
    }

    int x = val[v];
    for (int i = 2; i*i <= x; i++)
    {
        if (x % i == 0)
        {
            dp[v].push_back({i, 1});
        }
        while (x % i == 0)
            x /= i;
    }
    if (x != 1)
        dp[v].push_back({x, 1});

    map <int, pair <int, int> > help;
    for (auto i : g[v])
    {
        if (i != p)
        {
            for (auto j : dp[i])
            {
                if (j.second > help[j.first].second)
                {
                    help[j.first].second = j.second;
                    if (help[j.first].first < help[j.first].second)
                        swap(help[j.first].first, help[j.first].second);
                }
            }
        }
    }

    for (int x = 0; x < dp[v].size(); x++)
    {
        auto i = dp[v][x];
        if (help[i.first].first != 0)
        {
            ans = max(ans, help[i.first].first + help[i.first].second + 1);
            dp[v][x].second += help[i.first].first;
        }
        else
        {
            ans = max(ans, 1);
        }
    }
}

void run()
{
    ans = 0;
    dfs(0, 0);
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