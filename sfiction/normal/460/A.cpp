/*
ID: Sfiction
OJ: CF
PROB: 460A
*/
#include <cstdio>

int main(){
    int n,m;

    scanf("%d%d",&n,&m);
    printf("%d",n+(n-1)/(m-1));
    return 0;
}