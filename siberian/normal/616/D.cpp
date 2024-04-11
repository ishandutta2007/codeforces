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
const int MAXN = 5 * 1e5 + 10;
int arr[MAXN];
int n, k;
void read()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

const int MAXX = 1e6 + 10;
int mul[MAXX];
int check(int col)
{
    int cnt = 0;
    for (int i = 0; i < col; i++)
    { 
        if (mul[arr[i]] == 0)
        {
            cnt++;
        }
        mul[arr[i]]++;
    }
    if (cnt <= k)
        return true;
    for (int i = col; i < n; i++)
    {
        mul[arr[i - col]]--;
        if (mul[arr[i - col]] == 0)
        {
            cnt--;
        }
        if (mul[arr[i]] == 0)
        {
            cnt++;
        }
        mul[arr[i]]++;
        if (cnt <= k)
        {
            return true;
        }
    }
    return false;
}

pair<int, int> fans(int col)
{
    int cnt = 0;
    for (int i = 0; i < col; i++)
    {
        if (mul[arr[i]] == 0)
        {
            cnt++;
        }
        mul[arr[i]]++;
    }
    if (cnt <= k)
        return {1, col};
    for (int i = col; i < n; i++)
    {
        mul[arr[i - col]]--;
        if (mul[arr[i - col]] == 0)
        {
            cnt--;
        }
        if (mul[arr[i]] == 0)
        {
            cnt++;
        }
        mul[arr[i]]++;
        if (cnt <= k)
        {
            return {i - col + 2, i + 1};
        }
    }
}

pair <int, int> ans;
void run()
{
    int l = 0, r = n, mid;
    while (l < r - 1)
    {
        mid = (l + r) / 2;
        for (int i = 0; i < MAXX; i++)
        {
            mul[i] = 0;
        }
        if (check(mid))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    for (int i = 0; i < MAXX; i++)
    {
        mul[i] = 0;
    }
    if (check(l + 1) && l < n)
        l++;
    for (int i = 0; i < MAXX; i++)
    {
        mul[i] = 0;
    }
    ans = fans(l);
}

void write()
{
    cout << ans.first << " " << ans.second;
}

signed main()
{
    FAST;
    read();
    run();
    write();
    return 0;
}