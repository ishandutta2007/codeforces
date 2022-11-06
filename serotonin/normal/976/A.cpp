#include<stdio.h>
#include<math.h>

main()
{
    int n,i,k=0;
    char str[105];
    scanf("%d", &n);
    scanf("%s", str);
    for(i=0;i<n;i++) {
        if(str[i]=='1') k++;
    }
    if(n==1 && k==0) printf("0");
    else {
        printf("1");
        k=n-k;
        for(i=0;i<k;i++) printf("0");
    }
    printf("\n");
}