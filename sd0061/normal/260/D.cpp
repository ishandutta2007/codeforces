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
#include <set>
#define pb push_back
#define mp make_pair
#define N 100002
using namespace std;
typedef long long LL;
//const LL Q = 1000000007LL;
int n , s[N];
struct node0
{
  int x , v;
  bool operator < (const node0& t) const{
    return v > t.v;}
};
priority_queue<node0> p0;
struct node1
{
  int x , v;
  bool operator < (const node1& t) const{
    return v > t.v;}
};
priority_queue<node1> p1;

void work()
{
  int i , x , y, s0 = 0 , s1 = 0;
  for (i = 1 ; i <= n ;i ++)
  {
    scanf("%d %d",&x,&y);
    if (x)
      p1.push((node1){i , y}) , ++ s1;
    else p0.push((node0){i , y}) , ++ s0;
  }
  for (i = 1 ; i < n ;i ++)
  {
    node0 t0 = p0.top(); p0.pop();
    node1 t1 = p1.top(); p1.pop();
    -- s1 , -- s0;
    x = min(t0.v , t1.v);
    printf("%d %d %d\n",t0.x , t1.x , x);
    if (t0.v < t1.v || (t0.v == t1.v && s1 < s0))
      t1.v -= t0.v , p1.push(t1) , ++ s1;
    else t0.v -= t1.v , p0.push(t0) , ++ s0;
  }

 /* for (i = 1 ; i < n ;i ++)
  {
    set<pair<int ,int> >::iterator it0 = t0.begin(), it1 = t1.begin();
    if (it0 -> first < it1 -> first)
    {
      set<pair<int ,int> >::reverse_iterator p = t1.rbegin();
      pair<int , int> e = *p;
      x = it0 -> first , y = it0 -> second;
      t1.erase(--p.base()) , t0.erase(it0);
      t1.insert(mp(e.first - x ,e.second));
      printf("%d %d %d\n",y ,e.second , x);
    }
    else
    {
      set<pair<int ,int> >::reverse_iterator p = t0.rbegin();
      pair<int , int> e = *p;
      x = it1 -> first , y = it1 -> second;
      t0.erase(--p.base()) , t1.erase(it1);
      t0.insert(mp(e.first - x ,e.second));
      printf("%d %d %d\n",y ,e.second , x);
    }
  }*/
}

int main()
{
  while(~scanf("%d",&n)) work();
  return 0;
}