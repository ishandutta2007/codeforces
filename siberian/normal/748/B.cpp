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

#define int long long
signed main()
{
	FAST;
  string s1, s2;
  cin >> s1 >> s2;
  int n = s1.length();
  set <pair <char, char> > x;
  vector <bool> used(26, false);
  vector <bool> corr(26, false);
  vector <bool> f(26, false);
  for (int i = 0; i < n; i++)
  {
    char u, v;
    u = s1[i];
    v = s2[i];

    f[u%26] = true;
    f[v%26] = true;
    
    if (u == v)
    {
      corr[u%26] = true;
      continue;
    }

    if (u > v)
      swap(u, v);
    
    if (used[u%26] != used[v%26])
    {
      cout << -1;
      return 0;
    }

    if (used[u%26] && used[v%26])
    {
      if (x.find({u, v}) == x.end())
      {
        cout << -1;
        return 0;
      }
    }

    x.insert({u, v});
    used[u%26] = true;
    used[v%26] = true;
  }
  for (int i = 0; i < 26; i++)
  {
    if (corr[i] == used[i] && f[i])
    {
 //     cout << i << corr[i] << used[i] << f[i] << endl;
      cout << -1;
      return 0;
    }
  }
  cout << x.size() << endl;
  for (auto i : x)
  cout << i.first << " " << i.second << endl;
	return 0;

}