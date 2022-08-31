#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define trav(a,x) for(auto&a:x)
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
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
typedef vector<int> vi;
const int N=53,mod=1e9+7;
int n,k;
int d[N],a[N][N];
vector<pr>tmp;
set<pr>edge;
int siz[N];
vi g[N];
int f[N];
int fa(int x){return f[x]==x?x:f[x]=fa(f[x]);}
 
int dif;pr del,ad;
int f2[N];
void dfs(int x,int fat){
    f2[x]=fat;
    for(int v:g[x])if(v!=fat){
        dfs(v,x);
    }
}
int main(){
    scanf("%d%d",&n,&k);
    rep(i,k)scanf("%d",d+i);
    rep(i,n)for(int j=i+1;j<=n;++j)
        scanf("%d",a[i]+j),a[j][i]=a[i][j];
    rep(i,n)for(int j=i+1;j<=n;++j)
        tmp.pb(mp(i,j));
    int ans=mod;
    rep(tim,100){
        //printf("tim:%d\n",tim);
        int now=0;
        rep(i,n)f[i]=i;
        edge.clear();
        rep(i,n)siz[i]=0;
        random_shuffle(all(tmp));
        while((int)edge.size()<n-1){
            trav(p,tmp){
                if(p.st<=k&&siz[p.st]==d[p.st])continue;
                if(p.nd<=k&&siz[p.nd]==d[p.nd])continue;
                if(p.st<=k&&p.nd<=k&&siz[p.st]==d[p.st]-1&&siz[p.nd]==d[p.nd]-1)continue;
                int x=fa(p.st),y=fa(p.nd);
                if(x==y)continue;
                f[x]=y;
                now+=a[p.st][p.nd];
                ++siz[p.st];++siz[p.nd];
                edge.insert(p);
                //printf("add:%d %d\n",p.st,p.nd);
            }
        }
        //printf("%d\n",now);
        //i<j!!!
        a[0][0]=-mod;
        int cnt0=0;
        for(;;){
            rep(i,n)g[i].clear();
            trav(p,edge)
                g[p.st].pb(p.nd),g[p.nd].pb(p.st);
            rep(i,n)siz[i]=g[i].size();
            dif=mod;
            rep(i,n){
                dfs(i,0);
                rep(j,n){
                    int kk=j;
                    while(kk!=i){
                        bool flag=0;
                        --siz[kk];--siz[f2[kk]];
                        ++siz[i];++siz[j];
                        rep(p,k)if(siz[p]>d[p]){flag=1;break;}
                        ++siz[kk];++siz[f2[kk]];
                        --siz[i];--siz[j];
                        if(!flag&&dif>=a[i][j]-a[kk][f2[kk]]){
                            dif=a[i][j]-a[kk][f2[kk]];
                            del=mp(min(kk,f2[kk]),max(kk,f2[kk]));
                            ad=mp(min(i,j),max(i,j));
                        }
                        kk=f2[kk];
                    }
                }
            }
            if(dif<=0){
                if(dif==0)++cnt0;else cnt0=0;
                if(cnt0==10)break;
                now+=dif;
                edge.erase(del);
                edge.insert(ad);
            }else break;
        }
        ans=min(ans,now);
    }
    
    //trav(p,edge)printf("%d %d %d\n",p.st,p.nd,a[p.st][p.nd]);
    printf("%d\n",ans);
    return 0;
}
/*
3 2
1 1
1 30
38

1-3 1-4 2-3
*/