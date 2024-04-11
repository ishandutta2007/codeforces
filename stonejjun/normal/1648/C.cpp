#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double dl;
typedef pair<dl,dl> pdi;
typedef pair<ll,ll> pii;
 
#define ff first
#define ss second
#define ep emplace_back
#define eb emplace
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
//cout<<fixed;
//cout.precision(12);
vector<ll> v[101010];
vector<ll> x;
ll cnt[1010101];
ll arr[1010101];
ll pre[1010101];

ll brr[1010101];
ll lcnt[1010101];
ll ans=0;
ll n,m;
ll tree[2010101];
ll fac[1010101];
ll mod=998244353;

void upt(ll idx,ll val,ll s,ll e,ll nod){
    if(idx<s||idx>e) return ;
    tree[nod]+=val;
    if(s==e) return;
    upt(idx,val,s,(s+e)/2,nod*2);
    upt(idx,val,(s+e)/2+1,e,nod*2+1);
}

ll sol(ll l,ll r,ll s,ll e,ll nod){
  //  cout<<l<<' '<<r<<' '<<s<<' '<<e<<' '<<nod<<' '<<tree[nod]<<'\n';
    if(r<s||e<l) return 0;
    if(l<=s&&e<=r) return tree[nod];
    return sol(l,r,s,(s+e)/2,nod*2)+sol(l,r,(s+e)/2+1,e,nod*2+1);
}

ll lsp(ll a,ll b,ll mod){
    ll ret=1;
    while(b){
        if(b%2) ret=ret*a%mod;
        a=a*a%mod;
        b/=2;
    }
    return ret;
}

ll gin(ll x){
    return lsp(x,mod-2,mod);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t,T;
    ll i,j,k,l;
    ll a,b,c;
    cin>>n>>m;

    fac[0]=1;
    fac[1]=1;
    for(i=2;i<=202020;i++)
        fac[i]=(fac[i-1]*i)%mod;

    for(i=1;i<=n;i++){
        cin>>arr[i];
        cnt[arr[i]]++;
    }
    for(i=1;i<=m;i++)
        cin>>brr[i];

    ll val=fac[n];
    ll x=200000;
    for(i=1;i<=x;i++){
        val=val*gin(fac[cnt[i]])%mod;
       // if(cnt[i]) cout<<i<<' '<<cnt[i]<<'\n';
        upt(i,cnt[i],1,x,1);
    }
    ll ans=0;
    for(i=1;i<=min(n,m);i++){
        //cout<<i<<' '<<val<<' '<<ans<<'\n';
        ll p=val;
        //cout<<p<<'\n';
        if(i==n&&n<m) p=p*sol(1,brr[i],1,x,1)%mod;
        else p=p*sol(1,brr[i]-1,1,x,1)%mod;
        //cout<<p<<'\n';
        p=p*gin(n+1-i)%mod;
        //cout<<p<<'\n';
        ans=(ans+p)%mod;

        val=val*gin(n+1-i)%mod;
        val=val*sol(brr[i],brr[i],1,x,1)%mod;
        //cout<<val<<'\n';
        upt(brr[i],-1,1,x,1);
    }


    cout<<ans%mod;
    
    
}