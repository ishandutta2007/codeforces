#include <iostream>
#include <algorithm>
using namespace std;
int x[1000],y[1000],has[1000][1000];
int dx[4]={+1,-1,+1,-1};
int dy[4]={+1,+1,-1,-1};
void upd(){
    printf("%d %d\n", x[0],y[0]); fflush(stdout);
    int k,r,c; scanf("%d%d%d",&k,&r,&c);
    if(k==-1 && r==-1 && c==-1) exit(0);
    has[x[k]][y[k]]=0;
    x[k]=r,y[k]=c;
    has[x[k]][y[k]]=1;
}
int main(){
    for(int i=0;i<=666;i++){
        scanf("%d%d",&x[i],&y[i]);
        if(i)has[x[i]][y[i]]=1;
    }
    while(!(x[0]==500 && y[0]==500)){
        if(x[0]<500) x[0]++;else if(x[0]>500) x[0]--;
        if(y[0]<500) y[0]++;else if(y[0]>500) y[0]--;
        upd();
    }
    int cnt[4]={0};
    for(int i=1;i<=666;i++){
        int state=0;
        if(x[i]>500) state |= 1;
        if(y[i]>500) state |= 2;
        cnt[state] ++;
    }
    int dir = min_element(cnt,cnt+4) - cnt;
    while(1){
        x[0]+=dx[dir],y[0]+=dy[dir]; 
        if(has[x[0]][y[0]]) x[0]-=dx[dir];
        upd();
    }
}