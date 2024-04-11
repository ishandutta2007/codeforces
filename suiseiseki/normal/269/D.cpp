#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define test puts("OK");
#define inf 1000000000
#define lson (step<<1)
#define rson (step<<1|1)
using namespace std;
const int N=100005;
struct Wall{
    int h,l,r;
    Wall(){}
    Wall(int _h,int _l,int _r):h(_h),l(_l),r(_r){}
    bool operator<(const Wall w)const{
        return h<w.h;
    }
}wall[N];
struct Seg_Tree{
    int left,right;
    int val,all;
}L[N<<3];
int n,t;
int x[N<<1],cnt;
int dp[N]={0};
void Bulid(int step,int l,int r){
    L[step].left=l;
    L[step].right=r;
    L[step].val=L[step].all=-1;
    if(l==r) return ;
    int m=(l+r)>>1;
    Bulid(lson,l,m);
    Bulid(rson,m+1,r);
}
void Push_Down(int step){
    if(L[step].all!=-1){
        L[lson].all=L[rson].all=L[step].all;
        L[lson].val=L[rson].val=L[step].all;
        L[step].all=-1;
    }
}
void Push_Up(int step){
    L[step].val=max(L[lson].val,L[rson].val);
}
void Update(int step,int l,int r,int id){
    if(L[step].left==l&&L[step].right==r){
        L[step].val=L[step].all=id;
        return ;
    }
    Push_Down(step);
    int m=(L[step].left+L[step].right)>>1;
    if(r<=m) Update(lson,l,r,id);
    else if(l>m) Update(rson,l,r,id);
    else{
        Update(lson,l,m,id);
        Update(rson,m+1,r,id);
    }
    Push_Up(step);
}
int Query(int step,int l,int r){
    if(L[step].left==l&&L[step].right==r)
        return L[step].val;
    int m=(L[step].left+L[step].right)>>1;
    Push_Down(step);
    if(r<=m) return Query(lson,l,r);
    else if(l>m) return Query(rson,l,r);
    else return max(Query(lson,l,m),Query(rson,m+1,r));
}
void slove(int l,int r,int who,int can_l,int can_r){
    if(l>r) return ;
    int id=Query(1,l,r);
    if(id==-1){
        Update(1,l,r,who);
        dp[who]=x[r+1]-x[l];
        return;
    }
    int pre_l=wall[id].l,pre_r=wall[id].r;
    if((pre_l>=l||can_l)&&(pre_r<=r||can_r)){
        dp[who]=max(dp[who],min(dp[id],x[min(pre_r,r)+1]-x[max(pre_l,l)]));
    }
    if(l<pre_l) slove(l,pre_l-1,who,can_l,0);
    if(r>pre_r) slove(pre_r+1,r,who,0,can_r);
}
int main(){
    scanf("%d%d",&n,&t);
    for(int i=0;i<n;i++){
        int h,l,r;
        scanf("%d%d%d",&h,&l,&r);
        wall[i]=Wall(h,l,r);
        x[i*2]=l;x[i*2+1]=r;
    }
    x[n*2]=-inf;x[n*2+1]=inf;
    sort(x,x+2*n+2);
    cnt=unique(x,x+2*n+2)-x;
    wall[n++]=Wall(0,-inf,inf);
    wall[n++]=Wall(t,-inf,inf);
    sort(wall,wall+n);
    for(int i=0;i<n;i++){
        wall[i].l=lower_bound(x,x+cnt,wall[i].l)-x;
        wall[i].r=lower_bound(x,x+cnt,wall[i].r)-x-1;
    }
    Bulid(1,0,cnt-1);
    for(int i=0;i<n;i++){
        int l=wall[i].l,r=wall[i].r;
        slove(l,r,i,1,1);
        Update(1,l,r,i);
    }
    printf("%d\n",dp[n-1]);
    return 0;
}