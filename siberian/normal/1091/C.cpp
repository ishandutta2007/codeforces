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
vector <int> ans;
void run()
{
    set <int> x;
    for (int i = 1; i*i <= n; i++)
    {
        if (n % i == 0)
        {
            x.insert(i);
            x.insert(n / i);
        }
    }
    for (auto i : x)
    {
    //    cout << i << " ";
        ans.push_back(((i - 1)*n) / 2 + i);
    }
//    cout << endl;
}

void write()
{
    sort(ans.begin(), ans.end());
    for (auto i : ans)
    {
        cout << i <<  " ";
    }
}

signed main()
{
    FAST;
    read();
    run();
    write();
    return 0;
}