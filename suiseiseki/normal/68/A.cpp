#include <cstdio>
int main(){
    int p1,p2,p3,p4,a,b;
    scanf("%d%d%d%d%d%d",&p1,&p2,&p3,&p4,&a,&b);
    int ans=0;
    for(int i=a;i<=b;i++){
        if(i%p1==i&&i%p2==i&&i%p3==i&&i%p4==i){
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}