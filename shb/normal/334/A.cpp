#include <cstdio>
#include <cstdlib>

using namespace std;

int n;
 
int h(int x)
{
    if (x<=n) return x;
    return (x-n);
}

int main()
{
  scanf("%d",&n);
  for (int i=1;i<=n;i++)
  {
      for (int j=0;j<=n-1;j++)
       printf("%d ",j*n+h(i+j));
      printf("\n");
  }
}