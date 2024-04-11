#include <cstdio>
int main(){
    int n,d;
    scanf("%d%d",&n,&d);
    int m;
    scanf("%d",&m);
    int x,y;
    for(int i=1;i<=m;i++){
        scanf("%d%d",&x,&y);
        if((x+y>=d)&&(x+y<=(2*n-d))&&(x-y>=-d)&&(x-y)<=d){
            puts("YES");
        }
        else{
            puts("NO");
        }
    }
    return 0;
}