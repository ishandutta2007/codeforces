#include<stdio.h>
using namespace std;
int main()
{
    long n;scanf("%ld",&n);
    if(n==1||n==2)
    {
                  printf("-1");
                  return 0;
                  }
    else
    {
                  for(long i=n;i>=1;i--)printf("%ld ",i);
                  }
    return 0;
}