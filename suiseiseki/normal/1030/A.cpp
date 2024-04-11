#include <cstdio>
int main(){
    int n,a;
    scanf("%d",&n);
    bool have=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        if(a==1){
            have=1;
        }
    }
    if(have){
        puts("HARD");
    }
    else{
        puts("EASY");
    }
    return 0;
}