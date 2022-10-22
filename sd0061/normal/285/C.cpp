#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <string>
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
#define N 300005
#define M 100005
#define LL long long
int n , a[N];
bool f[N];
void work()
{
  int i ;
  long long ans = 0;
  scanf("%d",&n);
  for (i = 1 ; i <= n ; ++ i)
    scanf("%d",&a[i]);
  sort(a + 1 , a + 1 + n);
  for (i = 1 ; i <= n ;i ++)
    ans += abs(a[i] - i);
  cout << ans << endl;
}


int main()
{
    work();
  return 0;
}