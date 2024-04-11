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
typedef pair<ll,ll> pii;
typedef vector<int> vi;
const int N=5e5+5,mod=1e9+7;
int T,n,a[N];
int fra[N],rev[N];
int pw(int x,int y=mod-2){
    int s=1;
    for(;y;y>>=1,x=(ll)x*x%mod)
        if(y&1)s=(ll)s*x%mod;
    return s;
}
int C(int n,int m){
    if(m<0||n<m)return 0;
    return (ll)fra[n]*rev[m]%mod*rev[n-m]%mod;
}
int main(){
    fra[0]=1;rep(i,N-1)fra[i]=(ll)fra[i-1]*i%mod;
    rev[N-1]=pw(fra[N-1]);for(int i=N-2;~i;--i)rev[i]=(ll)rev[i+1]*(i+1)%mod;
    for(T=1;T--;){
        scanf("%d",&n);
        for(int i=0;i<=n;++i)scanf("%d",a+i);
        if(a[0]==0){
            puts("0");
            continue;
        }
        while(a[n]==0)--n;
        ++n;a[n]=0;
        int ans=0;
        for(int i=0;i<=n;++i){
            if(a[i]!=0){
                ans=(ans+(ll)C(i+a[i]-1,i))%mod;
                //printf("%lld\n",(ll)C(i+a[i]-1,i));
            }
            if(i>0){
                for(int j=a[i-1]-1;j>=a[i];--j){
                    ans=(ans+(ll)C(i+j-1,i-1))%mod;
                    //printf("%lld\n",(ll)C(i+j-1,i-1));
                }
            }
        }
        ans=(ans-1+mod)%mod;
        printf("%d\n",ans);
    }
    return 0;
}
/*
5
5
2 1 5 3 4
*/