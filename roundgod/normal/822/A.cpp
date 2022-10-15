#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
int x,y;
int fac(int n)
{
  int s=1;
  for(int i=1;i<=n;i++)
    s*=i;
return s;
}
int main()
{
   scanf("%d %d",&x,&y);
   printf("%d\n",x>y? fac(y):fac(x));
   return 0;
}