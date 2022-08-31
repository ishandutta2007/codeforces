#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=110000;
int n,k;
int b[N];
int rmq[17][N];
int LB[N*5];
int rmqAsk(int l,int r){
    return min(rmq[LB[r-l+1]][l],rmq[LB[r-l+1]][r-(1<<(LB[r-l+1]))+1]);
}
int daAsk(int l,int r){
    if(r-l+1>=n)return rmqAsk(1,n);
    if((l-1)/n==(r-1)/n){
        return rmqAsk((l-1)%n+1,(r-1)%n+1);
    }
    return min(rmqAsk((l-1)%n+1,n),rmqAsk(1,(r-1)%n+1));
}
void init_b(){
    rep(i,1,n)scanf("%d",&b[i]);
    rep(i,1,n)rmq[0][i]=b[i];
    rep(j,1,16)rep(i,1,n-(1<<j)+1)rmq[j][i]=min(rmq[j-1][i],rmq[j-1][i+(1<<(j-1))]);
    rep(j,1,16)rep(i,(1<<j),(1<<(j+1))-1)LB[i]=j;
}
int rt=0;
int cl[N*110],cr[N*110],tag[N*110],mi[N*110],tot;
inline void hav(int &me,int l,int r){
    if(!me){
        me=++tot;
        mi[me]=daAsk(l,r);
    }
}
inline void update(int &me,int l,int r){
    int mid=(l+r)>>1;
    hav(cl[me],l,mid);
    hav(cr[me],mid+1,r);
    mi[me]=min(mi[cl[me]],mi[cr[me]]);
}
inline void cov(int &me,int l,int r,int w){
    hav(me,l,r);
    tag[me]=mi[me]=w;
}
inline void down(int &me,int l,int r){
    if(!tag[me])return;
    int mid=(l+r)>>1;
    cov(cl[me],l,mid,tag[me]);
    cov(cr[me],mid+1,r,tag[me]);
    tag[me]=0;
}
void segCov(int &me,int l,int r,int x,int y,int v){
    hav(me,l,r);
    if(l^r)down(me,l,r);
    if(x<=l&&r<=y){
        cov(me,l,r,v);
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid)segCov(cl[me],l,mid,x,y,v);
    if(y>mid)segCov(cr[me],mid+1,r,x,y,v);
    update(me,l,r);
}
int segAsk(int &me,int l,int r,int x,int y){
    hav(me,l,r);
    if(l^r)down(me,l,r);
    if(x<=l&&r<=y)return mi[me];
    int res=1<<30;
    int mid=(l+r)>>1;
    if(x<=mid)res=min(res,segAsk(cl[me],l,mid,x,y));
    if(y>mid)res=min(res,segAsk(cr[me],mid+1,r,x,y));
    return res;
}
int main(){
    scanf("%d%d",&n,&k);
    init_b();
    int Q;scanf("%d",&Q);
    while(Q--){
        int ty,l,r;scanf("%d%d%d",&ty,&l,&r);
        if(ty==1){
            int x;scanf("%d",&x);
            segCov(rt,1,n*k,l,r,x);
        }
        else{
            printf("%d\n",segAsk(rt,1,n*k,l,r));
        }
    }
    return 0;
}