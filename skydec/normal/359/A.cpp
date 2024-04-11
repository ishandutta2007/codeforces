#include<stdio.h>
using namespace std;
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
            int u;scanf("%d",&u);
            if(u)
            {
                 if(i==n||j==m||i==1||j==1){printf("2");return 0;}
                 }
                 }
    printf("4");
    return 0;
}