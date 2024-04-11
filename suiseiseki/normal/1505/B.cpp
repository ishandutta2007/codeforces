#include <cstdio>
int solve(int a){
    int ans=0;
    while(a){
        ans+=a%10;
        a/=10;
    }
    return ans;
}
int main(){
    int a;
    scanf("%d",&a);
    while(a>=10){
        a=solve(a);
    }
    printf("%d\n",a);
    return 0;
}