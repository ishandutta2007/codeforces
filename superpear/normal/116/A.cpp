#include <cstdio>

int main()
{
    int n,now=0,max=0,x1,y1;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d %d",&x1,&y1);
        now-=x1;now+=y1;
        if (now>max) max=now;
    }
    printf("%d\n",max);
    return 0;
}