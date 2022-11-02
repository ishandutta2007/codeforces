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

void read()
{
    cin >> n;
}

vector <int> ans;

void run()
{
    map <int, int> a;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            a[x]++;
        }
    }

    int m = 0;
    for (auto i : a)
    {
        m = max(i.second, m);
    }
    for (auto i : a)
    {
        if (i.second == m)
        {
            ans.push_back(i.first);
        }
    }
}

void write()
{
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