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
int t;
void read()
{
    cin >> t;
}

const int MOD = 998244353;
int cnt = 0;
vector <bool> used;
vector <vector <int> > g;
vector <int> color;
vector <pair <int, int> > p;
bool flag;
void dfs(int v, int c)
{
    used[v] = true;
    color[v] = c;
    if (c == 1)
    {
        p[cnt].first++;
    }
    else {
        p[cnt].second++;
    }
    for (auto j : g[v])
    {
        if (!used[j])
        {
            dfs(j, 3 - c);
        }
        if (used[j] && color[j] == c)
        {
            flag = true;
        }
    }
}

vector <int> ans;
const int MAXN = 3 * 1e5 + 10;
void run()
{
    vector <int> pows(MAXN);
    pows[0] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        pows[i] = pows[i - 1] * 2;
        pows[i] %= MOD;
    }
    for (int i = 0; i < t; i++)
    {
        int n, m;
        cin >> n >> m;
        g.assign(n, {});
        used.assign(n, 0);
        color.assign(n, 0);
        flag = false;
        for (int j = 0; j < m; j++)
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        cnt = 0;
        p.assign(n, { 0, 0 });
        for (int i = 0; i < n; i++)
        {
            if (!used[i])
            {
                dfs(i, 1);
                cnt++;
            }
        }
        if (flag)
        {
            ans.push_back(0);
        }
        else
        {
            int fans = 1;
            for (int k = 0; k < cnt; k++)
            {
                int ff;
                ff = pows[p[k].first] + pows[p[k].second];
                ff %= MOD;
                fans *= ff;
                fans %= MOD;
            }
            ans.push_back(fans);
        }
    }
}

void write()
{
    for (auto i : ans)
    {
        cout << i << endl;
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