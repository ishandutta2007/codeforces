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
int n;
vector <int> a;

void read()
{
  cin >> n;
  n*=2;
  a.resize(n);
  for (int i = 0; i < n; i++)
  cin >> a[i];
  sort(a.begin(), a.end());
  n/=2;
}
int ans;
void run()
{
  ans = (a[2*n-1] - a[n])*(a[n-1] - a[0]);
  for (int i = 1; i < n; i++)
  ans = min(ans, (a[2*n-1] - a[0])*(a[n + i-1] - a[i]));
}

void write()
{
cout << ans;
}

signed main()
{
	FAST;
  read();
  run();
  write();
	return 0;
}