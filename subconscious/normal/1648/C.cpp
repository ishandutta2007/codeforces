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
const int N=2e5+5,mod=998244353;
int n,m,a[N],b[N];
int fra[N],rev[N];
int pw(int x,int y=mod-2){
    int s=1;
    for(;y;y>>=1,x=(ll)x*x%mod)
        if(y&1)s=(ll)s*x%mod;
    return s;
}
void add(int x,int num){
    for(;x<N;x+=x&-x)a[x]+=num;
}
int que(int x){
    int s=0;
    for(;x;x-=x&-x)s+=a[x];
    return s;
}
int main(){
    scanf("%d%d",&n,&m);
    fra[0]=1;rep(i,N-1)fra[i]=(ll)fra[i-1]*i%mod;
    rev[N-1]=pw(fra[N-1]);for(int i=N-2;~i;--i)rev[i]=(ll)rev[i+1]*(i+1)%mod;
    rep(i,n){
        int x;scanf("%d",&x);
        add(x,1);
    }
    rep(i,m)scanf("%d",b+i);
    int ans=0,now;
    now=fra[n];
    rep(i,N-1)now=(ll)now*rev[que(i)-que(i-1)]%mod;
    rep(i,m){
        if(i>n){
            ans=(ans+now)%mod;
            break;
        }
        int r=(ll)rev[n-i+1]*fra[n-i]%mod;
        ans=(ans+(ll)que(b[i]-1)*r%mod*now)%mod;
        if(que(b[i])-que(b[i]-1)==0)break;
        now=(ll)now*r%mod*(que(b[i])-que(b[i]-1))%mod;
        add(b[i],-1);
    }
    printf("%d\n",ans);
    return 0;
}
/*
*/