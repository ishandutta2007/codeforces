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
	int n;
  cin >> n;
  vector <int> a(n);
  vector <int> b(n);
  vector <pair<int, int> > sum(n);
  vector <int> ans(n);
  int max = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    if (a[i] > i)
    {
      cout << "NO\n";
      return 0;
    }
  }
  
  for (int i = 0; i < n; i++)
  {
    cin >> b[i];
    if (b[i] > n - i - 1)
    {
      cout << "NO\n";
      return 0;
    }
    sum[i].first = a[i] + b[i];
    sum[i].second = i;
  }
  sort(sum.begin(), sum.end());
  reverse(sum.begin(), sum.end());
  int x = 1;
  ans[sum[0].second] = 1;
  for (int i = 1; i < n; i++)
  {
    if (sum[i].first != sum[i- 1].first)
    x++;
    ans[sum[i].second] = x;
  }

  for (int i = 0; i < n; i++)
  {
    int cnt = 0;
    for (int j = 0; j < i; j++)
    {
      if (ans[j] > ans[i])
      cnt++;
    }
    if (cnt != a[i])
    {
      cout << "NO\n";
      return 0;
    }
  }

  for (int i = 0; i < n; i++)
  {
        int cnt = 0;
    for (int j = i + 1; j < n; j++)
    {
      if (ans[j] > ans[i])
      cnt++;
    }
    if (cnt != b[i])
    {
      cout << "NO\n";
      return 0;
    }
  }

  cout << "YES\n";
  for (auto i : ans)
  cout << i << " ";
  return 0;
}