#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
#define maxn 200001
using namespace std;
typedef long long ll;
vector <int> h[maxn],b[maxn];
int n,a[maxn],p,q,pre[maxn],dep[maxn],mu[maxn];
ll cnt[maxn],ans[maxn],sz[maxn];
bool f[maxn];

void _union(int pos,int x,int y){
    if (x==y) return;
    if (dep[x]<dep[y]) swap(x,y);
    cnt[pos]-=sz[x]*(sz[x]+1);
    cnt[pos]-=sz[y]*(sz[y]+1);
    pre[y]=x; sz[x]+=sz[y];
    if (dep[x]==dep[y]) dep[x]++;
    cnt[pos]+=sz[x]*(sz[x]+1);
}

int ffind(int x){
    if (pre[x]!=x) pre[x]=ffind(pre[x]);
    return pre[x];
}

int main(){
    cin >> n;
    mu[1]=1;
    for (int i=1;i<maxn;i++)
        for (int j=2;j*i<maxn;j++) mu[i*j]-=mu[i];
    for (int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        for (int j=1;j*j<=a[i];j++) if (a[i]%j==0){
            b[j].push_back(i);
            if (j*j<a[i]) b[a[i]/j].push_back(i);
        }
    }
    for (int i=1;i<n;i++){
        int u,v; scanf("%d%d",&u,&v);
        h[u].push_back(v);
        h[v].push_back(u);
    }
    for (int i=1;i<=n;i++) pre[i]=i,sz[i]=1;
    for (int i=1;i<maxn;i++){
        cnt[i]=b[i].size()*2;
        for (int j=0;j<b[i].size();j++){
            int u=b[i][j]; f[u]=true;
            for (int k=0;k<h[u].size();k++){
                int v=h[u][k];
                if (!f[v]) continue;
                _union(i,ffind(u),ffind(v));
            }
        }
        for (int j=0;j<b[i].size();j++){
            int u=b[i][j];
            f[u]=false; sz[u]=1; pre[u]=u;
        }
    }
    for (int i=1;i<maxn;i++) for (int j=1;i*j<maxn;j++) ans[i]+=mu[j]*cnt[i*j];
    for (int i=1;i<maxn;i++) if (ans[i]){
        printf("%d %lld\n",i,ans[i]/2);
    }
    return 0;
}