/*
ID: Sfiction
OJ: CF
PROB: 441C
*/
#include <cstdio>
int main(){
    int n,m,k;
    int x,y,dy,l;
    int i;
    scanf("%d%d%d",&n,&m,&k);
    x=y=1;
    dy=1;
    printf("%d",n*m-2*k+2);
    for (i=1;i<=n*m-2*k+2;++i){
        printf(" %d %d",x,y);
        if (y+dy>m||y+dy<1){
            dy=-dy;
            ++x;
        }
        else
            y+=dy;
    }
    l=2;
    for (;i<=n*m;++i){
        if (l==2){
            printf("\n2");
            l=0;
        }
        printf(" %d %d",x,y);
        ++l;
        if (y+dy>m||y+dy<1){
            dy=-dy;
            ++x;
        }
        else
            y+=dy;
    }
    return 0;
}