#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define N 200005
int n , m , c[N] , t[N];
void work()
{
  int i , j , x;
  scanf("%d%d",&n,&m);
  for (i = 1 ; i <= n ; ++ i)
    scanf("%d%d",&c[i],&t[i]) , c[i] *= t[i];
  i = 1 , j = c[1];
  while (m --)
  {
    scanf("%d",&x);
    while (x > j)
      ++ i , j += c[i];
    printf("%d\n" , i);
  }

}

int main()
{
 // init();
  //int _;cin >> _;while(_--)
  //while (~scanf("%d",&n))
    work();
  return 0;
}