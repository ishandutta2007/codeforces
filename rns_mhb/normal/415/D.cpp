 #include<stdio.h>
#define MAX 1000000007
int f[2010][2010],s;
main()
{
    int n,k,i,j,p;
    for(i=1;i<=2000;i++)
    {
        f[i][1]=1;
        for(j=1;j<=2000;j++)
        for(k=i;k<=2000;k+=i)
        f[k][j+1]+=f[i][j],f[k][j+1]%=MAX;
    }
    scanf("%d%d",&n,&p);
    for(i=1;i<=n;i++)
        s+=f[i][p],s%=MAX;
    printf("%d",s);
}