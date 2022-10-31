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
vector<ll> v[10101];
ll n;
vector<pii> ans;

bool sf(ll a,ll b){
    if(arr[a]==arr[b]) return a<b;
    return arr[a]<arr[b];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t,T;
    ll i,j,k,l,m;
    ll chk=0,cnt=0,val;
    ll a=0,b=0,c=0,d=0;
    ll e,f,g,h;
    ll cnta=0,cntb=0;
    ll lawin=0;
    
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>arr[i];
        for(j=1;j<i;j++){
            if(arr[j]>arr[i]){
                v[i].pb(j);
            }
        }
    }

    for(i=n;i>=1;i--){
        sort(v[i].begin(), v[i].end(),sf);
        for(auto k:v[i]){
            ans.pb({k,i});
         //   swap(arr[k],arr[i]);
        }
    }
    cout<<ans.size()<<'\n';
    for(auto k:ans){
        cout<<k.ff<<' '<<k.ss<<'\n';
    }

   
}