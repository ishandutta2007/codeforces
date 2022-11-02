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


signed main()
{
	FAST;
  int n, m;
  cin >> n >> m;
  vector <int> ans;
  ans.push_back(m);
  while (n < m)
  {
    if (m % 2 == 0)
    {
      m/=2;
      ans.push_back(m);
    }
    else if (m % 10 == 1)
    {
      m /= 10;
      ans.push_back(m);
    }
    else
    {
      cout << "NO\n";
      return 0;
    }
  }
  if (m != n)
  {
    cout << "NO\n";
    return 0;
  }
  reverse(ans.begin(), ans.end());
  cout << "YES\n";
  cout << ans.size() << endl;
  for (auto i : ans)
  cout << i << " ";
	return 0;
}