#include <bits/stdc++.h>
#define rep(i,n) for(long long i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define x0 fuckcjb
#define y0 fuckyzc
#define x1 fuckshb
#define y1 fuckhel
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=1e6+5,mod=1e9+7;
vector<int>a[N],b[N];
int n;
int db[N],revb[N],tob[N],topb;
void dfsb(int x){
    db[++topb]=x;
    revb[x]=topb;
    for(int v:b[x])
        dfsb(v);
    tob[x]=topb;
}
int ans;
ll t[2][N];
void add(ll t[],int p,int x){
    for(;p<=n+1;p+=p&-p)t[p]+=x;
}
ll que(ll t[],int p){
    int s=0;
    for(;p;p-=p&-p)s+=t[p];
    return s;
}
void dfsa(int x,int now){
    //printf("x:%d\n",x);
    int siz=que(t[0],tob[x])-que(t[0],revb[x]-1),flag=0,fk=0;
    //printf("siz:%d %d %d\n",revb[x],tob[x],siz);
    if(siz>0)flag=1;
    else{
        fk=que(t[1],revb[x]);
        if(fk>0){
            add(t[0],revb[fk],-1);
            add(t[1],revb[fk],-fk);
            add(t[1],tob[fk]+1,fk);
        }
        add(t[0],revb[x],1);
        add(t[1],revb[x],x);
        add(t[1],tob[x]+1,-x);
    }
    if(flag==0&&fk==0)++now;
    ans=max(ans,now);
    for(int v:a[x])
        dfsa(v,now);
    if(flag==0&&fk==0)--now;
    if(flag==0){
        add(t[0],revb[x],-1);
        add(t[1],revb[x],-x);
        add(t[1],tob[x]+1,x);
        if(fk>0){
            add(t[0],revb[fk],1);
            add(t[1],revb[fk],fk);
            add(t[1],tob[fk]+1,-fk);
        }
    }
}
int T;
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d",&n);
        rep(i,n+1)a[i].clear(),b[i].clear(),t[0][i]=t[1][i]=0;
        for(int i=2;i<=n;++i){
            int x;scanf("%d",&x);
            a[x].pb(i);
        }
        for(int i=2;i<=n;++i){
            int x;scanf("%d",&x);
            b[x].pb(i);
        }
        topb=0;dfsb(1);
        ans=0;
        dfsa(1,0);
        printf("%d\n",ans);
    }
    return 0;
}