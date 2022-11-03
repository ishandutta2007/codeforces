//
//  main.cpp
//  CirclingRoundTreasures
//
//  Created by  on 2019/10/22.
//  Copyright  2019 . All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

int bss[21][21][256][4][4];
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};

struct State{
    int x,y;
    int ob;
    int fx,qfx;
    int bs;
    State(){bs=0;}
    State(int x,int y,int ob,int fx,int qfx):x(x),y(y),ob(ob),fx(fx),qfx(qfx){bs=0;}
};

int n,m;
char s[21][21];
int sx,sy;
int px[8],py[8];
int cnt;
int bs;
int val[8];
int vcl[21][21];

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
        for(int j=1;j<=m;j++){
            if(s[i][j]=='S'){
                sx=i;
                sy=j;
                s[i][j]='.';
            }else if(s[i][j]>='1'&&s[i][j]<='8'){
                px[s[i][j]-'1']=i;
                py[s[i][j]-'1']=j;
                cnt++;
                bs++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i][j]=='B'){
                px[cnt]=i;
                py[cnt]=j;
                cnt++;
            }
        }
    }
    for(int i=0;i<cnt;i++){
        for(int j=py[i];j<=m;j++){
            vcl[px[i]][j]|=(1<<i);
        }
    }
    for(int i=0;i<bs;i++){
        scanf("%d",val+i);
    }
    int ans=0;
    queue<State> q;
    memset(bss,-1,sizeof(bss));
    bss[sx][sy][0][0][0]=0;
    q.push(State(sx,sy,0,0,0));
    while(q.size()){
        State now=q.front();
        q.pop();
        if(now.x==sx&&now.y==sy){
            if(now.bs==36){
                cerr<<now.ob<<endl;
            }
            int sum=0;
            for(int i=0;i<cnt;i++){
                if((now.ob>>i)&1){
                    if(i>=bs){
                        sum=-0x3f3f3f3f;
                        break;
                    }else{
                        sum+=val[i];
                    }
                }
            }
            ans=max(ans,sum-now.bs);
        }
        for(int i=0;i<4;i++){
            int nx=now.x+dx[i],ny=now.y+dy[i];
            if(nx<1||nx>n||ny<1||ny>m){
                continue;
            }
            if(s[nx][ny]!='.'){
                continue;
            }
            int obs=now.ob;
            if(i==2){
                obs^=vcl[nx][ny];
            }
            if(i==0){
                obs^=vcl[now.x][now.y];
            }
            if(bss[nx][ny][obs][i][now.qfx]==-1){
                bss[nx][ny][obs][i][now.qfx]=now.bs+1;
                State nnow(nx,ny,obs,i,now.qfx);
                nnow.bs=now.bs+1;
                q.push(nnow);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}