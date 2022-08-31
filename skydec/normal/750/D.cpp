#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=315;
int dx[8]={0,1,1,1,0,-1,-1,-1};
int dy[8]={1,1,0,-1,-1,-1,0,1};
bool vis[N][N][32][8];
bool hav[N][N];
int n,t[N];
void dfs(int x,int y,int s,int d){
    if(s>=n)return;
    if(vis[x][y][s][d])return;
    vis[x][y][s][d]=1;
    rep(i,1,t[s+1]){
        x+=dx[d];
        y+=dy[d];
        hav[x][y]=1;
    }
    dfs(x,y,s+1,(d+1)%8);
    dfs(x,y,s+1,(d+7)%8);
}
int main(){
    scanf("%d",&n);
    rep(i,1,n)scanf("%d",&t[i]);
    dfs(155,155,0,0);
    int ans=0;
    rep(i,0,310)rep(j,0,310)ans+=(int)hav[i][j];
    printf("%d\n",ans);
    return 0;
}