/*
ID: Sfiction
OJ: CF
PROB: 463B
*/
#include <cstdio>

int main(){
    int n;
    scanf("%d",&n);
    int t,max=0;
    while (n--){
        scanf("%d",&t);
        if (max<t)
            max=t;
    }
    printf("%d",max);
    return 0;
}