/*
ID: Sfiction
OJ: CF
PROB: 468A
*/
#include <cstdio>

int main(){
    int n;

    scanf("%d",&n);
    if (n<=3)
        printf("NO");
    else
        if (n&1){
            printf("YES");
            for (int i=n;i>5;i-=2)
                printf("\n%d - %d = 1\n1 * 1 = 1",i,i-1);
            printf("\n5 + 3 = 8");
            printf("\n8 - 2 = 6");
            printf("\n6 * 4 = 24");
            printf("\n24 * 1 = 24");
        }
        else{
            printf("YES");
            for (int i=n;i>4;i-=2)
                printf("\n%d - %d = 1\n1 * 1 = 1",i,i-1);
            printf("\n4 * 3 =12");
            printf("\n12 * 2 =24");
            printf("\n24 * 1 =24");
        }
    return 0;
}