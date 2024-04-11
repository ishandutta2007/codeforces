#include <cstdio>
char s[120][120];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
    }
    int left_x=-1,left_y,bc;
    for(int i=1;i<=n&&left_x==-1;i++){
        for(int j=1;j<=m&&left_x==-1;j++){
            if(s[i][j]=='B'){
                left_x=i;
                left_y=j;
                bc=0;
                for(int k=j;s[i][k]=='B';k++){
                    bc++;
                }
            }
        }
    }
    bc=(bc+1)>>1;
    printf("%d %d\n",(left_x+bc-1),(left_y+bc-1));
    return 0;
}