#include<stdio.h>

main()
{
    int n,m,x,y,i;
    scanf("%d %d", &n, &m);
    for(i=0;i<m;i++) scanf("%d %d", &x, &y);
    for(i=0;i<n;i++) {
        if(i%2==1) printf("1");
        if(i%2==0) printf("0");
    }
    printf("\n");
}