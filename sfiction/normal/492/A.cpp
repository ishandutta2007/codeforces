/*
ID: Sfiction
OJ: CF
PROB: 492A
*/
#include <cstdio>

int main(){
    int n,ans=0;
    scanf("%d",&n);
    for (int i=1;n>=i;i+=ans+1){
        ++ans;
        n-=i;
    }
    printf("%d",ans);
    return 0;
}