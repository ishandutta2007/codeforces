#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=110000;
struct node{
    int l,r;
    int tou[6],wei[6];
    int ans;
    void unit(int x){
        l=r=x;
        memset(tou,0,sizeof tou);
        memset(wei,0,sizeof wei);
        tou[1]=wei[1]=1;
        ans=0;
    }
};
int fa[22];int k;
int id[22];
int get(int x){
    if(x==fa[x])return x;
    return fa[x]=get(fa[x]);
}
bool edge[N][10];
inline node operator +(node a,node b){
    node c;
    int lv=0;
    rep(i,1,5)lv=max(lv,max(a.tou[i],a.wei[i]));
    int lv2=0;
    rep(i,1,5)lv2=max(lv2,max(b.tou[i],b.wei[i]));
    int M=lv+lv2;
    rep(i,1,5){
        if(b.tou[i])b.tou[i]+=lv;
        if(b.wei[i])b.wei[i]+=lv;
    }
    rep(i,1,M)fa[i]=i;
    rep(i,1,M)id[i]=0;
    int ans=a.ans+b.ans;
    rep(i,1,5)if(a.wei[i])rep(j,1,k-i+1)if(b.tou[j])if(edge[a.r-i+1][i+j-1]){
        if(get(a.wei[i])!=get(b.tou[j])){
            fa[get(a.wei[i])]=get(b.tou[j]);
            ++ans;
        }
    }
    int gt=0;
    rep(i,1,5){
        if(a.tou[i])c.tou[i]=a.tou[i];
        else if((i-(a.r-a.l+1))>=1&&(i-(a.r-a.l+1))<=5)c.tou[i]=b.tou[i-(a.r-a.l+1)];
        else c.tou[i]=0;

        if(b.wei[i])c.wei[i]=b.wei[i];
        else if((i-(b.r-b.l+1))>=1&&(i-(b.r-b.l+1))<=5)c.wei[i]=a.wei[i-(b.r-b.l+1)];
        else c.wei[i]=0;
    }
    rep(i,1,5){
        if(c.tou[i]){
            c.tou[i]=get(c.tou[i]);
            if(!id[c.tou[i]])id[c.tou[i]]=++gt;
            c.tou[i]=id[c.tou[i]];
        }
    }
    rep(i,1,5){
        if(c.wei[i]){
            c.wei[i]=get(c.wei[i]);
            if(!id[c.wei[i]])id[c.wei[i]]=++gt;
            c.wei[i]=id[c.wei[i]];
        }
    }
    c.l=a.l;
    c.r=b.r;
    c.ans=ans;
    return c;
}
node mes[N<<2];
int n,Q;
void build(int me,int l,int r){
    if(l==r){
        mes[me].unit(l);
        return;
    }
    int mid=(l+r)>>1;
    build(me<<1,l,mid);
    build(me<<1|1,mid+1,r);
    mes[me]=mes[me<<1]+mes[me<<1|1];
}
node ask(int me,int l,int r,int x,int y){
    if(x<=l&&r<=y)return mes[me];
    int mid=(l+r)>>1;
    if(x<=mid&&y>mid)return ask(me<<1,l,mid,x,y)+ask(me<<1|1,mid+1,r,x,y);
    if(x<=mid)return ask(me<<1,l,mid,x,y);
    else return ask(me<<1|1,mid+1,r,x,y);
}
int main(){
    scanf("%d%d",&n,&k);
    int m;scanf("%d",&m);
    while(m--){
        int u,v;scanf("%d%d",&u,&v);
        if(u>v)swap(u,v);
        edge[u][v-u]=1;
    }
    build(1,1,n);
    scanf("%d",&Q);
    while(Q--){
        int l,r;scanf("%d%d",&l,&r);
        r=min(r,n);
        if(l>r){
            printf("0\n");
            continue;
        }
        printf("%d\n",r-l+1-ask(1,1,n,l,r).ans);
    }
    return 0;
}