#include<cstdio>
int main()
{
    int n,m,x;
    scanf("%d%d%d",&n,&m,&x);
    x+=x,x--;
    printf("%d\n",(n-=x)<0||(m-=x)<0?0:n+m<1?1:n+m);
    return 0;
}