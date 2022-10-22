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
int n , m , a[N] , b[N] , cnt , sum[N << 1];
map<int , int> h;
LL p[N * 2];

int power(int k)
{
  LL a = 2 , ans = 1;
  while (k)
  {
    if (k & 1) ans *= a , ans %= m;
    a *= a , a %= m , k >>= 1;
  }
  return (int)ans;
}

void work()
{
  int i , x;
  cin >> n;
  for (i = 0 ;i < n ; ++ i)
    scanf("%d",&a[i]);
  for (i = 0 ;i < n ; ++ i)
    scanf("%d",&b[i]);
  for (i = 0 ;i < n ; ++ i)
  {
    ++ h[a[i]] , ++ h[b[i]];
    if (a[i] == b[i])
      -- cnt;
  }
  cin >> m;
  p[0] = 1 % m;
  for (i = 1 ; i <= n << 1 ; ++ i)
  {
    sum[i] = sum[i - 1];
    x = i;
    while (!(x & 1))
      x >>= 1 , ++ sum[i];
    p[i] = p[i - 1] * x % m;
  }
  LL ans = 1;
  map<int ,int>::iterator it;
  for (it = h.begin() ; it != h.end() ; ++ it)
    ans *= p[it -> second] , cnt += sum[it -> second] , ans %= m;
  cout << ans * power(cnt) % m << endl;
}

int main()
{
  //freopen("input.txt", "r" , stdin);
    work();
  return 0;
}