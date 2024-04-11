#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=1230000;
int ST;
int n,m,Q;
char s[N];
int pos[N];
int go[N][27],fail[N],len[N],tot=1,last=1,rrr[N];
int head[N],np[N],p[N],stot;
inline void addedge(int a,int b){
    ++stot;p[stot]=b;np[stot]=head[a];head[a]=stot;
}
int add(int x,int rr){
    int me=++tot;
    len[me]=len[last]+1;
    int p=last;last=tot;
    rrr[me]=rr;
    for(;p&&(!go[p][x]);p=fail[p])go[p][x]=me;
    if(!p){
        fail[me]=1;
        return me;
    }
    int gt=go[p][x];
    if(len[gt]==len[p]+1){
        fail[me]=gt;
        return me;
    }
    int np=++tot;
    len[np]=len[p]+1;
    rep(i,0,26)go[np][i]=go[gt][i];
    fail[np]=fail[gt];
    fail[gt]=fail[me]=np;
    for(;p&&(go[p][x]==gt);p=fail[p])go[p][x]=np;
    return me;
}
//seg
int root[N],cl[N*25],cr[N*25];
pii ans[N*25];
int segtot;
void segadd(int &me,int l,int r,int x){
    if(!me)me=++segtot;
    if(l==r){
        ans[me].fi=l;
        ans[me].se++;
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid)segadd(cl[me],l,mid,x);
    else segadd(cr[me],mid+1,r,x);
    if(ans[cr[me]].se>ans[cl[me]].se)ans[me]=ans[cr[me]];
    else ans[me]=ans[cl[me]];
}
pii Ask(int me,int l,int r,int x,int y){
    if(!me)return pii(max(l,x),0);
    if(x<=l&&r<=y)return ans[me];
    int mid=(l+r)>>1;
    pii res=pii(10000000,0);
    if(x<=mid){
        pii gt=Ask(cl[me],l,mid,x,y);
        if((gt.se>res.se)||(gt.se==res.se&&gt.fi<res.fi))res=gt;
    }
    if(y>mid){
        pii gt=Ask(cr[me],mid+1,r,x,y);
        if((gt.se>res.se)||(gt.se==res.se&&gt.fi<res.fi))res=gt;
    }
    return res;
}
int merge(int x,int y,int l,int r){
    if(!x||!y)return x+y;
    int me=++segtot;
    if(l==r){
        ans[me]=pii(ans[x].fi,ans[x].se+ans[y].se);
        return me;
    }
    int mid=(l+r)>>1;
    cl[me]=merge(cl[x],cl[y],l,mid);
    cr[me]=merge(cr[x],cr[y],mid+1,r);
    if(ans[cr[me]].se>ans[cl[me]].se)ans[me]=ans[cr[me]];
    else ans[me]=ans[cl[me]];
    return me;
}
void dfs(int x){
    //printf("ST %d\n",x);
    if(rrr[x])segadd(root[x],1,m,rrr[x]);
    //if(rrr[x])printf("%d %d\n",x,rrr[x]);
    for(int u=head[x];u;u=np[u]){
        dfs(p[u]);
        root[x]=merge(root[x],root[p[u]],1,m);
    }
    //printf("ED %d\n",x);
}
int fa[7][N];
int findnode(int x,int lp){
    per(i,6,0)rep(j,1,9)if(fa[i][x])if(len[fa[i][x]]>=lp)x=fa[i][x];
    return x;
}
//seg
int ED;
int main(){
    //printf("%d MB\n",((&ED)-(&ST))/250000);
    scanf("%s",s+1);n=strlen(s+1);
    rep(i,1,n)pos[i]=add(s[i]-'a',0);
    //rep(i,1,n)printf("pos[%d]=%d\n",i,pos[i]);
    //rep(i,1,tot)printf("%d ",fail[i]);puts("");
    add(26,0);
    scanf("%d",&m);
    rep(i,1,m){
        scanf("%s",s+1);
        int len=strlen(s+1);
        rep(j,1,len)add(s[j]-'a',i);
        add(26,0);
    }
    rep(i,1,tot)if(fail[i])addedge(fail[i],i);
    rep(i,1,tot)fa[0][i]=fail[i];
    rep(j,1,6)rep(i,1,tot){
        fa[j][i]=i;
        rep(t,1,10)fa[j][i]=fa[j-1][fa[j][i]];
    }
    dfs(1);
    scanf("%d",&Q);
    while(Q--){
        int l,r,pl,pr;
        scanf("%d%d%d%d",&l,&r,&pl,&pr);
        int xx=findnode(pos[pr],pr-pl+1);
        pii ans=Ask(root[xx],1,m,l,r);
        printf("%d %d\n",ans.fi,ans.se);
    }
    return 0;
}