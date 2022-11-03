/*
ID: Sfiction
OJ: CF
PROB: 266A
*/
#include <cstdio>
int main()
{
    int i,n,sum;
    char a[50];
    sum=0;
    scanf("%d",&n);
    scanf("%s",a);
    for (i=0;i<n;++i)
        if (i&&a[i]==a[i-1]) ++sum;
    printf("%d",sum);
    return 0;
}