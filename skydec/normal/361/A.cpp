#include<stdio.h>
using namespace std;
int n,k;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
            for(int j=1;j<=n;j++)
            printf("%d ",(i==j)*k);
            printf("\n");
            }
    return 0;
}