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
ll mod=998244353;
//ll arr[1010101];

ll n,m;
//vector<pii> ans;
//ll inf=1e18;
ll day;
ll arr[2101010];
ll brr[2020200];
ll pre[2020200];
ll lin[2020200];
ll blpre[2020200];

vector<ll> v;
vector<ll> ed[2101010];
vector<ll> nds[2101010];
ll inh;

ll gin(ll x){
    ll a=x;
    ll b=mod-2;
    ll ret=1;
    //cout<<a<<' ';
    while(b){
        if(b%2) ret=ret*a%mod;
        a=a*a%mod;
        b=b/2;
        //cout<<a<<' '<<b<<' '<<ret<<'\n';
    }
   // cout<<ret<<'\n';
    return ret;
}

ll sol(ll a,ll b){
    ll val=(blpre[a]-blpre[b]+mod)%mod;
    val=(val*gin(lin[b]))%mod;
    return val;
}

int main(){
    ll i,j,k,l,a,b,c,d;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        cin>>arr[i];
    inh=gin(100);

    for(i=1;i<=n;i++){
        brr[i]=100*gin(arr[i])%mod;
        pre[i]=(pre[i-1]+brr[i])%mod;
    }
    lin[n+1]=1;
    for(i=n;i>=1;i--){
        lin[i]=lin[i+1]*brr[i]%mod;
    }
    for(i=n;i>=1;i--){
        blpre[i]=(blpre[i+1]+lin[i])%mod;
    }
    set<ll> s;
    s.insert(1);
    s.insert(n+1);
    ll ans=sol(1,n+1);

//    for(i=1;i<=n;i++)
//        cout<<i<<' '<<arr[i]<<' '<<brr[i]<<' '<<lin[i]<<' '<<blpre[i]<<'\n';

    while(m--){
        cin>>k;
        auto it = s.lower_bound(k);
        if(it==s.end()||*it != k){
            ll hi=*it;
            it--;
            ll lo=*it;
           // cout<<lo<<' '<<k<<' '<<hi<<'\n';
            s.insert(k);
            
            ans-=sol(lo,hi);
            ans+=mod;
            ans%=mod;
            ans+=sol(lo,k);
            ans%=mod;
            ans+=sol(k,hi);
            ans%=mod;                                                                 
        }
        else{
            it++;
            ll hi=*it;
            it--;
            it--;
            ll lo=*it;
            //cout<<lo<<' '<<k<<' '<<hi<<'\n';
            it++;
            s.erase(k);
            ans+=sol(lo,hi);
            ans%=mod;
            ans-=sol(lo,k);
            ans+=mod;
            ans%=mod;
            ans-=sol(k,hi);
            ans+=mod;
            ans%=mod;
        }
        cout<<ans<<'\n';
    }

}