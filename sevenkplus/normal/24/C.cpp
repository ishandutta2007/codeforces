#include<cstdio>
int main()
{
    int n,x,y,C=1;long long m;
    scanf("%d%I64d%d%d",&n,&m,&x,&y),m%=(n*2);
    for(int i=0,X,Y;i<m&&i<n;i++)
    {
        scanf("%d%d",&X,&Y),x=-x,y=-y;
        if(i+n>=m)x+=2*X,y+=2*Y;else C=-C;
    }
    printf("%d %d\n",x*C,y*C);
    return 0;
}