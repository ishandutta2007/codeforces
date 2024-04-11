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
int n;
vector <pair <int, int> > a, b;

void read()
{
    cin >> n;
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i].first >> b[i].second;
    }
}

pair <int, int> ans;

void run()
{
    ans.first = 0;
    ans.second = 0;
    for (int i = 0; i < n; i++)
    {
        ans.first += a[i].first;
        ans.first += b[i].first;
        ans.second += a[i].second;
        ans.second += b[i].second;
    }
    ans.first /= n;
    ans.second /= n;
}

void write()
{
    cout << ans.first << " " << ans.second;
}

signed main()
{
    FAST;
    read();
    run();
    write();
    return 0;
}