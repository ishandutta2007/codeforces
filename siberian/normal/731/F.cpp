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
#define ll long long
const ll maxn = 500000;
ll a[maxn], cnt[maxn];
signed main()
{
	//FAST;
  for (int i = 0; i < maxn; i++)
  {
    a[i] = 0;
    cnt[i] = 0;
  }
  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    a[x]++;
  }

  for (int i = 1; i < maxn; i++)
  {
    cnt[i] += cnt[i - 1] + a[i];
  }

  ll ans = 0;
  for (int i = 1; i < 200010; i++)
  {
    if (!a[i])
      continue;
    ll res = 0;
    for (int j = i; j < 200010; j += i)
      res += abs(cnt[j + i - 1] - cnt[j - 1])*j;
    ans = max(ans, res);
  }
  cout << ans;
  return 0;
}