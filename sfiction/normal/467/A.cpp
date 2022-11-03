/*
ID: Sfiction
OJ: CF
PROB: 467A
*/
#include <cstdio>

int main(){
    int n,ans=0;
    int a,b;
    
    scanf("%d",&n);
    for (int i=0;i<n;++i){
        scanf("%d%d",&a,&b);
        if (b-a>=2)
            ++ans;
    }
    printf("%d",ans);
    return 0;
}