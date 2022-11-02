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

using namespace std;
#define FAST ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr)

//#define int long long

void read()
{
  int n;
  cin >> n;
  vector <int> a(n + 1, -1e9);
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
  }
  int ans = 0;
  int loc = 0;
  
  for (int i = 1; i <= n; i++)
    if (a[i] == i)
      loc++;
    else
      break;
  ans = max(loc, ans);
  loc = 0;
  int pos = 1000;
  for (int i = n; i > 0; i--)
    if (a[i] == pos)
    {
      loc++;
      pos--;
    }
    else
    break;
  ans = max(loc, ans);
  loc = 0;

  for (int i = 1; i <= n; i++)
  {
    if (a[i] == a[i - 1] + 1)
    {
      loc++;
    }
    else
    {
      ans = max(loc, ans);
      loc = 0;
    }
  }
  ans = max(loc, ans);
  cout << max(ans-1, 0);
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