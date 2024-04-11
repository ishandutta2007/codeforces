#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x0 gtmsub
#define y0 gtmshb
#define x1 gtmjtjl
#define y1 gtmsf
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=3e6+5;
int n;
ll a[N],b[N],c[N],d[N],e[N];
set<ll>st,sd;
ll gt(ll inc,ll mod){
    ll x=a[inc];
    if(x<mod)return c[inc]*(mod-x);
    return c[inc]*min(x%mod,mod-x%mod);
}
int main(){
    srand(time(0));

    scanf("%d",&n);
    //n=2e5;
    rep(i,n){
        scanf("%lld",a+i);
        //a[i]=((ll)1e12)-i;
    }
    sort(a+1,a+n+1);
    ll top=0;
    rep(i,n)if(top==0||a[top]!=a[i])a[++top]=a[i],c[top]=1;else ++c[top];
    n=top;
    ll ans=0;
    rep(i,n)ans+=gt(i,2);
    ll l=max(1ll,a[1]-ans),r=a[1]+ans,len=r-l+1;
    b[1]=l;
    rep(i,len-1)b[i+1]=b[i]+1;
    for(int i=2;i<=1100000;++i){
        bool flag=0;
        for(ll j=r/i*i-l+1;j>=1;j-=i){
            while(b[j]%i==0)b[j]/=i,flag=1;
        }
        if(flag)st.insert(i);
    }
    rep(i,len)if(b[i]>1)st.insert(b[i]);
    rep(i,n)d[i]=i;
    random_shuffle(d+1,d+n+1);
    rep(i,n)e[d[i]]=a[i];rep(i,n)a[i]=e[i];
    rep(i,n)e[d[i]]=c[i];rep(i,n)c[i]=e[i];
    for(ll mod:st){
        ll now=0;
        rep(i,n){
            now+=gt(i,mod);
            //printf("%lld\n",a[i]);
            if(now>=ans)break;
        }
        //printf("%lld:%lld\n",mod,now);
        ans=min(ans,now);
    }
    printf("%lld\n",ans);
}