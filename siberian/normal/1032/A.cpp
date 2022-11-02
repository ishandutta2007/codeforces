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
#include <stdio.h>

using namespace std;
#define FAST ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr)

#define int long long

int n, k;
vector <int> a;
void read()
{
  cin >> n >> k;
  a.resize(110, 0);
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    a[x]++;
  }
}
int ans = 0;
void run()
{
  int m = 0;
  int cnt = 0;
  for (int i = 0; i < a.size(); i++)
  {
    m = max(m, a[i]);
  }
  cnt = m / k;
  if (m % k != 0)
    cnt++; 
  cnt *= k;
  for (int i = 0; i < a.size(); i++)
  {
    if (a[i] != 0)
    { 
      ans += cnt - a[i];
    }
  }
  //cout << cnt << endl;
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