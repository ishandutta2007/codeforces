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
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

int a[100020];
signed main()
{
	FAST;
	int n;
  cin >> n;
  for (int i = 0; i < 100020; i++)
  {
    a[i] = 0;
  }
  a[0] = 1;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    if (x > 100010)
    {
      cout << i + 1 << endl;
      return 0;
    }
    if (i == 0 && x != 0)
    {
      cout << 1 << endl;
      return 0;
    }
    if (!x)
    continue;
    if (a[x - 1] != 1)
    {
     // cout << x << endl;
      cout << i + 1 << endl;
      return 0;
    }
    a[x] = 1;
  }
  cout << -1;
  return 0;
}