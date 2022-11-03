/*
ID: Sfiction
OJ: CF
PROB: 337B
*/
#include <cstdio>
int main()
{
    int a,b,c,d;
    int i,p,q,t;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    p=a*d;
    q=b*c;
    for (i=2;i<=1000;++i)
        while (p%i==0&&q%i==0)
        {
            p/=i;
            q/=i;
        }
    if (p<q) printf("%d/%d",q-p,q);
    else printf("%d/%d",p-q,p);
    return 0;
}