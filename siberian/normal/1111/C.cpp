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

int n, k, a, b;
vector <int> pos;

void read()
{
    cin >> n >> k >> a >> b;
    pos.resize(k);
    for (int i = 0; i < k; i++)
    {
        cin >> pos[i];
    }
    sort(pos.begin(), pos.end());
}

int cnt(int l, int r)
{
    auto it = lower_bound(pos.begin(), pos.end(), l);
    auto it2 = upper_bound(pos.begin(), pos.end(), r);
    if (it == pos.end())
        return 0;
    if (it2 == pos.begin())
        return 0;
    int ans = it2 - it;
    return max(0LL, ans);

}

int cost(int l, int r)
{
    if (cnt(l, r) == 0)
        return a;
    if (r == l)
        return b*cnt(l, r);
    int ans;
    ans = min(cnt(l, r)*(r - l + 1)*b, cost(l, (r + l) / 2) + cost((r + l) / 2 + 1, r));
    return ans;
}

int ans;

void run()
{
    ans = cost(1, pow(2, n));
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