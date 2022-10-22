#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
#define N 50005
#define LL long long
int n , a[N] , b[N] , m;
char s[N];
LL ans;
set< pair<int,int> > h;
void work()
{
  int i , j , x;
  scanf("%s",s + 1) , n = strlen(s + 1);
  for (i = 1 ; i <= n; ++ i)
    if (s[i] == '?')
      scanf("%d%d",&a[i],&b[i]) , ans += b[i];
  x = 0;
  for (i = 1 ; i <= n ; ++ i)
  {
    if (s[i] == ')')
      ++ x;
    else if (s[i] == '(')
      -- x;
    else
    {
      h.insert(make_pair(a[i] - b[i] , i));
      s[i] = ')';
      ++ x;
    }
    if (x > 0)
    {
      if (h.empty()) break;
      set< pair<int,int> >::iterator it = h.begin();
      ans += it -> first , x -= 2 , s[it -> second] = '(';
      h.erase(it);
    }
  }
  if (i <= n || x) printf("-1");
  else
    cout << ans << endl << s + 1;
}

int main()
{
 // freopen("~input.txt","r",stdin);
  work();
  return 0;
}