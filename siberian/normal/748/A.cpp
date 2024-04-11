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
signed main()
{
	FAST;

  int n, m, k;
  cin >> n >> m >> k;
  char x = 'L';
  int n1, m1;
  n1 = k/(2*m);
  if (k%(2*m))
  n1++;
  m1 = k - (m*2*(n1-1) + 1);
  //cout << m*2*(n1-1) + 1 << endl;
  //cout << m1 << endl;
  m1/=2;
  m1++;
  if (k%2 == 0)
  x ='R';
  cout << n1 << " " << m1 << " " << x;
	return 0;
}