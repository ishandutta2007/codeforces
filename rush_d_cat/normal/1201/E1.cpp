#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 2000000 + 10;

int n,m;
struct State {
    int x1,y1,x2,y2,who;
};

bool vis[42][42][42][42][2];
int deg[42][42],sg[42][42][42][42][2],out[42][42][42][42][2];
State nex[42][42][42][42][2];

int dx[8]={1,1,-1,-1,2,2,-2,-2};
int dy[8]={2,-2,2,-2,1,-1,1,-1};
bool in(int x,int y){
    return x<=n && x>=1 && y<=m && y>=1;
}
int get(int x1,int y1,int x2,int y2,int who) {
    if (who == 0) {
        if(x1==x2 && y1==y2) return 0;
        bool can = 0;
        for(int dir=0;dir<8;dir++){
            int nx=x1+dx[dir];
            int ny=y1+dy[dir];
            if(nx == x2 && ny == y2) can = 1;
        }
        if (x2 == n/2+1 && y2==m/2 && !can) return 0;
    }  else {
        if(x1==x2 && y1==y2) return 0;
        bool can = 0;

        for(int dir=0;dir<8;dir++){
            int nx=x2+dx[dir];
            int ny=y2+dy[dir];
            if(nx == x1 && ny == y1) can = 1;
        }
        if (x1 == n/2 && y1==m/2 && !can) return 0;
    }
    return 1;
}
void init() {
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
        for(int dir=0;dir<8;dir++){
            int nx=i+dx[dir];
            int ny=j+dy[dir];
            if(in(nx,ny)) deg[nx][ny]++;
        }
    }
    queue<State> q;

    for(int x1=1;x1<=n;x1++)for(int y1=1;y1<=m;y1++)for(int x2=1;x2<=n;x2++)for(int y2=1;y2<=m;y2++)for(int who=0;who<2;who++){
        out[x1][y1][x2][y2][who] = who==0 ? deg[x1][y1] : deg[x2][y2];
        if(get(x1,y1,x2,y2,who) == 0) {
            sg[x1][y1][x2][y2][who]=0; vis[x1][y1][x2][y2][who]=1;
            q.push((State){x1,y1,x2,y2,who});
        }
    }

    while(q.size()) {
        State now = q.front(); q.pop();
        int x1=now.x1, y1=now.y1, x2=now.x2, y2=now.y2, who=now.who;
        // printf("x1=%d,y1=%d,x2=%d,y2=%d,who=%d\n", x1,y1,x2,y2,who);
        if(who == 0) {
            for(int dir=0;dir<8;dir++){
                int nx=x2+dx[dir];
                int ny=y2+dy[dir];  
                if(!in(nx,ny)) continue;       
                if(vis[x1][y1][nx][ny][who^1]) continue;
                if(sg[x1][y1][x2][y2][who] == 0) {
                    vis[x1][y1][nx][ny][who^1] = 1; q.push((State){x1,y1,nx,ny,who^1});
                    nex[x1][y1][nx][ny][who^1] = now;
                    sg[x1][y1][nx][ny][who^1] = 1;
                } else {
                    out[x1][y1][nx][ny][who^1] --;
                    if(out[x1][y1][nx][ny][who^1] == 0) {
                        vis[x1][y1][nx][ny][who^1] = 1; q.push((State){x1,y1,nx,ny,who^1});
                        sg[x1][y1][nx][ny][who^1] = 0;                        
                    }
                }
            }
        } else {
            for(int dir=0;dir<8;dir++){
                int nx=x1+dx[dir];
                int ny=y1+dy[dir]; 
                //printf("dir = %d, %d ,%d\n", dir,nx,ny);     
                if(!in(nx,ny)) continue;   
                //printf("ok\n");
                if(vis[nx][ny][x2][y2][who^1]) continue;
                //printf("ok\n");
                if(sg[x1][y1][x2][y2][who] == 0) {
                    //printf("1 %d %d %d %d\n",nx,ny,x2,y2);
                    vis[nx][ny][x2][y2][who^1]= 1; q.push((State){nx,ny,x2,y2,who^1});
                    nex[nx][ny][x2][y2][who^1] = now;
                    sg[nx][ny][x2][y2][who^1] = 1;
                } else {
                    out[nx][ny][x2][y2][who^1] --;
                    if(out[nx][ny][x2][y2][who^1]== 0) {
                        vis[nx][ny][x2][y2][who^1] = 1; q.push((State){nx,ny,x2,y2,who^1});
                        sg[nx][ny][x2][y2][who^1] = 0;                        
                    }
                }
            }            
        }
    }
}
int main() {
    scanf("%d%d",&n,&m);
    init();
    int x1,y1,x2,y2;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    if(sg[x1][y1][x2][y2][0] == 1) {
        printf("WHITE\n"); fflush(stdout);
        while(1) {
            State st = nex[x1][y1][x2][y2][0];
            printf("%d %d\n", st.x1,st.y1); fflush(stdout);
            x1 = st.x1, y1 = st.y1;
            if ((x1 == n/2 && y1==m/2) || (x1==x2 && y1==y2)) {
                return 0;
            }
            scanf("%d%d",&x2,&y2);
        }
    } else {
        printf("BLACK\n"); fflush(stdout);
        while(1) {
            scanf("%d%d",&x1,&y1);
            //printf("x1=%d,y1=%d,x2=%d,y2=%d sg=%d\n", x1,y1,x2,y2,sg[x1][y1][x2][y2][1]);
            State st = nex[x1][y1][x2][y2][1];
            printf("%d %d\n", st.x2,st.y2); fflush(stdout);
            x2 = st.x2, y2 = st.y2;
            if ((x2 == n/2+1 && y2==m/2) || (x1==x2 && y1==y2)) {
                return 0;
            }
        }
    } 
}