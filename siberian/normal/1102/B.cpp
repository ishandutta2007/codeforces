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
int n, k;
vector <pair <int, int> > a;
void read()
{
    cin >> n >> k;
    a.resize(n);
    map <int, int> fx;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
        fx[a[i].first]++;
    }
    for (auto i : fx) {
        if (i.second > k)
        {
            cout << "NO\n";
            exit(0);
        }
    }
    sort(a.begin(), a.end());
}
vector <int> ans;
void run()
{
    ans.resize(n);
    for (int i = 0; i < n; i++)
    {
        ans[a[i].second] = i % k + 1;
    }
}

void write()
{
    cout << "YES\n";
    for (auto i : ans)
        cout << i << " ";
}

signed main()
{
    FAST;
    read();
    run();
    write();
    return 0;
}