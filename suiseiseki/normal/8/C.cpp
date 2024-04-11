#include <cstdio>
#include <cstring>
struct Point{
    int x,y;
}a[30];
int dist(int x1,int y1,int x2,int y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
int dis[30][30];
int f[1<<24|5],last[1<<24|5];
int n;
void out(int now){
    if(now==0){
        return;
    }
    out(last[now]);
    printf("0 ");
    for(int i=1;i<=n;i++){
        if((1<<i-1)&(now^last[now])){
            printf("%d ",i);
        }
    }
}
int main(){
    scanf("%d%d",&a[0].x,&a[0].y);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i].x,&a[i].y);
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dis[i][j]=dist(a[i].x,a[i].y,a[j].x,a[j].y);
        }
    }
    memset(f,0x3f,sizeof(f));
    f[0]=0;
    for(int k=0;k<(1<<n);k++){
        if(f[k]==0x3f3f3f3f){
            continue;
        }
        for(int i=1;i<=n;i++){
            if(k&(1<<i-1)){
                continue;
            }
            for(int j=1;j<=n;j++){
                if(k&(1<<j-1)){
                    continue;
                }
                if(f[k|(1<<i-1)|(1<<j-1)]>f[k]+dis[0][i]+dis[i][j]+dis[j][0]){
                    f[k|(1<<i-1)|(1<<j-1)]=f[k]+dis[0][i]+dis[i][j]+dis[j][0];
                    last[k|(1<<i-1)|(1<<j-1)]=k;
                }
            }
            break;
        }
    }
    printf("%d\n",f[(1<<n)-1]);
    out((1<<n)-1);
    puts("0");
    return 0;
}