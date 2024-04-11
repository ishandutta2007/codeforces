/*
ID: Sfiction
OJ: CF
PROB: 204A
*/
/*
[l,r][0,r]-[0,l-1]
*/
#include <stdio.h>
long long d[19][10];
void Begin()
{
    int i,j;
    long long pow;
    d[1][0]=1;
    for (j=1;j<10;j++) d[1][j]=j;
    pow=1;
    for (i=2;i<19;i++)
    {
        d[i][0]=pow;
        pow*=10;
        d[i][1]=pow+1;
        for (j=2;j<10;j++) d[i][j]=d[i][1]*j;
    }
}
long long NUM(long long N)
{
    long long t,s;
    int i,j;
    s=0;
    for (i=1;i<19;i++)
        for (j=1;j<10;j++)
            if (d[i][j]<=N)
            {
                t=(N-d[i][j])/10+1;
                if (t>d[i][0]) t=d[i][0];
                s+=t;
            }
            else return s;
    return s;
}
int main()
{
    long long l,r,sum;
    Begin();
    scanf("%I64d%I64d",&l,&r);
    sum=NUM(r)-NUM(l-1);
    printf("%I64d",sum);
    return 0;
}