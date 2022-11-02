#include<cstdio>

int main()
{
    int n;
    scanf("%d",&n);
    if(n&1||n==2)puts("NO");
    else puts("YES");
}