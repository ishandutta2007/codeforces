#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
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
const int N=(1<<18)+1,mod=998244353;
int n,m,a[N];
set<int>S;
int x[N],y[N];
int t[N];
void add(int p,int x){
    for(;p<N;p+=p&-p)
        t[p]+=x;
}
int que(int p){
    int l=0,r=(1<<18);
    for(;l+1<r;){
        int mid=(l+r)/2;
        if(mid-l-t[mid]<p)p-=mid-l-t[mid],l=mid;else r=mid;
    }
    return r;
}
int is[N],pos[N];
int fra[N<<1],rev[N<<1];
int pw(int x,int y=mod-2){
    int s=1;
    for(;y;y>>=1,x=(ll)x*x%mod)
        if(y&1)s=(ll)s*x%mod;
    return s;
}
int T;
int main(){
    fra[0]=1;rep(i,N*2-1)fra[i]=(ll)fra[i-1]*i%mod;
    rev[N*2-1]=pw(fra[N*2-1]);
    for(int i=N*2-2;~i;--i)rev[i]=(ll)rev[i+1]*(i+1)%mod;
    for(scanf("%d",&T);T--;){
        scanf("%d%d",&n,&m);
        rep(i,m)scanf("%d%d",x+i,y+i);
        for(int i=m;i;--i){
            pos[i]=que(y[i]);
            //printf("%d %d\n",x[i],pos[i]);
            is[pos[i]]=x[i];
            add(pos[i],1);
        }
        int cnt=0;
        rep(i,m)
            if(pos[i]<n&&(is[pos[i]+1]<is[pos[i]]))++cnt;
        cnt=n-1-cnt;
        //C(n,n)
        int ans=(ll)fra[n+cnt]*rev[n]%mod*rev[cnt]%mod;
        printf("%d\n",ans);
        rep(i,m)is[pos[i]]=0,add(pos[i],-1),pos[i]=0;
    }
    return 0;
}
/*
3
3 2
2 1
3 1
*/