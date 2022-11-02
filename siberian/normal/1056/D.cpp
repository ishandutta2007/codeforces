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

int n;
vector <vector <int> > g;
vector <int> cnt;
vector <bool> used;

void dfs(int v)
{
    used[v] = true;
    bool flag = true;
    for (auto u : g[v])
    {
        if (!used[u])
        {
            flag = false;
            dfs(u);
            cnt[v] += cnt[u];
        }
    }
    if (flag)
        cnt[v] = 1;
}

void read()
{
    cin >> n;
    g.resize(n);
    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;
        x--;
        g[x].push_back(i);
        g[i].push_back(x);
    }
}

void run()
{
    cnt.assign(n, 0);
    used.assign(n, false);
    dfs(0);
    sort(cnt.begin(), cnt.end());
}

void write()
{
    for (int i = 0; i < n; i++)
        cout << cnt[i] << " ";
}

signed main()
{
    FAST;
    read();
    run();
    write();
    return 0;
}