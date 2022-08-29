#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define res(i,n) for(int i=0;i<n;++i)
#define eb emplace_back
#define mp make_pair
#define x0 fuckcjb
#define y0 fuckcxb
#define x1 fuckxjb
#define y1 fuckcjx
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=3e6+5,mod=1e9+7;
const ld eps=1e-9,inf=1e50;
int n,q;ll a[N],b[N];
void cge(int p,int l,int r,int pos,int num){
    //printf("UL%d %lld\n",p,b[p]);
    if(l==r){if(a[l]<b[p])a[l]=b[p];b[p]=0;a[l]=num;return;}
    if(b[p<<1|1]<b[p])b[p<<1|1]=b[p];
    if(b[p<<1]<b[p])b[p<<1]=b[p];
    b[p]=0;
    int mid=l+r>>1;
    if(pos<=mid)cge(p<<1,l,mid,pos,num);
    else cge(p<<1|1,mid+1,r,pos,num);
}
void pri(int p,int l,int r){
    //printf("%d %lld\n",p,b[p]);
    if(l==r){if(a[l]<b[p])a[l]=b[p];b[p]=0;
        printf("%lld%c",a[l]," \n"[l==n]);
        return;}
    if(b[p<<1|1]<b[p])b[p<<1|1]=b[p];
    if(b[p<<1]<b[p])b[p<<1]=b[p];
    b[p]=0;
    int mid=l+r>>1;
    pri(p<<1,l,mid);pri(p<<1|1,mid+1,r);
}
int main(){
    scanf("%d",&n);
    rep(i,n){
        int x;
        scanf("%d",&x);
        cge(1,1,n,i,x);
    }
    scanf("%d",&q);
    rep(cc,q){
        int typ;scanf("%d",&typ);
        if(typ==1){
            int pp,xx;scanf("%d%d",&pp,&xx);
            cge(1,1,n,pp,xx);
        }else{
            int x;scanf("%d",&x);
            if(b[1]<x)b[1]=x;
        }
    }
    pri(1,1,n);
    return 0;
}