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
int n , a[N] , f[N];

void work()
{
  int i , x , y;
  cin >> n;
  for (i = 1 ; i <= n ; ++ i)
  {
    scanf("%d",&x);
    y = min(i , n - i + 1);
    if (x >= y) ++ f[x - y + 1];
  }
  int ans = 0;
  for (i = 1 ; i <= 100000 ; ++ i)
    ans = max(ans , f[i]);
  cout << n - ans << endl;
}

int main()
{
//  freopen("input.txt", "r" , stdin);
    work();
  return 0;
}