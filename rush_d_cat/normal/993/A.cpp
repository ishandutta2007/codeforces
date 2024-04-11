#include <iostream>
using namespace std;

int x[2][5],y[2][5];
bool vis[202][202];

int main() {
    for(int i=0;i<2;i++)
        for(int j=1;j<=4;j++) {
            scanf("%d %d",&x[i][j], &y[i][j]);
            x[i][0]+=x[i][j],y[i][0]+=y[i][j];
        }

    x[0][0]/=4,y[0][0]/=4;
    x[1][0]/=4,y[1][0]/=4;

    int L=min(min(x[0][1],x[0][2]),x[0][3]);
    int R=max(max(x[0][1],x[0][2]),x[0][3]);
    int D=min(min(y[0][1],y[0][2]),y[0][3]);
    int U=max(max(y[0][1],y[0][2]),y[0][3]);
    int sum = max(abs(x[1][0] - x[1][1]), abs(x[1][0]-x[1][2]));

    for(int i=L;i<=R;i++)
        for(int j=D;j<=U;j++)
            vis[i+100][j+100]=1;
   

    for(int i=-100;i<=100;i++)
        for(int j=-100;j<=100;j++)
            if(vis[i+100][j+100]) {
                if(abs(i-x[1][0])+abs(j-y[1][0])>sum)
                    continue;            
                printf("YES\n");
                return 0;
            }
    printf("NO\n");
}