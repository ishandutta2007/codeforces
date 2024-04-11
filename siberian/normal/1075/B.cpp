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
int n, m;
vector <int> a; 
vector <int> b;
void read()
{
  cin >> n >> m;
  a.resize(n+m);
  for (int i = 0; i < n+m; i++)
  cin >> a[i];
  for (int i = 0; i < n+m; i++)
  {
    int x;
    cin >> x;
    if (x == 1)
    {
      b.push_back(a[i]);
    }
  }
}
vector <int> ans;
void run()
{
  int r = 0;
  int l = -1;
  ans.resize(m, 0);
  for (int i = 0; i < n+m; i++)
  { 
    if (b[r] != a[i])
    {
      if (l == -1)
      ans[0]++;
      else if (r == m)
      ans[m-1]++;
      else{
        if (abs(b[l]-a[i]) <= abs(b[r]-a[i]))
        ans[l]++;
        else
        ans[r]++;
      }
    }
    else
    {
      l++;
      r++;
    }
  }
}

void write()
{
  for (auto i : ans)
  cout << i << " ";
}

signed main()
{
	FAST;
  read();
  run();
  write();
	return 0;
}