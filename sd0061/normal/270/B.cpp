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
#define N 100005
typedef long long ll;
int n , a[N] , ans;

void work()
{
  int i , j , ans = 0;
  scanf("%d",&n);
  for (i = 1 ; i <= n ;i ++)
    scanf("%d",&a[i]);
  for(i = 1;i < n; i ++)
    if (a[i] > a[i + 1])
      ans = i;
  cout << ans <<endl;
}

int main()
{
  work();
  return 0;
}