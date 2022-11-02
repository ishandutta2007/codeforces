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
int T;
void read()
{
    cin >> T;
}

bool cmp(pair <pair <int, int>, int> a, pair <pair<int, int>, int> b)
{
    if (a.first.first == b.first.first)
    {
        if (a.first.second == b.first.second)
        {
            return a.second < b.second;
        }
        return a.first.second < b.first.second;
    }
    return a.first.first < b.first.first;
}

void run()
{
    for (int i = 0; i < T; i++)
    {
        int n;
        cin >> n;
        vector <pair <pair <int, int>, int> > x;
        for (int i = 0; i < n; i++)
        {
            int s, f;
            cin >> s >> f;
            x.push_back({ { s, 1 }, i });
            x.push_back({ { f, 2 }, i });
        }
        sort(x.begin(), x.end());
        int ans = -1;
        int last = -1;
        int cnt = 0;
        vector <int> fans;
        for (int i = 0; i < 2*n; i++)
        {
            if (x[i].first.second == 1)
            {
                cnt++;
                fans.push_back(x[i].second);
            }
            else
                cnt--;
            if (cnt == 0 && i != 2*n - 1)
            {
                ans = 1;
                break;
            }
        }
        if (ans == -1)
            cout << ans << endl;
        else
        {
            vector <int> help(n, 1);
            for (auto i : fans)
                help[i] = 2;
            for (int i = 0; i < n; i++)
            {
                cout << help[i] << " ";
            }
            cout << endl;
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