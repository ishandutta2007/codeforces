#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int N=4e5+5;
inline int read(){
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
int n,m,k;
struct edge{
    int v,ne;
}e[N<<1];
int h[N],cnt;
inline void ins(int u,int v){
    cnt++;
    e[cnt].v=v;e[cnt].ne=h[u];h[u]=cnt;
    cnt++;
    e[cnt].v=u;e[cnt].ne=h[v];h[v]=cnt;
}
int vis[N];
int a[N<<1],p;
void dfs(int u){
    vis[u]=1;
    a[++p]=u;
    for(int i=h[u];i;i=e[i].ne) 
        if(!vis[e[i].v]) dfs(e[i].v),a[++p]=u;
}
int main(){
    //freopen("in","r",stdin);
    n=read();m=read();k=read();
    for(int i=1;i<=m;i++) ins(read(),read());
    dfs(1);
    int c=ceil((double)2*n/k);
    int x=p/c,y=p%c,now=0;
    for(int i=1;i<=k;i++){
        if(i<=x){
            printf("%d ",c);
            for(int j=i;j<=i+c-1;j++) printf("%d ",a[++now]);
        }else if(i==x+1&&y!=0){
            printf("%d ",y);
            for(int j=1;j<=y;j++) printf("%d ",a[++now]);
        }else printf("1 1");
        puts("");
    }
    return 0;
}