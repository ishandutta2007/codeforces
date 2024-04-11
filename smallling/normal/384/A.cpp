#include<cstdio>
#include<cstdlib>
int i,j,n,ans;
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    if((i+j)%2==0)ans++;
    printf("%d\n",ans);
    for(i=1;i<=n;i++,printf("\n"))
    for(j=1;j<=n;j++)
    if((i+j)%2==0)printf("C");
    else printf(".");
    //system("pause");
}