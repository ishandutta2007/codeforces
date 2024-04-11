#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <utility>
#include <map>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
#define N 1005
int n , r[N] , c[N] , rr[N] , cc[N];
vector<pair<int , pair<int , int> > > ans;
pair<int,int> a[N];
void work()
{
  int i , j , x , y;
  scanf("%d",&n);
  for (i = 1 ; i < n ; ++ i)
  {
    scanf("%d%d",&x,&y);
    a[i] = mp(x,y);
    ++ r[x] , ++ c[y];
  }
  for (i = 1 ; i <= n ; ++ i)
    rr[i] = cc[i] = i;
  for (i = n ; i > 1 ;i --)
  {
    for (j = 1 ; j <= i ; j ++)
      if (c[j] == 0)
        break;
    if (c[i] != 0 && c[j] == 0 && j <= i)
      ans.pb(mp(2,mp(j,i))) , swap(c[i],c[j]) , swap(cc[i] , cc[j]);
    for (j = 1 ; j <= i ; j ++)
      if (r[j])
        break;
    if (r[i] == 0 && r[j] != 0 && j <= i)
      ans.pb(mp(1,mp(j,i))) , swap(r[i],r[j]) , swap(rr[i] , rr[j]);
    for (j = 1 ; j < n ; j ++)
      if (rr[a[j].fi] == i)
        c[cc[a[j].se]] --;
  }
  cout << (x = ans.size()) << endl;
  for (i = 0 ; i < x ; ++ i)
    printf("%d %d %d\n",ans[i].fi , ans[i].se.fi, ans[i].se.se);
}

int main()
{
  work();
  return 0;
}