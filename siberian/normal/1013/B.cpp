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
int x;
vector <int> a;
int ans = -1;
set <int> b;
void read()
{
  cin >> n >> x;
  a.resize(n);
  for (int i = 0; i < n; i++)
  cin >> a[i];
}

void run()
{
  for (int i = 0; i < n; i++)
  {
    if (b.find(a[i]) != b.end())
    {
     // cout << i << " " << a[i];
      cout << 0;
      exit(0);
    }
    b.insert(a[i]);
  }
  for (int i = 0; i < n; i++)
  {
    if (b.find((a[i]&x)) != b.end() && (a[i] != (a[i]&x)))
    { 
      cout << 1;
      exit(0);
    }
  }
  for (int i = 0; i < n; i++)
  {
    if (b.find((a[i]&x)) != b.end() && (a[i] != (a[i]&x)))
    { 
      cout << 2;
      exit(0);
    }
    b.insert(a[i]&x);
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