#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define per(i,j,k) for(int i=j;i>=k;i--)
#define lowbit(x) ((x)&(-(x)))
#define MAXN 110000
#define jsb 1000000007
using namespace std;
int n,m;int a[MAXN];int gfs[MAXN][6];int LL;
int L[MAXN*4],R[MAXN*4];
inline void A(int &x,int y){x+=y;x%=jsb;}
inline int Pow(int x,int y){
    int c=1;rep(i,1,y)c=c*1ll*x%jsb;
    return c;
}
struct Info{
       int c[6];
       inline Info operator +(const Info &b)const{
              Info p;rep(i,0,5)p.c[i]=c[i];
              rep(j,0,5)
              A(p.c[j],b.c[j]);
              return p;
              }
       inline void Make(int x,int y){
              c[0]=1;
              rep(j,1,5)
              c[j]=c[j-1]*1ll*y%jsb;
              rep(j,0,5)c[j]=c[j]*1ll*x%jsb;
              }
       inline void MakerQ(int l,int r,int v){
              int u=v;
              rep(j,0,5)c[j]=u*1ll*(gfs[r][j]-gfs[l-1][j])%jsb;
              }
       inline int calc(int k){
              if(k==0)return c[0];
              if(k==1)return (c[1]-c[0]*1ll*LL%jsb)%jsb;
              if(k==2){
                       int u=0;
                       A(u,c[2]);
                       A(u,(-2ll*c[1]%jsb)*1ll*LL%jsb);
                       A(u,c[0]*1ll*Pow(LL,2)%jsb);
                       return u;
                       }
              if(k==3){
                       int u=0;
                       int bi[6];rep(i,0,5)bi[i]=Pow(LL,i);
                       A(u,c[3]);
                       A(u,-3ll*c[2]%jsb*bi[1]%jsb);
                       A(u,3ll*c[1]%jsb*bi[2]%jsb);
                       A(u,-c[0]*1ll*bi[3]%jsb);
                       return u;
                       }
              if(k==4){
                       int u=0;
                       int bi[6];rep(i,0,5)bi[i]=Pow(LL,i);
                       A(u,c[4]);
                       A(u,-4ll*c[3]%jsb*bi[1]%jsb);
                       A(u,6ll*c[2]%jsb*bi[2]%jsb);
                       A(u,-4ll*c[1]%jsb*bi[3]%jsb);
                       A(u,c[0]*1ll*bi[4]%jsb);
                       return u;
                       }
              if(k==5){
                       int u=0;
                       int bi[6];rep(i,0,5)bi[i]=Pow(LL,i);
                       A(u,c[5]);
                       A(u,-5ll*c[4]%jsb*bi[1]%jsb);
                       A(u,10ll*c[3]%jsb*bi[2]%jsb);
                       A(u,-10ll*c[2]%jsb*bi[3]%jsb);
                       A(u,5ll*c[1]*1ll*bi[4]%jsb);
                       A(u,-c[0]*1ll*bi[5]%jsb);
                       return u;
                       }
              }
}info[MAXN*4];int tag[MAXN*4];
inline void down(int now){
       if(tag[now]==-1)return;
       tag[2*now]=tag[2*now+1]=tag[now];
       info[2*now].MakerQ(L[2*now],R[2*now],tag[2*now]);
       info[2*now+1].MakerQ(L[2*now+1],R[2*now+1],tag[2*now+1]);
       tag[now]=-1;
}      
void build(int now,int l,int r){
     L[now]=l;R[now]=r;
     if(l==r){
              info[now].Make(a[l],l+1);
              return;
              }
     int mid=(l+r)>>1;
     build(now*2,l,mid);
     build(now*2+1,mid+1,r);
     info[now]=info[now*2]+info[now*2+1];
}
Info ask(int now,int l,int r,int x,int y){
     if(l!=r)down(now);
     if(x<=l&&r<=y)return info[now];
     int mid=(l+r)>>1;
     Info res;memset(res.c,0,sizeof res.c);
     if(x<=mid)res=res+ask(now*2,l,mid,x,y);
     if(y>mid)res=res+ask(now*2+1,mid+1,r,x,y);
     return res;
}
void change(int now,int l,int r,int x,int y,int v){
     if(l!=r)
     down(now);
     if(x<=l&&r<=y){
                    tag[now]=v;
                    info[now].MakerQ(l,r,v);
                    return;
                    }
     int mid=(l+r)>>1;
     if(x<=mid)change(now*2,l,mid,x,y,v);
     if(y>mid)change(now*2+1,mid+1,r,x,y,v);
     info[now]=info[now*2]+info[now*2+1];
}
int main(){
    memset(tag,-1,sizeof tag);
    scanf("%d%d",&n,&m);rep(i,1,n)scanf("%d",&a[i]);build(1,1,n);
    rep(i,1,n)rep(j,0,5)A(gfs[i][j],(gfs[i-1][j]+Pow(i+1,j))%jsb);
    rep(i,1,m){
               char opt[3];int l,r,k;scanf("%s",opt+1);
               scanf("%d%d%d",&l,&r,&k);LL=l;
               if(opt[1]=='=')change(1,1,n,l,r,k);
               else printf("%d\n",(ask(1,1,n,l,r).calc(k)+jsb)%jsb);
               }
    return 0;
}