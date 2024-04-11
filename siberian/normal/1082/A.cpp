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

void read()
{

}

void run()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, x, y, d;
        cin >> n >> x >> y >> d;

        int ans = 1e9;

        if (abs(x - y) % d == 0)
        {
            int ans1 = 0;
            ans1 += abs(x - y) / d;
            ans = min(ans1, ans);
        }

        if (abs(n - y) % d == 0)
        {
            int ans1 = 0;
            ans1 += abs(n - x) / d;
            if (abs(n - x) % d != 0)
                ans1++;
            ans1 += abs(n - y) / d;
            ans = min(ans1, ans);
        }

        if (abs(y - 1) % d == 0)
        {
            int ans1 = 0;
            ans1 += abs(x - 1) / d;
            if (abs(x - 1) % d != 0)
                ans1++;
            ans1 += abs(y - 1) / d;
            ans = min(ans1, ans);
        }
        if (ans == 1e9)
            ans = -1;
        cout << ans << endl;
    }
}

void write()
{

}

signed main()
{
    FAST;
    read();
    run();
    write();
    return 0;
}