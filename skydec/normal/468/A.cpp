#include<stdio.h>
#include<cstring>
using namespace std;
int n;
int main()
{
    scanf("%d",&n);
    if(n<=3){printf("NO\n");return 0;}
    printf("YES\n");
    if(n%2==0)
    {
              printf("1 * 2 = 2\n");
              printf("2 * 3 = 6\n");
              printf("6 * 4 = 24\n");
              for(int j=5;j<=n;j+=2)
              {
                      printf("%d - %d = 1\n",j+1,j);
                      printf("1 * 24 = 24\n");
                      }
                      }
    else
    {
        printf("2 * 5 = 10\n");
        printf("3 - 1 = 2\n");
        printf("2 * 10 = 20\n");
        printf("20 + 4 = 24\n");
        for(int j=6;j<=n;j+=2)
        {
                      printf("%d - %d = 1\n",j+1,j);
                      printf("1 * 24 = 24\n");
                      }
                      } 
    return 0;
}