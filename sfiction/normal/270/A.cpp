/*
ID: Sfiction
OJ: CF
PROB: 270A
*/
#include <cstdio>
int main()
{
    int t,degree;
    scanf("%d",&t);
    for (;t;--t)
    {
        scanf("%d",&degree);
        if (360%(180-degree)==0) printf("YES");
        else printf("NO");
        if (t>1) printf("\n");
    }
    return 0;
}