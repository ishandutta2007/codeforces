#include<stdio.h>
main()
{
    int n;
    scanf("%d",&n);
    int p = n%7;
    int s = n/7;
    int mn= 2*s,mx = 2*s;
    if(p > 5) mn += (p -5);
    if(p > 2) mx += 2;
    else mx += p;
    printf("%d %d",mn,mx);
}