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
  cin >> b;
  for (i = 2; i * i <= b; i++)
  {
    if (b % i == 0)
    ans += 2;
  }
  //out << i << endl;
  if ((i-1)*(i-1) == b)
    ans--;
  ans += 2;
  
  if (b == 1)
    ans = 1;
  
  cout << ans;

	return 0;
}