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


signed main()
{
	FAST;
  long long a, b;
  cin >> a >> b;
  bool flag = false;
  if (a > b)
  {
    flag = true;
    swap(a, b);
  }
  long long sum = a + b;
  long long count = 0;
  for (int i = 1; i <= a + b; i++)
  {
    if (sum - i >= 0)
    {
      sum -= i;
      count++;
    }
    else
    {
      sum = a + b;
      break;
    }
  }

  vector <int> ans1;
  int a1 = a;
  for (int i = 1; i <= count; i++)
  {
    if (a - i >= 0)
    {
      a -= i;
      ans1.push_back(i);
    }
    else
    {
      if (i - 1)
      {
          ans1[ans1.size() - 1] += a;
          if (ans1[ans1.size() - 1] > count)
          {
              ans1[ans1.size() - 2] += ans1[ans1.size() - 1] - count;
              ans1[ans1.size() - 1] = count;
          }
      }
      a = a1;
      break;
    }
  }
  
  vector <int> ans2;
  for (int i = 1; i <= count; i++)
  {
    if (!binary_search(ans1.begin(), ans1.end(), i))
    {
      if (b - i >= 0)
      {
        b -= i;
        ans2.push_back(i);
      }
      else
      {
        break;
      }
    }
  }

  if (flag)
  swap(ans1, ans2);
  cout << ans1.size();
  cout << endl;
  for (size_t i = 0; i < ans1.size(); i++)
  {
    cout << ans1[i] << " ";
  }
  cout << endl;
  
  cout << ans2.size();
  cout << endl;
  for (size_t i = 0; i < ans2.size(); i++)
  {
    cout << ans2[i] << " ";
  }
  cout << endl;
  
  return 0;
}