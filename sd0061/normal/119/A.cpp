#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int n,a,b;
int gcd(int x,int y) {return x % y == 0 ? y : gcd(y, x % y);}

int main()
{
  int i,j,x,y;  
  scanf("%d%d%d",&a,&b,&n);
  while (1)
  {
    if (n < gcd(n,a))
    {
      printf("1");
      break;    
    }    
    n -= gcd(n,a);
    if (n < gcd(n,b))
    {
      printf("0");
      break;    
    }    
    n -= gcd(n,b);
  }
  return 0;
}