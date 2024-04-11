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

int n, a, b, k;
vector <char> x;
void read()
{
  cin >> n >> a >> b >> k;
  x.resize(n);
  for (int i = 0; i < n; i++)
  {
    cin >> x[i];
  }
}
vector <int> ans;

void run()
{
  int cnt1 = 0, cnt2 = 0;
  for (int i = n-1; i >= 0; i--)
  {
    if (x[i] == '0')
    cnt2++;
    else
    {
      cnt2=0;
      continue;
    }
    if (cnt1 < a)
    {
      x[i] = 'x';
    }
    if (cnt2 % b == 0)
    cnt1++;
  }
/*  for (int i = 0; i < n; i++)
  {
    cout << x[i];
  }*/
  cout << endl;
  cnt1 = 0, cnt2 = 0;
  for (int i = 0; i < n; i++)
  {
    if (x[i] == '0')
    cnt2++;
    else
    {
      cnt2=0;
      cnt1=0;
      continue;
    }
    if (cnt2 % b == 0)
    {
      ans.push_back(i+1);
    }
  }
  for (int i = 0; i < n; i++)
  if (x[i]=='x')
  {
    ans.push_back(i+1);
    break;
  }
}

void write()
{
  cout << ans.size() << endl;
  for (auto i : ans)
  cout << i << " ";
}


signed main()
{
	FAST;
	read();
	run();
	write();
	return 0;
}