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
int w, h;
int u1, d1, u2, d2;
void read()
{
    cin >> w >> h >> u1 >> d1 >> u2 >> d2;
}
int ans = 0;
void run()
{
    ans = w;
    h++;
    while (h--)
    {
        ans += h;
        if (h == d1)
            ans -= u1;
        if (h == d2)
            ans -= u2;
        ans = max(ans, 0LL);
    }
    ans = max(ans, 0LL);
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