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
string s;

void read()
{
    cin >> n;
    cin >> s;
}

int ans = 0;

int dp[100010][2];

void run()
{
    for (int i = 1; i <= n; i++)
    {
        if (s[i - 1] == 'G')
        {
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][1] = dp[i - 1][1] + 1;
            ans = max(ans, max(dp[i][0], dp[i][1]));
        }
        else
        {
            dp[i][0] = 0;
            dp[i][1] = dp[i - 1][0] + 1;
            ans = max(ans, max(dp[i][0], dp[i][1]));
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == 'G')
            cnt++;
    ans = min(ans, cnt);
}

void write()
{
    cout << ans << endl;
    ans = 0;
}

signed main()
{
    FAST;
    //while (true)
    //{
        read();
        run();
        write();
    //}
    return 0;
}