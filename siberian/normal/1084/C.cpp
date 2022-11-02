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
string s;
int n;
const int MOD = 1e9 + 7;
void read()
{
    cin >> s;
    n = s.size();
}
const int MAXN = 1e5 + 10;
int dp[MAXN][2];
int ans = 0;
void run()
{
    for (int i = 1; i <= n; i++)
    {
        dp[i][1] = dp[i - 1][1];
        dp[i][0] += dp[i - 1][0];

        if (s[i - 1] == 'a')
        {
            dp[i][0] += 1;
            dp[i][0] += dp[dp[i][1]][0];
            dp[i][0] %= MOD;
        }

        if (s[i - 1] == 'b')
        {
            dp[i][1] = i;
        }
    }
    ans = dp[n][0];
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