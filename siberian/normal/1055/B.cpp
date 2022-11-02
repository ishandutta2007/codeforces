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
int n, m, l;
vector <int> a;
void read()
{
  cin >> n >> m >> l;
  a.resize(n + 1);
  a[0] = -1e9;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  a.push_back(-1e9);
}

void run()
{
  bool flag = false;
  int ans = 0;

  for (int i = 1; i <= n; i++)
  {
    if (a[i] > l)
    {
      if (a[i - 1] <= l)
        ans++;
    }
  }

  for (int i = 0; i < m; i++)
  {
    int x;
    cin >> x;
    if (x == 0)
    {
      cout << ans << endl;
    }
    else if (x == 1)
    {
      int pos, val;
      cin >> pos >> val;
      if (a[pos] > l)
        continue;
      a[pos] += val;
      if (a[pos] > l)
      {
        if (a[pos - 1] > l && a[pos + 1] > l)
          ans--;
        if (a[pos - 1] <= l && a[pos + 1] <= l)
          ans++;
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