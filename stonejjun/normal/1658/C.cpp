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

struct poi{
    ll u,a,b;
};

vector<poi> v[1101010];
vector<ll> x;
ll arr[1010101];
ll ans=0;
ll n,m;
ll mod=998244353;
ll vis[1010101];
ll val[1010101];
ll mul[1010101];
ll pmul[1010101];
ll fin[1010101];
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t,T;
    cin>>t;

    while(t--){

        ll i,j,k,l;
        cin>>n;
        ll chk=1;
        for(i=0;i<n;i++){
            cin>>arr[i];
        }
        ll cnt1=0;
        ll x1=0;
        for(i=0;i<n;i++){
            if(arr[i]==1){
                cnt1++;
                x1=i;
            }
        }
        if(cnt1!=1){
            cout<<"NO"<<'\n';
            continue;
        }

        for(i=x1;i<x1+n;i++){
            ll j=i%n;
            if(arr[(j+1)%n]>arr[j]+1){
                chk=0;
            }
        }

        if(chk){
            cout<<"YES"<<'\n';
        }
        else{
            cout<<"NO"<<'\n';
            
        }

    }


    
    
}