#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
ll mod=1000000007;
ll qwe[1010101];
ll arr[1010101];
ll prein[20][20];

ll n;

ll lsp(ll a,ll b){
    ll ret=1;
    while(b){
        if(b%2) ret=ret*a%mod;
        a=a*a%mod;
        b/=2;
    }
    return ret%mod;
}

ll getinv(ll a){
    return lsp(a,mod-2);
}

void sol(ll mask){
    ll i,j,k;
    qwe[mask]=1;
    vector<ll> v;
    for(j=0;j<n;j++){
        if(mask&(1<<j)) v.pb(j);
    }

    for (ll x = mask;x;x = (x-1)&mask){
        if(x==mask) continue;
       // cout<<"bima"<<x<<' '<<mask<<'\n';
        ll val=qwe[x];

        ll cnt1=0,cnt0=0;
        ll arr1[20]={0,};
        ll arr0[20]={0,};
        for(auto j:v){
            if(x&(1<<j)){
                cnt1++;
                arr1[cnt1]=j;
            }
            else {
                cnt0++;
                arr0[cnt0]=j;
            }
        }
        //cout<<cnt1<<cnt0<<'\n';
        for(i=1;i<=cnt1;i++)
            for(j=1;j<=cnt0;j++){
                ll k1=arr1[i];
                ll k0=arr0[j];

                //cout<<"kiko"<<k1<<' '<<k0<<'\n';
                val=val*arr[k1]%mod;
                val=val*prein[k1][k0]%mod;
            }

            
       // cout<<"val"<<val<<'\n';
        qwe[mask]=(qwe[mask]-val+mod)%mod;
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t,T;
    ll i,j,k,l,m;
    ll chk=0,cnt=0,ans=0,val;
    ll a=0,b=0,c=0,d=0;
    ll e,f,g,h;
    ll cnta=0,cntb=0;
    ll lawin=0;
    
    cin>>n;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            prein[i][j]=getinv(arr[i]+arr[j]);
        }
    }

    for(i=1;i<(1<<n);i++){
        ll x=i;
        ll ct=__builtin_popcountll(x);
        sol(x);
       // cout<<"qwe"<<i<<' '<<qwe[i]<<'\n';
        ll val=qwe[x];
        vector<ll> v1;
        vector<ll> v0;
        for(j=0;j<n;j++){
            //cout<<"bit"<<mask<<' '<<(1<<j)<<'\n';
            if(x&(1<<j)) v1.pb(j);
            else v0.pb(j);
        }
       // cout<<v1.size()<<v0.size()<<'\n';
        for(auto k1:v1)
            for(auto k0:v0){
              //  cout<<"kiko"<<k1<<' '<<k0<<'\n';
                val=val*arr[k1]%mod;
                val=val*prein[k1][k0]%mod;
            }
        val=val*ct%mod;
        ans=(ans+val+mod)%mod;
    }

    cout<<ans;
   
}