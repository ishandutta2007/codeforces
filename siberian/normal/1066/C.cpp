#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)
signed main()
{
  FAST;
  int q;
  cin >> q;
  vector <int> a(1e6, 0);
  int l = 1e6/2;
  int r = 1e6/2 + 1;
  map<int, int> b;
  for (int i = 0; i < q; i++)
  {
    char x;
    cin >> x;
    int m;
    cin >> m;
    if (x == 'L')
    {
      a[l] = m;
      b[m] = l;
      l--;
    }
    else if (x == 'R')
    {
      a[r] = m;
      b[m] = r;
      r++;
    }
    else{
      auto it = b[m]; 
      auto itl = l + 1;
      auto itr = r - 1;
      //cout << min((it - a.begin()) - l, find(a.begin(), a.end(), r) - it) - 2;
      cout << min(it - itl, itr - it);
      cout << endl;
    }
  }
	return 0;
}