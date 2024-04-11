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
int a[5][5] , b[5][5];
void work()
{
  int i , j;
  for (i = 1 ; i <= 3 ; i ++)
    for (j = 1 ;j <= 3 ; j ++)
      scanf("%d",&a[i][j]) , a[i][j] %= 2;
  for (i = 1 ; i <= 3 ; i ++)
  for (j = 1 ; j <= 3 ; j ++)
  {
    b[i][j] = a[i][j] + a[i - 1][j] + a[i + 1][j] + a[i][j - 1] + a[i][j + 1] + 1;
    b[i][j] %= 2;
  }
  for (i = 1 ; i <= 3 ; i ++)
    for (j = 1 ;j <= 3 ; j ++)
      printf("%d",b[i][j]),  j == 3 ? putchar('\n') : i;

}

int main()
{
  //int _;cin>>_;while(_--)
  work();
  return 0;
}