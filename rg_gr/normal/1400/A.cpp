#include <stdio.h>
int main()
{
    int t;scanf("%d",&t);
    char c[125];
    while(t--)
    {
        int n;scanf("%d",&n);
        scanf("%s",c);
        for(int i=0;i<n;i++)
        printf("%c",c[n-1]);
        puts("");
    }
}