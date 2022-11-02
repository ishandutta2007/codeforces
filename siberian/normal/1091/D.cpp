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
const int MOD = 998244353;
const int MAXN = 1e6 + 10;
int fact[MAXN];

void read()
{
    cin >> n;
}

int ans = 0;
int fact2[MAXN];
void run()
{
    fact2[n] = n;
    for (int i = n - 1; i >= 1; i--)
    {
        fact2[i] = i * fact2[i + 1];
        fact2[i] %= MOD;
    }
    
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fact[i] = i * fact[i - 1];
        fact[i] %= MOD;
    }
    ans += fact[n];
    
    for (int i = 2; i < n; i++)
    {
        ans += (fact[i] - 1) * fact2[i + 1];
        ans %= MOD;
    }
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