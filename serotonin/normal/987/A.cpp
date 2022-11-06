#include<stdio.h>
#include<math.h>

main()
{
    int n,i,stones[6];
    char s[10];
    double q,l,limit;
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        scanf("%s", s);
        if(s[0]=='p') stones[0]=1;
        if(s[0]=='g') stones[1]=1;
        if(s[0]=='b') stones[2]=1;
        if(s[0]=='o') stones[3]=1;
        if(s[0]=='r') stones[4]=1;
        if(s[0]=='y') stones[5]=1;
    }
    printf("%d\n", 6-n);
    for(i=0;i<6;i++) {
        if(stones[i]!=1) {
            if(i==0) printf("Power\n");
            if(i==1) printf("Time\n");
            if(i==2) printf("Space\n");
            if(i==3) printf("Soul\n");
            if(i==4) printf("Reality\n");
            if(i==5) printf("Mind\n");
        }
    }
}