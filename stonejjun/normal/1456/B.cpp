#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double dl;
typedef pair<dl,dl> pdi;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> piii;
 
#define ff first
#define ss second
#define eb emplace_back
#define ep emplace
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define IDX(v, x) lower_bound(all(v), x) - v.begin()
//cout<<fixed;
//cout.precision(12);
 
struct poi{
    ll val,xx,yy;
};
 
vector<ll> x;
ll n,m;
ll mod=998244353;
string s;
string t;
ll arr[1010101];
ll brr[1010101];
 
vector<ll> v[1010101];
 
ll gmsb(ll x){
    ll ret=0;
    for(ll i=0;i<=30;i++){
        if(x&(1LL<<i)) ret=i;
    }
    return ret;
}

ll pre[1010101];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j,k,a,b,c;
    cin>>n;
    ll ans=1e18;
 
    for(i=1;i<=n;i++){
        cin>>arr[i];
        pre[i]=pre[i-1]^arr[i];
    }
    
    for(i=1;i<n-2;i++){
        if((arr[i]^arr[i+1])>arr[i+2]){
            cout<<1;
            return 0;
        }
        if(arr[i]>(arr[i+1]^arr[i+2])){
            cout<<1;
            return 0;
        }
    }
    for(i=1;i<n-3;i++){
        if((arr[i]^arr[i+1]^arr[i+2])>arr[i+3]){
            cout<<2;
            return 0;
        }
        if((arr[i]^arr[i+1])>(arr[i+2]^arr[i+3])){
            cout<<2;
            return 0;
        }
        if(arr[i]>(arr[i+1]^arr[i+2]^arr[i+3])){
            cout<<2;
            return 0;
        }
    }

    for(i=1;i<=n;i++){
        for(j=i+1;j<=n;j++){
            for(k=i;k<j;k++){
                //cout<<i<<' '<<j<<' '<<k<<' '<<(pre[k]^pre[i-1])<<' '<<(pre[j]^pre[k])<<'\n';
                if((pre[k]^pre[i-1])>(pre[j]^pre[k])){
                    //cout<<"qwerqwer";
                    ans=min(ans,j-1-i);
                }
            }
        }
    }
    if(ans>1e9){
    cout<<"-1";
    return 0;
}
cout<<ans;
    
}