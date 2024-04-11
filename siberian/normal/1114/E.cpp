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
int cnt = 0;
int get_max()
{
    int l = 0;
    int r = 1e9;
    while (l < r - 1)
    {
        int mid = (l + r) / 2;
        cout << "> " << mid << endl;
        cnt++;
        int res;
        cin >> res;
        if (res == 0)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    return r;
}

int gcd(int a, int b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

int get_d()
{
    vector <int> x;
    set <int> help;
    if (n <= 60LL - cnt)
    for (int i = 0; i < min(60LL - cnt, n); i++) {
        cout << "? " << i + 1 << endl;
        int res;
        cin >> res;
        x.push_back(res);
    }
    else
    {
        for (int i = 0; i < 60LL - cnt; i++)
        {
            int p = 1;
            while (help.find(p) != help.end())
            {
                p = (rand() << 16 | rand()) % n + 1;
            }
            help.insert(p);
            cout << "? " << p << endl;
            int res;
            cin >> res;
            x.push_back(res);
        }
    }
    sort(x.begin(), x.end());
    vector <int> num;
    
    for (int i = 1; i < x.size(); i++) 
    {
        num.push_back(x[i] - x[i - 1]);
    }

    int ans = num[0];
    for (auto i : num)
    {
        ans = gcd(i, ans);
    }
    return ans;
}

void run()
{
    
    int a = get_max();
    int d = get_d();
    cout << "! " << a - d*(n - 1) << " " << d << endl;
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