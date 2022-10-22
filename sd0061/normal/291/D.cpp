#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
#define N 100005
int n , k ,  a[N];

void work()
{
  int i , j , x;
  scanf("%d%d",&n,&k);
  for (i = 1 ; i < n ; ++ i) a[i] = 1;

  while (k --)
  {
    for (i = 1 ; i <= n ; ++ i)
    {
      if ((a[i] << 1) <= n - i)
        printf("%d " , i) , a[i] <<= 1;
      else if (a[i] == n - i)
        printf("%d " , n);
      else
        printf("%d " , i + a[i]) , a[i] = n - i;
    }
    puts("");
  }


}

int main()
{
  //freopen("~input.txt" , "r", stdin);
  work();
  return 0;
}