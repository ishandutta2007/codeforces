#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define x0 fuckxjb
#define y0 fuxkcjb
#define x1 fxckcjb
#define y1 fuckcxb
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=1e5+5,MOD=998244353,inf=0x3f3f3f3f;
const ld eps=1e-9;
int n,k;
int b[N],v[N<<1],f[N<<1],d[N],tot;
void add(int x,int y){
    v[++tot]=y,f[tot]=b[x],b[x]=tot,++d[x];
}
int q[N],l,r;
int dis[N];
bool check(int pos,int fa,int cur){
   // printf("%d %d\n",pos,cur);
    if(cur<0)return 0;
    int cnt=0;
    for(int i=b[pos];i;i=f[i])if(v[i]!=fa){
        ++cnt;
        if(!check(v[i],pos,cur-1))return 0;
    }
    if(cur==0)return cnt==0;
    if(cnt<3)return 0;
    return 1;
}
int main(){
    scanf("%d%d",&n,&k);
    rep(i,n-1){
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y),add(y,x);
    }
    l=r=0;
    memset(dis,0x3f,sizeof dis);
    rep(i,n)if(d[i]==1)q[++r]=i,dis[i]=0;
    while(l!=r){
        int x=q[++l];
        for(int i=b[x];i;i=f[i])if(dis[v[i]]>dis[x]+1)
            dis[q[++r]=v[i]]=dis[x]+1;
    }
    int top=q[l];//printf("%d\n",top);
    if(check(top,0,k))puts("Yes");else puts("No");
    return 0;
}