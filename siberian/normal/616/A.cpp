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
string s11, s21;
void read()
{
    cin >> s11 >> s21;
}
char ans = '=';
void run()
{
    string s1 = "", s2 = "";
    bool flag = false;
    for (int i = 0; i < s11.length(); i++)
    {
        if (s11[i] != '0')
            flag = true;
        if (flag)
            s1 += s11[i];
    }
    flag = false;
    for (int i = 0; i < s21.length(); i++)
    {
        if (s21[i] != '0')
            flag = true;
        if (flag)
            s2 += s21[i];
    }
    //cout << s1 << " " << s2;
    int n = s1.length();
    int m = s2.length();
    if (n < m)
    {
        ans = '<';
        return;
    }
    if (n > m)
    {
        ans = '>';
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (s1[i] > s2[i])
        {
            ans = '>';
            return;
        }
        if (s1[i] < s2[i])
        {
            ans = '<';
            return;
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