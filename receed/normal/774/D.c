#include<stdio.h>

int main(){
    int n,l,r,t;
    scanf("%d%d%d",&n,&l,&r);
    int a[100001];
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        scanf("%d",&t);
        if(t!=a[i] && (i<l || i>r)){
            printf("LIE");
            return 0;
        }
    }
    printf("TRUTH");
    return 0;
}