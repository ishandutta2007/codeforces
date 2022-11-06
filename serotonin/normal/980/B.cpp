#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    int n,k,i,x;
    scanf("%d %d", &n, &k);
    printf("YES\n");
    if(k<=n-2) x=k/2;
    else x=(n-2)/2;

    for(i=0;i<n;i++) printf(".");
    printf("\n");


    for(i=0;i<n;i++) {
        if((i>0 && i<n-1) && (i>=n-1-x || i<=x)) printf("#");
        else if((k%2==1 || k==2*(n-2)) && i==n/2) printf("#");
        else printf(".");
    }
    printf("\n");

    x=(k-2*x)/2;

    for(i=0;i<n;i++) {
        if((i>0 && i<n-1) && (i>=n-1-x || i<=x)) printf("#");
        else if(k==2*(n-2) && i==n/2) printf("#");
        else printf(".");
    }
    printf("\n");


    for(i=0;i<n;i++) printf(".");
    printf("\n");
}