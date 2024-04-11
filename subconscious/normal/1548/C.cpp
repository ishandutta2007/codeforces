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
const int N=3e6+5,mod=1e9+7;
int n,q,ans[N],a[3];
vector<int>to[N];
int fra[N],rev[N];
int C(int n,int m){return (ll)fra[n]*rev[m]%mod*rev[n-m]%mod;}
int pw(int x,int y=mod-2){
    int s=1;
    for(;y;y>>=1,x=(ll)x*x%mod)
        if(y&1)s=(ll)s*x%mod;
    return s;
}
int main(){
    fra[0]=1;rep(i,N-1)fra[i]=(ll)fra[i-1]*i%mod;
    rev[N-1]=pw(fra[N-1]);for(int i=N-2;~i;--i)rev[i]=(ll)rev[i+1]*(i+1)%mod;
    scanf("%d%d",&n,&q);
    rep(i,q){
        int x;scanf("%d",&x);
        to[x].pb(i);
    }
    a[0]=a[1]=a[2]=n;
    int r3=pw(3);
    rep(i,3*n){
        //int cst=(C(3*n,i)+C(3*n,i-1))%mod;
        int n2=((ll)C(3*n+1,i+1)-a[2]*2-a[1]+3ll*mod)%mod*r3%mod;
        int n1=(n2+a[2])%mod;
        int n0=(n1+a[1])%mod;
        a[0]=n0,a[1]=n1,a[2]=n2;
        for(int v:to[i])
            ans[v]=a[0];
    }
    rep(i,q)printf("%d\n",ans[i]);
    return 0;
}
/*

*/