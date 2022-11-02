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
#define ll long long

vector <ll> parent;
 
void make_set (ll v)
{
    parent[v] = v;
}
 
ll find_set (ll v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set (parent[v]);
}
 
void union_sets (ll a, ll b)
{
    a = find_set (a);
    b = find_set (b);
    if (a != b)
        parent[b] = a;
}

ll ve(vector <ll> a)
{
  sort(a.begin(), a.end());
  ll n = int(a.size());
  ll maxi = 1;
  ll locmax = 1;
  for (ll i = 0; i < n - 1; i++)
  {
    if (a[i] == a[i + 1])
    {
      locmax++;
    }
    else
    {
      maxi = max(maxi, locmax);
      locmax = 1;
    }
  } 
  maxi = max(maxi, locmax);
  return n - maxi;
}

signed main()
{
	//FAST;
	ll n, m, k;
  cin >> n >> m >> k;
  parent.resize(n);
  vector <ll> colors(n);
  for (ll i = 0; i < n; i++)
  {
    cin >> colors[i];
  }

  for (ll i = 0; i < n; i++)
  {
    make_set(i);
  }

  for (ll i = 0; i < m; i++)
  {
    ll l, r;
    cin >> l >> r;
    l--;
    r--;
    if (find_set(l) != find_set(r))
    union_sets(l, r);
  }

  set <ll> a;
  for (ll i = 0; i < n; i++)
  {
    a.insert(find_set(i));
  }

  map <ll, vector <ll> > b;
  for (ll i = 0; i < n; i++)
  {
    if (b.count(find_set(i)) == 0)
    {
      vector <ll> c;
      c.push_back(colors[i]);
      b[find_set(i)] = c;
    }
    else
    {
      b[find_set(i)].push_back(colors[i]);
    }
  }
  ll ans = 0;
  for (auto i : a)
  {
    if (b[i].size())
    ans += ve(b[i]);
    //cout << ans << " ";
  }
  //cout << endl;
  cout << ans;
  
  for(auto i : parent)
  {
    //cout << i << " ";
  }

  return 0;
}