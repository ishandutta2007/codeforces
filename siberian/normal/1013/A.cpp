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

void read()
{
  int n, s = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    s+=x;
  }
  for (int i = 0; i< n; i++)
  {
    int x;
    cin >> x;
    s-=x;
  }
  if (s >= 0)
  cout << "Yes\n";
  else
  cout << "No\n";
}

void run()
{

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