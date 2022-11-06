#include<stdio.h>
#include<math.h>


main()
{
    int n,i,j,d[50],k=0,x;
    char s[105],r[105];
    scanf("%d %s", &n, s);
    for(i=2;i<=100;i++) {
        if(n%i==0) {
            d[k]=i;
            k++;
        }
    }
    for(i=0;i<k;i++) {
        x=d[i];
        for(j=0;j<x;j++) {
            r[j]=s[x-1-j];
        }
        for(j=0;j<x;j++) {
            s[j]=r[j];
        }
    }
    for(i=0;i<n;i++) printf("%c", s[i]);
    printf("\n");
}