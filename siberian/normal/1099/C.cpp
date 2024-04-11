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
int k;
void read()
{
    cin >> s >> k;
}
string ans = "";
void run()
{
    int cnt1 = 0;
    int cnt2 = 0;
    for (auto i : s)
    {
        if (i == '?')
            cnt1++;
        if (i == '*')
            cnt2++;
    }
    if (s.length() - 2 * cnt1 - 2 * cnt2 > k)
    {
        cout << "Impossible";
        exit(0);
    }
    if (cnt2 == 0 && s.length() - cnt1 < k)
    {
        cout << "Impossible";
        exit(0);
    }
    int len = s.length() - 2*cnt1 - 2*cnt2;
    bool flag = 0;
    if (cnt2 != 0)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != '?' && s[i] != '*')
            {
                if (i == s.length() - 1)
                    ans += s[i];
                else if ((s[i + 1] != '?' && s[i + 1] != '*'))
                    ans += s[i];
            }
            else if (s[i] == '*' && !flag)
            {
                flag = true;
                for (int jk = 0; jk < k - len; jk++)
                {
                    ans += s[i - 1];
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != '?' && s[i] != '*')
            {
                if (i == s.length() - 1)
                    ans += s[i];
                else if ((s[i + 1] != '?' && s[i + 1] != '*'))
                    ans += s[i];
            }
            else if (len != k)
            {
                len++;
                ans += s[i - 1];
            }
        }
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