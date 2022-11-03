/*
ID: Sfiction
OJ: CF
PROB: 198A
*/
#include <cstdio>

int main(){
    int k,b,n,t;

    scanf("%d%d%d%d",&k,&b,&n,&t);
    for (++n;n && t>0;--n)
        t=(t-b)/k;
    printf("%d",n);
    return 0;
}