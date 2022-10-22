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
#include <map>
#include <set>
#include <list>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define N 100005
int n , m ;
int a[N] , b[N];
vector<int> ans;
list<int> A , B;

void work()
{
  int i , j;
  cin >> n >> m;
  for (i = 0 ; i < n ; ++ i)
    cin >> a[i];
  for (i = 0 ; i < n ; ++ i)
    cin >> b[i];
  sort(a , a + n);
  sort(b , b + n);
  for (i = 0 ; i < n ; ++ i)
    A.push_back(a[i]);
  for (i = 0 ; i < n ; ++ i)
    B.push_back(b[i]);

  list<int>::iterator it1 = A.end() , it2 = B.begin();
  do
  {
    -- it1;
    while (it2 != B.end() && *it1 + *it2 < m) ++ it2;
    if (it2 != B.begin())
    {
      -- it2;
      ans.push_back(*it1 + *it2);
      it1 = A.erase(it1);
      it2 = B.erase(it2);
    }
  }while (it1 != A.begin());

  it1 = A.end() , it2 = B.end();
  while (it1 != A.begin())
  {
    -- it1 , -- it2;
    ans.push_back((*it1 + *it2) % m);
  }
  sort(ans.begin() , ans.end() , greater<int>());
  for (i = 0 ; i < n ; ++ i)
    printf("%d " , ans[i]);
}

int main()
{
  std::ios::sync_with_stdio(false);
    work();
  return 0;
}