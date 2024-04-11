#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define x0 fuck1
#define y0 fuck2
#define x1 fuck3
#define y1 fuck4
#define mp make_pair
#define pb push_back
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=5e5+5,mod=998244353;
int p[N],q[N],pos[N],n;
int mi[N<<2],ad[N<<2];
int gt(int p){return mi[p]+ad[p];}
void add(int p,int l,int r,int x,int y,int c){
    if(x<=l&&r<=y){ad[p]+=c;return;}

    ad[p<<1]+=ad[p],ad[p<<1|1]+=ad[p],mi[p]+=ad[p],ad[p]=0;

    int mid=(l+r)/2;
    if(x<=mid)add(p<<1,l,mid,x,y,c);
    if(mid+1<=y)add(p<<1|1,mid+1,r,x,y,c);

    mi[p]=min(gt(p<<1),gt(p<<1|1));
}
int que(int p,int l,int r,int x,int y){
    if(x>y||x<1)return 0;
    if(x<=l&&r<=y)return mi[p]+ad[p];
    ad[p<<1]+=ad[p],ad[p<<1|1]+=ad[p],mi[p]+=ad[p],ad[p]=0;
    //printf("c:%d %d %d\n",p,mi[p],ad[p]);

    int mid=(l+r)/2,s=mod;
    if(x<=mid)s=min(s,que(p<<1,l,mid,x,y));
    if(mid+1<=y)s=min(s,que(p<<1|1,mid+1,r,x,y));
    return s+ad[p];
}
int main(){
    scanf("%d",&n);
    rep(i,n)scanf("%d",p+i),pos[p[i]]=i;
    rep(i,n)scanf("%d",q+i);
    int ans=n;
    rep(i,n){
        //que(1,1,n,pos[ans]-1,pos[ans]-1)-min(0,que(1,1,n,1,pos[ans]-1))
        //+
        //printf("now:%d\n",que(1,1,n,1,1));
        while(que(1,1,n,n,n)-min(0,que(1,1,n,1,pos[ans]-1))<0){
            //printf("%d %d %d\n",ans,que(1,1,n,n,n),que(1,1,n,1,pos[ans]-1));
            add(1,1,n,pos[ans],n,1),--ans;
        }
        printf("%d%c",ans," \n"[i==n]);
        if(i==n)break;
        add(1,1,n,q[i],n,-1);
    }
    return 0;
}