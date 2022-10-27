#include <iostream>
#include <vector>
using namespace std;
const int N=300000+10;
int n,k;
char s[N];
vector<int> v[N],has[N];
int par[N],dis[N],cerdis[N],sz[N][2];
int ans=0;
int find(int x){
    if(par[x]==x) return x;
    int p=par[x];
    par[x]=find(p);
    dis[x]=dis[p]^dis[x];
    return par[x];
}
void assert_(int x,bool flag){
    //printf("assert_ %d %d\n", x, flag);
    int p=find(x);
    if(cerdis[p]!=-1) return;
    if(flag==1){
        ans -= min(sz[p][0],sz[p][1]);
        cerdis[p]=dis[x];
        //printf("cerdis[%d] = %d\n", x, dis[x]);
        ans += sz[p][cerdis[p]];
    } else {
        ans -= min(sz[p][0],sz[p][1]);
        cerdis[p]=dis[x]^1;
        ans += sz[p][cerdis[p]];
    }
}
void unite(int x,int y,bool flag){
    //printf("unite %d %d %d\n", x,y,flag);
    int px=find(x);
    int py=find(y);
    //printf("px = %d, py = %d\n", px, py);
    if(px==py) return;

    if(cerdis[px]==-1) {
        ans-=min(sz[px][0],sz[px][1]);
       // printf("1 ###  ans -= %d\n", min(sz[px][0],sz[px][1]));
    } else {
        ans-=sz[px][cerdis[px]];
        //printf("1 ###  ans -= %d\n", sz[px][cerdis[px]]);
    }
    //printf("# cerdis[%d] = %d\n", py,cerdis[py]);
    if(cerdis[py]==-1) {
        ans-=min(sz[py][0],sz[py][1]);
        //printf("2 ###  ans -= %d\n", min(sz[py][0],sz[py][1]));
    } else {
        ans-=sz[py][cerdis[py]];
        //printf("2 ###  ans -= %d\n", sz[py][cerdis[py]]);
    }

    bool newflag = 0;
    if (flag == 0) {
        newflag = 0^dis[x]^dis[y];
    } else {
        newflag = 1^dis[x]^dis[y];
    }
   // printf("px = %d, py = %d\n",px,py);
    // printf("newflag = %d\n", newflag);
    if(newflag==0){
        dis[px]=0; 
        sz[py][0]+=sz[px][0]; sz[py][1]+=sz[px][1];
        if(cerdis[px]==0) cerdis[py]=0;
        if(cerdis[px]==1) cerdis[py]=1;  
        par[px]=py;
    } else {
        dis[px]=1; 
        sz[py][0]+=sz[px][1]; sz[py][1]+=sz[px][0]; 
        if(cerdis[px]==0) cerdis[py]=1;
        if(cerdis[px]==1) cerdis[py]=0;  
        par[px]=py;
    }
   // printf("cerdis[py] = %d\n", cerdis[py]);
    if(cerdis[py]==-1) {
        ans+=min(sz[py][0],sz[py][1]);
        //printf("! ans += %d\n", min(sz[py][0], sz[py][1]));
    } else {
        ans+=sz[py][cerdis[py]];
        //printf("# ans += %d\n", sz[py][cerdis[py]]);
    }
}
int main() {
    for(int i=0;i<N;i++)par[i]=i,dis[i]=0,cerdis[i]=-1,sz[i][0]=1,sz[i][1]=0;
    scanf("%d%d%s",&n,&k,s+1);
    for(int i=1;i<=k;i++){
        int c; scanf("%d",&c);
        for(int j=1;j<=c;j++){
            int x; scanf("%d",&x); v[i].push_back(x);
            has[x].push_back(i);
        }
    }
    for(int i=1;i<=n;i++){//3->n
        bool need=(s[i]=='0'?1:0);
        //printf("i=%d, need=%d\n", i,need);
        if(need==0){
            if(has[i].size()==1){
                assert_(has[i][0],false);
            }
            if(has[i].size()==2){
                unite(has[i][0],has[i][1],0);
            }
        }
        if(need==1){
            if(has[i].size()==1){
                assert_(has[i][0],true);
            }
            if(has[i].size()==2){
                unite(has[i][0],has[i][1],1);
            }
        }
        printf("%d\n", ans);
    }
}