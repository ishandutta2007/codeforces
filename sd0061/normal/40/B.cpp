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
#define N 105

int n , m , x;
void work()
{
  cin >> n >> m >> x;
  -- x;
  if (n > 2 * x && m > 2 * x)
  {
    m -= 2 * x , n -= 2 * x;
    int ans = 0;
    for (int i = 0 ; i < n ; ++ i) ans += (m + 1 - (i & 1)) >> 1;
    m -= 2 , n -= 2;
    for (int i = 0 ; i < n ; ++ i) ans -= (m + 1 - (i & 1)) >> 1;
    printf("%d", ans);
  }
  else printf("0");
}

int main()
{
  //freopen("~input.txt","r",stdin);
  //freopen("~output.txt","w",stdout);
  //while(scanf("%s", s) , s[0] != '#')
  //int _;cin>>_;while(_--)
    work();
  return 0;
}