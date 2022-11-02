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
  int n;
  cin >> n;
  bool up = false, down = false, left = false, right = false;
  int cnt = 1;
  for (int i = 0; i < n; i++)
	{

    char x;
    cin >> x;
    if (x == 'U')
    {
      if (down)
      {
        cnt++;
        up = false;
        down = false;
        left = false;
        right = false;
      }
       up = true;
    }
    if (x == 'D')
    {
      
      if (up)
      {
       cnt++;
       
        up = false;
        down = false;
        left = false;
        right = false;
      }
       down = true;
     }
    if (x == 'R')
    {
      
      if (left)
      {
        cnt++;
        
        up = false;
        down = false;
        left = false;
        right = false;
      }
       right = true;
    }
    if (x == 'L')
    {  
      if (right)
      {
       cnt++;     
        up = false;
        down = false;
        left = false;
        right = false;
      }
      left = true;
      }
  }
  cout << cnt;
  return 0;

}