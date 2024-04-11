#include <stdio.h>
#include <vector>
using namespace std;

#define M 100001
#define inf 1100000000
vector<int> con[M],wei[M];
int go[20][M];
int pnt[M];
int fa[M];
int dep[M];
int erase(int u,int rt){
    int k=0;
    for(int i=0;i<con[u].size();i++){
        int v=con[u][i];
        if(v==rt) continue;
        int tmp=erase(v,u);
        if(tmp){
            con[u][k]=v;
            wei[u][k]=wei[u][i];
            k++;
        }
    }
    con[u].resize(k);
    wei[u].resize(k);
    if(pnt[u]) k++;
    return k;
}
int nod[M],dis[M];
int dfs(int u,int rt){
    fa[u]=rt;
    dep[u]=dep[rt]+1;
    if(con[u].empty()){
        nod[u]=u;
        dis[u]=0;
        return 0;
    }
    int mx=0;
    int cnt=0;
    int snod;
    for(int i=0;i<con[u].size();i++){
        int v=con[u][i];
        if(v==rt) continue;
        int dis=dfs(v,u)+wei[u][i];
        if(dis>mx){
            mx=dis;
            cnt=0;
            snod=nod[v];
        }
        if(dis==mx){
            cnt++;
        }
    }
    if(cnt>1) nod[u]=u;
    else nod[u]=snod;
    dis[u]=mx;
    return mx;
}
int sum[M];
void insert(int u,int v,int ans){
    sum[u]++;
    sum[v]++;
    sum[ans]--;
    if(fa[ans]) sum[fa[ans]]--;
}

void look(int u,int rt,int mx,int cnod,int ans){
    if(mx<0 && pnt[u]){
        mx=0;
        cnod=u;
        ans=u;
    }
    if(pnt[u]){
        if(dis[u]>mx) insert(u,nod[u],u);
        else if(dis[u]==mx) insert(u,u,u);
        else insert(u,cnod,ans);
    }
    int sto[4],sn=0;
    for(int i=0;i<con[u].size();i++){
        int v=con[u][i];
        if(v==rt) continue;
        int j;
        for(j=0;j<sn;j++){
            int tj=sto[j];
            if(dis[v]+wei[u][i]>dis[con[u][tj]]+wei[u][tj]) break;
        }
        for(int k=sn-1;k>=j;k--) sto[k+1]=sto[k];
        sto[j]=i;
        sn++;
        if(sn>3) sn=3;
    }


    for(int i=0;i<con[u].size();i++){
        int v=con[u][i];
        if(v==rt) continue;

        int smx=-inf;
        int j;
        int cnt=0;
        int sj;
        for(j=0;j<sn;j++){
            int tj=sto[j];
            if(tj==i) continue;
            int tdis=dis[con[u][tj]]+wei[u][tj];
            if(smx<tdis){
                smx=tdis;
                cnt=0;
                sj=tj;
            }
            if(smx==tdis){
                cnt++;
            }
        }
        if(smx>mx){
            if(cnt>1){
                look(v,u,smx+wei[u][i],u,u);
            }
            else{
                look(v,u,smx+wei[u][i],nod[con[u][sj]],u);
            }
        }
        else if(smx==mx){
            look(v,u,smx+wei[u][i],u,u);
        }
        else{
            look(v,u,mx+wei[u][i],cnod,ans);
        };
    }

}
void calc(int u,int rt){
    for(int i=0;i<con[u].size();i++){
        int v=con[u][i];
        if(v==rt) continue;
        calc(v,u);
        sum[u]+=sum[v];
    }
}
int main(){
    //freopen("ee.in","r",stdin);
    int n,m,a,i,j,k,b,c;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d",&a);
        pnt[a]=1;
    }

    for(i=0;i<n-1;i++){
        scanf("%d %d %d",&a,&b,&c);
        con[a].push_back(b);
        con[b].push_back(a);
        wei[a].push_back(c);
        wei[b].push_back(c);

    }
    erase(1,0);
    dfs(1,0);
    for(i=1;i<=n;i++) go[0][i]=fa[i];
    for(i=1;(1<<i)<=n;i++){
        for(j=1;j<=n;j++) go[i][j]=go[i-1][go[i-1][j]];
    }
    look(1,0,-inf,0,0);
    calc(1,0);
    int mx=-1;
    int cnt=0;
    for(i=1;i<=n;i++) if(!pnt[i]){
        if(mx<sum[i]){
            mx=sum[i];
            cnt=0;
        }
        if(mx==sum[i]) cnt++;
    }

    printf("%d %d\n",mx,cnt);
    //sorry;
}