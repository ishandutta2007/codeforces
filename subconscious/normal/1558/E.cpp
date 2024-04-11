#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
#define x0 fuckhel
#define y0 fuckoscar
#define x1 fucksub
#define y1 fuckzzy
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=2005;
int a[N],b[N],n,m;
vector<int> g[N];
bool in[N],is[N];
ll now;

bool dfs(int x,int fa,ll tmp){
    //printf("%d %d %lld\n",x,fa,tmp);
    is[x]=1;
    for(int v:g[x]){
        if(v==fa)continue;
        if(!is[v]){
            if(a[v]>=tmp)continue;
            if(dfs(v,x,tmp+(in[v]?0:b[v]))){
                in[x]=1;
                return 1;
            }
        }else if(tmp>now){
            in[x]=1;
            now=tmp;
            return 1;
        }
    }
    return 0;
}
int T;
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d%d",&n,&m);
        for(int i=2;i<=n;++i)scanf("%d",a+i);
        for(int i=2;i<=n;++i)scanf("%d",b+i);
        rep(i,n)g[i].clear();
        rep(i,m){
            int x,y;scanf("%d%d",&x,&y);
            g[x].pb(y),g[y].pb(x);
        }
        ll l=-1,r=1e9+1;
        while(l+1<r){
            ll mid=(l+r)/2;
            rep(i,n)in[i]=0;
            in[1]=1;

            now=mid;
            for(;;){
                rep(i,n)is[i]=0;
                if(!dfs(1,0,now))break;
            }

            bool flag=1;
            rep(i,n)if(!in[i]){flag=0;break;}
            if(flag)r=mid;else l=mid;
        }  
        printf("%lld\n",r);     
    }
    return 0;
}
/*
1
5 6

1 1 10 10
5 5 10 10
1 2
1 3
2 3
1 4
1 5
4 5

*/