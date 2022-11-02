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
const int MAXM = 1010;
void read()
{
    cin >> n >> m;
}
int ans = 0;
int dp[MAXM][MAXM];
void run()
{
    int cnt1 = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = i * i + j * j;
//            cout << dp[i][j] << " ";

            dp[i][j] %= m;
            
            if (dp[i][j] == 0)
                cnt1++;
            
        }
     //   cout << endl;
    }
    int cnt2 = 0;
    int cnt3 = 0;
    for (int i = 1; i <= n % m; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (dp[i][j] == 0)
                cnt2++;
        }
    }

    for (int i = 1; i <= n % m; i++)
    {
        for (int j = 1; j <= n % m; j++)
        {
            if (dp[i][j] == 0)
                cnt3++;
        }
    }

    ans = 0;
    ans += (n / m)*(n / m) * cnt1;
    ans += (n / m) * cnt2 * 2;
    if (n % m != 0)
        ans += cnt3;
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