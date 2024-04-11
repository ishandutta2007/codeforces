#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define trav(a,x) for(auto&a:x)
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define x0 fuckhel
#define y0 fuckoscar
#define x1 fucksub
#define y1 fuckzzy
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
typedef vector<int> vi;
const int N=1e6+5,mod=1e9+7;
int n,q;
ll a[N],S[N];
struct node{
    ll sum;
    ll mil,mir,miin;
    ll mal,mar,mainx;
    node operator+(node p){
        node ret;
        ret.sum=sum+p.sum;
    
        ret.mil=min(mil,sum+p.mil);
        ret.mir=min(mir+p.sum,p.mir);
        ret.miin=min(mir+p.mil,min(miin,p.miin));
    
        ret.mal=max(mal,sum+p.mal);
        ret.mar=max(mar+p.sum,p.mar);
        ret.mainx=max(mar+p.mal,max(mainx,p.mainx));
        return ret;
    }
}t[N];
void build(int p,int l,int r){
    if(l==r){
        t[p].sum=a[l];
        
        t[p].mil=min(0ll,a[l]);
        t[p].mir=min(0ll,a[l]);
        t[p].miin=min(0ll,a[l]);

        t[p].mal=max(0ll,a[l]);
        t[p].mar=max(0ll,a[l]);
        t[p].mainx=max(0ll,a[l]);
        return;
    }
    int mid=(l+r)/2;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    t[p]=t[p<<1]+t[p<<1|1];
}
node que(int p,int l,int r,int x,int y){
    if(x<=l&&r<=y)return t[p];
    node ret=(node){0ll,0ll,0ll,0ll,0ll,0ll,0ll};
    int mid=(l+r)/2;
    if(x<=mid)ret=ret+que(p<<1,l,mid,x,y);
    if(mid+1<=y)ret=ret+que(p<<1|1,mid+1,r,x,y);
    return ret;
}
int main(){
    scanf("%d%d",&n,&q);
    rep(i,n){
        int x;scanf("%d",&x);
        a[i]-=x;
    }
    rep(i,n){
        int x;scanf("%d",&x);
        a[i]+=x;
    }
    rep(i,n)S[i]=S[i-1]+a[i];
    build(1,1,n);
    rep(i,q){
        int l,r;scanf("%d%d",&l,&r);
        node ret=que(1,1,n,l,r);
        if(ret.sum!=0||ret.mil<0){
            puts("-1");continue;
        }
        printf("%lld\n",max(ret.mainx,-ret.miin));
    }
    return 0;
}
/*
7 6
1 6 4 2 3 5 4

*/