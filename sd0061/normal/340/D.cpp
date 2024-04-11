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
int n , a[N];
int s[N] , top;
void work()
{
  int i , j;
  scanf("%d",&n);
  for (i = 1 ; i <= n ; ++ i)
    scanf("%d",&a[i]);
  for (i = 1 ; i <= n ; ++ i)
  {
    if (a[i] > s[top])
      s[++ top] = a[i];
    else
    {
      j = upper_bound(s + 1 , s + top + 1 , a[i]) - s;
      s[j] = a[i];
    }
  }
  cout << top << endl;
}

int main()
{
  //
  //freopen("~input.txt","r",stdin);
  //while (scanf("%d",&n) , n)
  //int _; cin >> _;while (_--)
    work();
  return 0;
}