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

int n, m, k;
vector <vector <int> > g(400400);
vector <bool> used;

void dfs(int v)
{
  used[v] = 1;
  for (auto i : g[v])
  {
    if (!used[i])
    dfs(i);
  }
}

void read()
{
  cin >> n >> m >> k;
  used.resize(n+m, false);
  for (int i = 0; i < k; i++)
  {
    int v, u;
    cin >> v >> u;
    v--;
    u--;
    u+=n;
    g[u].push_back(v);
    g[v].push_back(u);
  }
}
int ans = -1;
void run()
{
  for (int i = 0; i < (n+m); i++)
  {
    if (!used[i])
    {
      dfs(i);
      ans++;
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