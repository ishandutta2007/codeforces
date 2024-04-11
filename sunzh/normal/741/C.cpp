#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
    return f==-1?~x+1:x;
}
int n;
vector<int>vec[1000010];
int col[1000010];
PII a[1000010];
void fail(){
    printf("Impossible\n");exit(0);
}
void dfs(int x){
    for(int v:vec[x]){
        if(col[v]==-1) col[v]=col[x]^1,dfs(v);
        else if(col[v]==col[x]) fail();
    }
}
int main(){
    n=read();
    for(int i=1;i<=2*n;i+=2) vec[i].pb(i+1),vec[i+1].pb(i);
    for(int i=1;i<=n;++i){
        int x=read(),y=read();a[i]=mp(x,y);vec[x].pb(y);vec[y].pb(x);
    }
    memset(col,-1,sizeof(col));
    for(int i=1;i<=2*n;++i) if(col[i]==-1) col[i]=0,dfs(i);
    for(int i=1;i<=n;++i){
        printf("%d %d\n",col[a[i].fi]+1,col[a[i].se]+1);
    }
    return 0;
}