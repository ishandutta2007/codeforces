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

using namespace std;
#define FAST ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr)

//#define int long long


int n;
void read()
{
    cin >> n;
}
int ans1, ans2;
void run()
{
    if (n == 1)
    {
        ans1 = 1;
        ans2 = 0;
        return;
    }
    vector <int> a;
    int x = n;
    ans1 = 1;
    for (int i = 2; i <= n; i++)
    {
        int y = 0;
        while (x % i == 0)
        {
            x /= i;
            y++;
        }
        if (y != 0)
        {
            a.push_back(y);
            ans1 *= i;
        }
    }

    bool flag = true;
    for (auto i : a)
    {
        if (i != 1)
            flag = false;
    }
    if (flag)
    {
        ans1 = n;
        ans2 = 0;
        return;
    }
    ans2 = 0;
    for (auto i : a)
    {
        int p = 0;
        int x = 1;
        while (x < i)
        {
            x *= 2;
            p++;
        }
        ans2 = max(p, ans2);
    }

    flag = true;
    int abs = a[0];
    for (auto i : a)
    {
        if (i != abs)
            flag = false;
    }
    int pos = 1;
    while (pos < abs)
    {
        pos *= 2;
    }
    if (pos != abs)
        flag = false;
    if (!flag)
     ans2++;
}

void write()
{
    cout << ans1 << " " << ans2 << endl;
}

signed main()
{
    FAST;
   // while (true)
   // {
        read();
        run();
        write();
    //}
    return 0;
}