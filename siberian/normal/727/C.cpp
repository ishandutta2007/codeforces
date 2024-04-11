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

int ask(int i, int j)
{
  cout << "? " << i + 1 << " " << j + 1 << endl; 
  int x;
  cin >> x;
  return x;
}

void run()
{
  int n;
  cin >> n;
  vector <int> ans(n);

  int x, y, z;
  x = ask(0, 1);
  y = ask(1, 2);
  z = ask(0, 2);

  ans[0] = x+z-y;
  ans[0]/=2;
  ans[1] = x+y-z;
  ans[1]/=2;
  ans[2] = z+y-x;
  ans[2]/=2;

  for (int i = 3; i < n; i++)
  {
    ans[i] = ask(0, i)-ans[0];
  }

  cout << "! ";
  for (auto i : ans)
  cout << i << " "; 
}


signed main()
{
	FAST;
  run();
  return 0;
}