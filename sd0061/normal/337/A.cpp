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
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define N 200005
int n , m , a[N];

void work()
{
  int i , ans = 1 << 30;
  cin >> n >> m;
  for (i = 0 ; i < m ; ++ i)
    cin >> a[i];
  sort(a , a + m);
  for (i = 0 ; i + n - 1 < m ; ++ i)
    ans = min(ans , a[i + n - 1] - a[i]);
  cout << ans << endl;
}

int main()
{
  //freopen("~input.txt","r",stdin);
  //while (~scanf("%d",&n))
    work();
  return 0;
}