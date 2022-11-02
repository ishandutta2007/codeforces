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
set<char> lett = { 'a', 'e', 'i', 'o', 'u' };
string s, t;
void read()
{
    cin >> s >> t;
    if (s.length() != t.length())
    {
        cout << "No";
        exit(0);
    }
    bool f1 = true;
    bool f2 = false;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == t[i])
            continue;
        if (lett.find(s[i]) != lett.end() && lett.find(t[i]) != lett.end())
        {
            continue;
        }
        if (lett.find(s[i]) == lett.end() && lett.find(t[i]) == lett.end())
        {
            continue;
        }
        cout << "No";
        exit(0);
    }
    cout << "Yes";
}

void run()
{

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