#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int n;
int main()
{
  int i,j,x,y;  
  scanf("%d",&n);
  x = 5, i = 0,y = 0,j = 1;
  while (n > x)
    n -= x , x <<= 1 , j <<= 1;    
  if ((n - 1) / j == 0)
    printf("Sheldon");
  if ((n - 1) / j == 1)
    printf("Leonard");
  if ((n - 1) / j == 2)
    printf("Penny");
  if ((n - 1) / j == 3)
    printf("Rajesh");
  if ((n - 1) / j == 4)
    printf("Howard");
  return 0;
}