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
int dp[1010][1010];
int n, m;
void read()
{
  cin >> n >> m;;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> dp[i][j];
    }
  }
}
int ans = 0;
void run()
{
  for (int i = 0; i < n; i++)
  {
    int cnt = 0;
    int posl = -1, posr = -1;
    for (int j = 0; j < m; j++)
    {
      if (dp[i][j] == 1)
      {
      if (posl == -1)
      posl = j;
      posr = j;
      cnt++;
      }
    }
    if (posl != -1)
    {
    ans+=(m - posl) - cnt;
    ans+=posr - cnt + 1;
   // cout << posl << " " << posr << " " << ans << endl;
    }
  }
  
  
  for (int i = 0; i < m; i++)
  {
    int cnt = 0;
    int posl = -1, posr = -1;
    for (int j = 0; j < n; j++)
    {
      if (dp[j][i] == 1)
      {
      if (posl == -1)
      posl = j;
      posr = j;
      cnt++;
      }
    }
    if (posl != -1)
    {
    ans+=(n - posl) - cnt;
    ans+=posr - cnt + 1;
    }
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