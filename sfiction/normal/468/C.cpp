/*
ID: Sfiction
OJ: CF
PROB: 468C
*/
#include <cstdio>

int main(){
    long long a;
    long long sum;
    scanf("%I64d",&a);
    sum=(long long)1E17;
    sum=(sum*5)%a;
    sum=(sum*9)%a;
    sum=(sum*9)%a;
    sum=(sum*2)%a;
    sum=a-sum;
    printf("%I64d %I64d",sum,(long long)1E18+sum-1);
    return 0;
}