#include <bits/stdc++.h>
const int INF = 1e9;
using namespace std;
int abs(int a)
{
  if (a < 0)
  return -a;
  return a;
}
signed main()
{
  int n, h, a, b, k;
  cin >> n >> h >> a >> b >> k;
  vector<vector <int> > need(k);
  for (int i = 0; i < k; i++)
  {
    int q,w,e,r;
    cin >> q >> w >> e >> r;
    need[i].push_back(q);
    need[i].push_back(w);
    need[i].push_back(e);
    need[i].push_back(r);
  }

  for (int i = 0; i < k; i++)
  {
    int res = 0;
    if (need[i][0] != need[i][2])
    {
      
      if (need[i][1] < a)
      {
        res += abs(need[i][1] - a);
        need[i][1] = a;
      }

      if (need[i][3] < a)
      {
        res += abs(need[i][3] - a);
        need[i][3] = a;
      }

      if (need[i][1] > b)
      {
        res += abs(need[i][1] - b);
        need[i][1] = b;
      }
      if (need[i][3] > b)
      {
        res += abs(need[i][3] - b);
        need[i][3] = b;
      }
    }

    res += abs(need[i][0] - need[i][2]);
    res += abs(need[i][1] - need[i][3]);
    cout << res  << endl;
  }
  
  return 0;
}