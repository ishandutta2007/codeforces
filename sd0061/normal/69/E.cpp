#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define LL long long
#define N 100005
int n , k , a[N];
map<int , int> cnt;
struct cmp
{
  bool operator () (pair<int,int> a , pair<int,int> b)
  {
    if (a.first == b.first)
      return a.second > b.second;
    return a.first < b.first;
  }
};

set< pair<int,int> , cmp> h;


void work()
{
  int i , x ;
  scanf("%d%d",&n,&k);
  for (i = 1 ; i <= n ; ++ i)
    scanf("%d" , &a[i]);
  set< pair<int,int> >::iterator it;
  for (i = 1  ;i <= k ; ++ i)
  {
    it = h.lower_bound( make_pair(cnt[a[i]] , a[i]) );
    if (it -> second == a[i])
      h.erase(it);
    h.insert( make_pair(++ cnt[a[i]] , a[i]));
  }
  it = h.begin();
  if (it -> first == 1)
    printf("%d\n" , it -> second);
  else puts("Nothing");

  for (i = k + 1 ; i <= n ; ++ i)
  {
    it = h.lower_bound( make_pair(cnt[a[i]] , a[i]) );
    if (it -> second == a[i])
      h.erase(it);
    h.insert( make_pair(++ cnt[a[i]] , a[i]));

    it = h.lower_bound( make_pair(cnt[a[i - k]] , a[i - k]) );
    h.erase(it);
    if (-- cnt[a[i - k]])
      h.insert( make_pair(cnt[a[i - k]] , a[i - k]));

    it = h.begin();
    if (it -> first == 1)
      printf("%d\n" , it -> second);
    else puts("Nothing");
  }
}

int main()
{
  work();
  return 0;
}