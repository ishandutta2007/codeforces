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
long long i, b, ans = 0;

signed main()
{
	FAST;
  int n, m;
  cin >> n >> m;
  vector <vector <pair <int, int> > > a(n);
  vector <int> used(n, 0);
  for (int i = 1; i <= m; i++)
  {
    int x, y;
    
    cin >> x >> y;
    x--; y--;
    used[x]++;
    used[y]++;
    a[x].push_back({i*10+10000, i*10+10000});
    a[y].push_back({i*10+10000 + 1, i*10+10000});
  }

  for (int i = 0; i < n; i++)
  {
    if (used[i] == 0)
    {
      cout << 1 << endl;
      cout << i + 1 << " " << i+1 << endl;
      continue;
    } 
    cout << used[i]*2 << endl;
    
    for (auto j : a[i])
    {
      cout << j.first << " " << j.second << endl;
      cout << j.first << " " << 100000000 + i << endl;
    }
  }
	return 0;
}