#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=410000;
int rs[N];
int pos[N],go[N][26],fail[N],len[N],tot=1,last=1;
int n;char a[N];
int f[N];
int head[N],np[N],p[N],stot;
int fa[20][N];
int add(int x){
    int np=++tot;len[np]=len[last]+1;int p=last;last=tot;
    for(;p&&!(go[p][x]);p=fail[p])go[p][x]=np;
    if(!p){
        fail[np]=1;
        return np;
    }
    int gt=go[p][x];
    if(len[gt]==len[p]+1){
        fail[np]=gt;
        return np;
    }
    int xx=++tot;
    len[xx]=len[p]+1;
    fail[xx]=fail[gt];
    rep(i,0,25)go[xx][i]=go[gt][i];
    fail[gt]=fail[np]=xx;
    for(;p&&go[p][x]==gt;p=fail[p])go[p][x]=xx;
    return np;
}
int cl[N*22],cr[N*22];
bool hav[N*22];
int segtot;
int root[N];
void segadd(int &me,int l,int r,int x){
    hav[me=++segtot]=1;
    if(l==r)return;
    int mid=(l+r)>>1;
    if(x<=mid)segadd(cl[me],l,mid,x);
    else segadd(cr[me],mid+1,r,x);
}
int merge(int a,int b){
    if(!a||!b)return a+b;
    int me=++segtot;
    hav[me]=hav[a]|hav[b];
    cl[me]=merge(cl[a],cl[b]);
    cr[me]=merge(cr[a],cr[b]);
    return me;
}
int findpre(int me,int l,int r,int x){
    if(!hav[me])return 0;
    if(l==r)return l*(l!=x);
    int mid=(l+r)>>1;
    if(x<=mid)return findpre(cl[me],l,mid,x);
    int xx=findpre(cr[me],mid+1,r,x);
    if(xx)return xx;
    else return findpre(cl[me],l,mid,x);
}
int dp(int x){
    int rr=findpre(root[x],1,n,n+1);
    int dt=x;
    per(i,19,0)if(fa[i][dt]){
        int y=fa[i][dt];
        int gt=findpre(root[y],1,n,rr);
        if(rr-gt+len[y]>len[x])dt=fa[i][dt];
    }
    dt=fa[0][dt];
    if(dt)f[x]=max(f[x],f[dt]+1);
    for(int u=head[x];u;u=np[u])dp(p[u]);
}
void gtw(int x){
    if(rs[x])segadd(root[x],1,n,rs[x]);
    for(int u=head[x];u;u=np[u]){
        gtw(p[u]);
        root[x]=merge(root[x],root[p[u]]);
    }
}
int main(){
    scanf("%d",&n);
    scanf("%s",a+1);
    rep(i,1,n)pos[i]=add(a[i]-'a');
    rep(i,1,n)rs[pos[i]]=i;
    rep(i,1,tot)if(i==1)f[i]=0;else f[i]=1;
    rep(i,1,tot)if(fail[i]){
        ++stot;p[stot]=i;np[stot]=head[fail[i]];head[fail[i]]=stot;
    }
    rep(i,1,tot)fa[0][i]=fail[i];
    rep(j,1,19)rep(i,1,tot)fa[j][i]=fa[j-1][fa[j-1][i]];
    gtw(1);
    dp(1);
    int ans=0;
    rep(i,1,tot)ans=max(ans,f[i]);
    printf("%d\n",ans);
    return 0;
}