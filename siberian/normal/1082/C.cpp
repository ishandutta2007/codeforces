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

int n, m;
vector <vector <int> > a;

bool cmp(vector <int> a, vector <int> b)
{
    return a.size() > b.size();
}

void read()
{
    cin >> n >> m;
    a.resize(m);
    for (int i = 0; i < n; i++)
    {
        int s, r;
        cin >> s >> r;
        s--;
        a[s].push_back(r);
    }

    for (int i = 0; i < m; i++)
    {
        sort(a[i].begin(), a[i].end());
        reverse(a[i].begin(), a[i].end());
    }
    sort(a.begin(), a.end(), cmp);

    for (int i = 0; i < m; i++)
    {
        for (int j = 1; j < a[i].size(); j++)
        {
            a[i][j] += a[i][j - 1];
        }
    }
}

int ans = 0;

void run()
{
    
    for (int i = 1; i <= n; i++)
    {
        vector <int> help;
        for (int j = 0; j < m; j++)
        {
            if (a[j].size() < i)
                break;
            help.push_back(a[j][i - 1]);
        }
        int loc = 0;
        sort(help.begin(), help.end());
        reverse(help.begin(), help.end());
        for (auto x : help)
        {
            if (x <= 0)
                break;
            loc += x;
        }
        ans = max(loc, ans);
    }
}

void write()
{
    cout << ans << endl;
}

signed main()
{
    FAST;
    read();
    run();
    write();
    return 0;
}