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

int n, s;
vector <int> a;
int sum = 0, m = 1e10 + 10;
void read()
{
    cin >> n;
    cin >> s;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        m = min(m, a[i]);
    }
    if (sum < s)
    {
        cout << -1;
        exit(0);
    }
   // sort(a.begin(), a.end());
}

int ans = 0;

void run()
{
    s -= sum - n*m;
    ans = m;
    if (s <= 0)
        return;
    m = s / n;
    if (s % n)
     m++;
    ans -= m;
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