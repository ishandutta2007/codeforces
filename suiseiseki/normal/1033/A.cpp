#include <cstdio>
#include <queue>
using namespace std;
bool mp[1005][1005];
bool visit[1005][1005];
const int d[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
queue<int> qx,qy;
int main(){
    int n;
    int sx,sy,tx,ty,x,y;
    scanf("%d",&n);
    scanf("%d%d",&x,&y);
    for(int i=1;i<=n;i++){
        mp[x][i]=mp[i][y]=1;
    }
    int i=x,j=y;
    while(i>0&&j>0){
        mp[i][j]=1;
        i--,j--;
    }
    i=x,j=y;
    while(i<=n&&j<=n){
        mp[i][j]=1;
        i++,j++;
    }
    i=x,j=y;
    while(i<=n&&j>0){
        mp[i][j]=1;
        i++,j--;
    }
    i=x,j=y;
    while(i>0&&j<=n){
        mp[i][j]=1;
        i--,j++;
    }
    scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
    qx.push(sx);
    qy.push(sy);
    int nx,ny;
    while(!qx.empty()){
        x=qx.front();
        y=qy.front();
        qx.pop();
        qy.pop();
        for(int i=0;i<8;i++){
            nx=x+d[i][0];
            ny=y+d[i][1];
            if(nx<1||ny<1||nx>n||ny>n||mp[nx][ny]||visit[nx][ny]){
                continue;
            }
            visit[nx][ny]=1;
            qx.push(nx);
            qy.push(ny);
        }
    }
    if(visit[tx][ty]){
        puts("YES");
    }
    else{
        puts("NO");
    }
    return 0;
}