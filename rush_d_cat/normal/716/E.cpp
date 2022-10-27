#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;
const int N=100000+10;
vector< pair<int,int> > g[N]; vector<int> miao;
int n,m,sz[N],mx[N],conquered[N];
LL po[N];
void dfs_miao(int u,int p){
    miao.push_back(u); sz[u]=1,mx[u]=0;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i].first; if(v==p||conquered[v])continue;
        dfs_miao(v,u);
        sz[u]+=sz[v]; mx[u]=max(mx[u],sz[v]);
    }
}
int getRoot(int u){
    miao.clear(); dfs_miao(u,u);
    int minsize=N, root=0;
    for(auto x: miao){
        mx[x]=max(mx[x],sz[u]-sz[x]);
        if(mx[x]<minsize){
            minsize=mx[x]; root=x;
        }
    } return root;
}
map<int,int> mp; vector< pair< pair<int,int> ,int> > nod; 
void dfs_init(int u,int p,int dep,LL val1,LL val2){
    nod.push_back(make_pair(make_pair(val1,val2),dep));
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i].first; if(v==p||conquered[v])continue;
        dfs_init(v,u,dep+1,(val1*10+g[u][i].second)%m,(val2+po[dep]*g[u][i].second)%m);
    }
}
LL ans=0;
LL mpow(LL a,LL x,LL mod) {
    if(x==0)return 1%mod;
    LL t=mpow(a,x>>1,mod);
    if(x%2==0)return t*t%mod;
    return t*t%mod*a%mod;
}
int P;LL inv[N];
void Excalibur(int u,int p,int dep,int v1,int v2,int sgn){
    nod.clear(); dfs_init(u,p,dep,v1,v2); 
    LL tmp=0; 
    mp.clear(); for(auto p: nod) mp[p.first.second]++;

    for(auto p:nod) {
        LL need = (m-p.first.first)%m * inv[p.second] % m;
        tmp += mp[need]; if(p.first.second==need) tmp--;
        //printf("v1=%d v2=%d dep=%d need=%lld\n", p.first.first,p.first.second,p.second,need);
    }
    //printf("tmp=%lld\n", tmp);
    ans += tmp*sgn; 
}   

void divide_and_conquered(int u){
    u=getRoot(u); conquered[u]=1;
    Excalibur(u,u,0,0,0,+1);
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i].first; if(conquered[v])continue;
        Excalibur(v,u,1,g[u][i].second%m,g[u][i].second%m,-1);
        divide_and_conquered(v);
    }
}
int phi(int x) {
    int ans=x;
    for(int i=2;i*i<=x;i++) {
        int t=i;
        if(x%t==0) {
            ans=ans/t*(t-1); while(x%t==0)x/=t;
        }
    }
    if(x>1)ans=ans/x*(x-1);
    return ans;
}
int main(){
    //printf("%d\n", phi(14));
    scanf("%d%d",&n,&m); P=phi(m);
    po[0]=1; for(int i=1;i<N;i++)po[i]=po[i-1]*10%m;
    inv[0]=1; for(int i=1;i<N;i++)inv[i]=mpow(po[i],P-1,m);
    for(int i=1;i<n;i++){
        int u,v,w; scanf("%d%d%d",&u,&v,&w); u++,v++;
        g[u].push_back(make_pair(v,w));
        g[v].push_back(make_pair(u,w));
    }
    if(m==1) {
        ans = 1LL*n*(n-1);
    } else {
        divide_and_conquered(1);
    }
    cout<<ans<<endl;
}