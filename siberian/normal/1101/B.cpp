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
void read()
{
    cin >> s;
}
int ans;
void run()
{
    int n = s.length();
    int pos1 = -1;
    int pos2 = -1;
    int pos3 = -1;
    int pos4 = -1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '[')
        {
            pos1 = i;
            break;
        }
    }
    for (int i = pos1 + 1; i < n; i++)
    {
        if (s[i] == ':')
        {
            pos2 = i;
            break;
        }
    }
    for (int i = n - 1; i > pos1; i--)
    {
        if (s[i] == ']')
        {
            pos3 = i;
            break;
        }
    }
    for (int i = pos3 - 1; i > pos2; i--)
    {
        if (s[i] == ':')
        {
            pos4 = i;
            break;
        }
    }

    if ((pos1 == -1 || pos2 == -1 || pos3 == -1 || pos4 == -1) || (pos2 == pos4))
    {
        cout << -1;
        exit(0);
    }
    ans = 4;
    for (int i = pos2 + 1; i < pos4; i++)
    {
        if (s[i] == '|')
            ans++; 
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