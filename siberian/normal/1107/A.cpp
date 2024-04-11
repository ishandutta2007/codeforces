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
int q;
void read()
{
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        string s;
        cin >> s;
        if (x == 2 && s[0] >= s[1])
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
            cout << 2 << endl;
            cout << s[0] << " ";
            for (int j = 1; j < x; j++)
                cout << s[j];
            cout << endl;
        }
    }

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