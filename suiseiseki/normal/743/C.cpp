#include <cstdio>
int main(){
    int n;
    scanf("%d",&n);
    if(n==1){
        puts("-1");
        return 0;
    }
    printf("%d %d %d\n",n,n+1,n*(n+1));
    return 0;
}