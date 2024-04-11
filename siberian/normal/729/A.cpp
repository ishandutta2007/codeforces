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
string s, ans = "";
int n;
void read()
{
  cin >> n;
  cin >> s;
  s+="***";
}

void run()
{
  bool flag = true;
  for (int i = 0; i < n; i++)
  {
    while (s[i] == 'o' && s[i+1] == 'g' && s[i+2] == 'o')
    {
      ans+="***";
      i+=3;
      while (i < n)
      {
        if (s[i] != 'g' || s[i+1] != 'o')
        break;
        i+=2;
      }
    }

    if (s[i] != '*')
    ans+=s[i];
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