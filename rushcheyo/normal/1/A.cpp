#include<cstdio>
int main(){
    int n,m,a;
    scanf("%d%d%d",&n,&m,&a);
    printf("%lld\n",1LL*((n-1)/a+1)*((m-1)/a+1));
}