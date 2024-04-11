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
int n, m;
int ans = 0;
void read()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int fans = 1e10;
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            fans = min(x, fans);
        }
        ans = max(ans, fans);
    }
}

void run()
{

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