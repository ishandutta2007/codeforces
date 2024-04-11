#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=300100;
int go[N][26];
int dep[N],fa[N];
int n;
int sz[N];
int head[N],np[N<<1],p[N<<1],w[N<<1],tot;
inline void add(int a,int b,int c){
    ++tot;p[tot]=b;np[tot]=head[a];head[a]=tot;w[tot]=c;
    ++tot;p[tot]=a;np[tot]=head[b];head[b]=tot;w[tot]=c;
}
vector<int>hu[N];
void dfs(int x){
    sz[x]=1;
    hu[dep[x]].push_back(x);
    for(int u=head[x];u;u=np[u])if(p[u]^fa[x]){
        fa[p[u]]=x;go[x][w[u]]=p[u];dep[p[u]]=dep[x]+1;
        dfs(p[u]);sz[x]+=sz[p[u]];
    }
}
int res=n;
int stk[N][2];
int t;
void initstk(){
    t=0;
}
int dg;
void reback(){
    rep(i,1,t){
        go[stk[i][0]][stk[i][1]]=0;
    }
}
void insit(int x,int y){
    res--;
    rep(i,0,25)if(go[x][i]||go[y][i]){
        if(go[x][i]&&go[y][i])insit(go[x][i],go[y][i]);
        else if(!go[x][i]){
            go[x][i]=go[y][i];
            ++t;stk[t][0]=x;stk[t][1]=i;
        }
        else if(!go[y][i]){
            continue;
        }
        else assert(0);
    }
}
int calc(int dp){
    dg=dp;
    res=n;
    initstk();
    rep(i,0,hu[dp].size()-1){
        int x=hu[dp][i];
        int pre=0;
        int presz=0;
        rep(i,0,25)if(go[x][i]){
            int y=go[x][i];
            if(!pre){
                pre=y;
                presz=sz[y];
            }
            else{
                if(sz[y]>presz){
                    insit(y,pre);
                    presz+=sz[y];
                    pre=y;
                }
                else{
                    insit(pre,y);
                    presz+=sz[y];
                }
            }
        }
        if(pre)--res;
    }
    reback();
    return res;
}
int main(){
    scanf("%d",&n);
    rep(i,1,n-1){
        int a,b;char c[3];
        scanf("%d%d",&a,&b);
        scanf("%s",c+1);
        add(a,b,c[1]-'a');
    }
    dfs(1);
    int ans0=0;
    int ans1=n+100;
    rep(i,0,n)if(hu[i].size()){
        int vv=calc(i);
        if(vv<ans1){
            ans1=vv;
            ans0=i+1;
        }
    }
    printf("%d\n%d\n",ans1,ans0);
    return 0;
}