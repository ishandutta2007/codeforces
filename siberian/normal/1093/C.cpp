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
vector <int> a;
vector <int> b;
void read()
{
    cin >> n;
    b.resize(n / 2);
    for (int i = 0; i < n / 2; i++)
    {
        cin >> b[i];
    }
}

void run()
{
    a.resize(n);
    a[0] = 0;
    a[n - 1] = b[0];
    for (int i = 1; i < n / 2; i++)
    {
        a[i] = a[i - 1];
        b[i] -= a[i];
        a[n - i - 1] = min(a[n - i], b[i]);
        b[i] -= a[n - i - 1];
        if (b[i] > 0)
        {
            a[i] += b[i];
        }
    }
}

void write()
{
    for (auto i : a)
    {
        cout << i << " ";
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