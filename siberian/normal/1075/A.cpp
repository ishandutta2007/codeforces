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
int n, x, y;
void read()
{
cin >> n >> x >> y;

}
bool ans;
void run()
{
  int w = x+y-2;
  int b = n-x+n-y;
  ans = false;
  if (w <= b)
  ans = true;
}

void write()
{
if (ans)
cout << "White";
else
cout << "Black";
}

signed main()
{
	FAST;
  read();
  run();
  write();
	return 0;
}