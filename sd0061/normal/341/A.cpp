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
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define N 100005
int n , m ;
long long ans, a[N];
void work()
{
  int i , j; LL x , sum = 0;
  cin >> n;
  for (i = 1 ; i <= n ; ++ i)
    scanf("%d",&a[i]);
  sort(a + 1, a + n + 1);
  for (i = 1 ; i <= n ; ++ i)
  {
    ans += (a[i] * (i - 1) - sum) * 2;
    sum += a[i];
  }
  for (i = 1 ; i <= n ; ++ i)
    ans += (LL) a[i];
  x = n , sum = __gcd(x , ans);
  ans /= sum , x /= sum;
  cout << ans << ' ' << x << endl;

}

int main()
{
  //while (scanf("%d",&n) , n)
  //int _; cin >> _;while (_--)
    work();
  return 0;
}