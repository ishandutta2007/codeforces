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
int n;
void read()
{
    cin >> n;
}

void run()
{
    int maxH = -1;
    int maxW = -1;
    for (int i = 0; i < n; i++)
    { 
        char x;
        cin >> x;
        if (x == '+')
        {
            int a, b;
            cin >> a >> b;
            if (a > b)
                swap(a, b);
            maxH = max(maxH, a);
            maxW = max(maxW, b);
        }
        else
        {
            int h, w;
            cin >> h >> w;
            if (h > w)
                swap(h, w);
            if (h >= maxH && w >= maxW)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
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