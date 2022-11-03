/*
ID: Sfiction
OJ: CF
PROB: 103A
*/
#include <cstdio>
int main(){
    int N;
    long long choice,sum=0;

    scanf("%d",&N);
    for (int i=1;i<=N;++i){
        scanf("%I64d",&choice);
        sum+=1+(choice-1)*i;
    }
    printf("%I64d",sum);
    return 0;
}