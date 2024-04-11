#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <set>
using namespace std;
#define N 100005
#define LL long long
int n , k , a[N] , ans;
multiset<int> h;
vector< pair<int,int> > p;
int main()
{
   int i , j , x , y;
   scanf("%d%d",&n,&k);
   for (i = 1 ; i <= n ; ++ i)
      scanf("%d",&a[i]);
   multiset<int>::iterator it;
   for (i = 1 , j = 0 ; i <= n ; ++ i)
   {
     h.insert(a[i]);
     while (j < i)
     {
       x = *h.begin() , y = *(-- h.end());
       if (y - x <= k) break;
       it = h.lower_bound(a[++ j]) , h.erase(it);
     }
     ans = max(ans , i - j);
   }
   cout << ans << ' ';
   h.clear();
   for (i = 1 , j = 0 ; i <= n ; ++ i)
   {
     h.insert(a[i]);
     while (j < i)
     {
       x = *h.begin() , y = *(-- h.end());
       if (y - x <= k) break;
       it = h.lower_bound(a[++ j]) , h.erase(it);
     }
     if (i - j == ans) p.push_back(make_pair(j + 1, i));
   }
   cout << p.size() << endl;
   for (i = 0 ; i < p.size() ; ++ i)
     cout << p[i].first << ' ' << p[i].second << endl;

}