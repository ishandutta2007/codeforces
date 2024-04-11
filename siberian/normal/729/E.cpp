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

int n, s;
vector <int> a;
int ans = 0;
void read()
{
  cin >> n >> s;
  s--;
  a.resize(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
}
void run()
{
  if (a[s] != 0)
  {
    ans++;
    a[s] = 0;
  }
  for (int i = 0; i < n; i++)
  {
    if (i == s)
    continue;
    if (a[i] == 0)
    a[i] = n;
  }

  sort(a.begin(), a.end());
  int pos = n-1;
  for (int i = 1; i < n; i++)
  {
    if (binary_search(a.begin(), a.end(), i) == false && a[pos] > i)
    {
      pos--;
      ans++;
    }  
  }
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