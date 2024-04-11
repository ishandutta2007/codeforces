#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=210000;
char a[N];int n,Q;
int t[15];
struct data{
    int w[5][5];
    void init(){rep(i,0,4)rep(j,0,4)w[i][j]=10000000;}
    void build(int x){
        init();
        rep(i,0,4){
            if(i>=3&&x==6){
                w[i][i]=1;
                continue;
            }
            if(i<4&&x==t[i])w[i][i+1]=0;
            w[i][i]=(x==t[i]);
        }
    }
}mes[N<<2];
inline data operator +(const data &a,const data &b){
    data c;
    c.init();
    rep(i,0,4)rep(k,i,4)rep(j,max(i,k),4)c.w[i][j]=min(c.w[i][j],a.w[i][k]+b.w[k][j]);
    return c;
}
int f[5];
int g[5];
void ask(int me,int l,int r,int x,int y){
    if(x<=l&&r<=y){
        rep(i,0,4)g[i]=10000000;
        rep(j,0,4)rep(k,j,4)g[k]=min(g[k],f[j]+mes[me].w[j][k]);
        rep(i,0,4)f[i]=g[i];
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid)ask(me<<1,l,mid,x,y);
    if(y>mid)ask(me<<1|1,mid+1,r,x,y);
}
void build(int me,int l,int r){
    if(l==r){
        mes[me].build(a[l]);
        return;
    }
    int mid=(l+r)>>1;
    build(me<<1,l,mid);
    build(me<<1|1,mid+1,r);
    mes[me]=mes[me<<1]+mes[me<<1|1];
}
int main(){
    t[0]=2;
    t[1]=0;
    t[2]=1;
    t[3]=7;
    t[4]=-1;
    scanf("%d%d",&n,&Q);
    scanf("%s",a+1);
    rep(i,1,n)a[i]-='0';
    build(1,1,n);
    while(Q--){
        int l,r;scanf("%d%d",&l,&r);
        rep(i,0,4)f[i]=10000000;
        f[0]=0;
        ask(1,1,n,l,r);
        if(f[4]>n+5)printf("-1\n");
        else printf("%d\n",f[4]);
    }
    return 0;
}