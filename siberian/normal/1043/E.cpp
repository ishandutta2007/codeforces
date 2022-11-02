#include <bits/stdc++.h>

using namespace std;
#define int long long

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)



bool cmp(pair <int, pair <int, int> > x, pair <int, pair <int, int> > y)
{
  return x.second.first-x.second.second < y.second.first-y.second.second;
}

signed main()
{

  FAST;
  int n, m;
  
  cin >> n >> m;
  
  vector < pair <int, pair <int, int> > > a;
  for (int i = 0; i < n; i++)
  {
    pair <int, pair <int, int> > x;
    x.first = i;
    cin >> x.second.first >> x.second.second;
    a.push_back(x);
  }
  
  sort(a.begin(), a.end(), cmp);
  
  vector <int> b(n);
  for (int i = 0; i < n; i++)
  {
    b[a[i].first] = i;
  }
 /* cout << "a" << endl;
  for (auto i : a)
  cout << i.first << " " << i.second.first << " " << i.second.second << endl;
  cout << endl;
*/
/*  cout << "b" << endl;
  for (int i = 0; i < n; i++)
  {
    cout << i << " " << b[i] <<endl;
  }
*/
  vector <int> pref(n+1);
  pref[0] = 0;
  for (int i = 1; i <= n; i++)
  {
    pref[i] = pref[i-1]+a[i-1].second.first;
  }
  /*cout << "pref" << endl;
  for (auto i : pref)
  cout << i << " ";
  cout << endl;
 */
  vector <int> suff(n+1);
  suff[n] = 0;
  
  for (int i = n-1; i >= 0; i--)
  {
    suff[i] = suff[i+1]+ a[i].second.second;
  }

  /*
  cout << "suff" << endl;
  for (auto i : suff)
  cout << i << " ";
  cout << endl;
*/
  vector <int> ans(n, 0);
//  ans[0] = a[b[0]].second.first*n + suff[1];
 // ans[n-1] = a[b[n-1]].second.second*n + pref[n-1];
  
  for (int i = 0; i < n; i++)
  {
    ans[i] += pref[i];
    ans[i] += suff[i+1];
    ans[i] += i*a[i].second.second;
    ans[i] += (n- i - 1)*a[i].second.first;
   // ans[i] += a[b[i]].second.first*(n-i) + suff[i+1];
   // ans[i] += a[b[i]].second.second*i + pref[i]; 
  }
/*
cout << endl;
for (auto i : ans)
  cout << i << " "; 
  cout << endl;
*/
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    u--; v--;
    int x = min(a[b[u]].second.first + a[b[v]].second.second, a[b[v]].second.first + a[b[u]].second.second);
    ans[b[u]] -= x;
    ans[b[v]] -= x;
  }

  vector <int> f(n);

  for (int i = 0; i < n; i++)
  {
    f[i] = ans[b[i]];
  }
  
  for (auto i : f)
  cout << i << " ";

  return 0;
}